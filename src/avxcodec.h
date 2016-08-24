#ifndef DICT_AVX_H
#define DICT_AVX_H

/**
* This is silly compression/decompression code. Meant to test the basics, not
* for production.
*/
#include <cassert>
#include <cstdint>
#include <cstddef>
#include <unordered_map>

#ifndef __AVX2__
#error This code requires AVX2 support (available on Intel processors made since ~2013)
#endif

#ifdef _MSC_VER
/* Microsoft C/C++-compatible compiler */
#include <intrin.h>
#else
/* Pretty much anything else. */
#include <x86intrin.h>
#endif

#include "avxbpacking.h"
#include "avxdict.h"
#include "dict.h"


/**
* This class is *not* thread-safe, use one instance per thread.
*/
class AVXDictCODEC {
public:

    AVXDictCODEC() : tmpbuffer(NULL), buffercapacity(0) {}

    virtual ~AVXDictCODEC() {
        clearBuffer();
    }
    /**
    * Silly code that compresses an array of 64-bit integers to an array of char,
    * outputting a convenient data structure.
    *
    * This could be *greatly* optimized.
    *
    * For simplicity, array lengths are assumed to be multiples of 256.
    */
    inline dictionary_coded_t compress(const uint64_t * array, size_t length) {
        dictionary_coded_t out;
        out.array_length = length;
        ensureBufferCapacity(out.array_length);
        std::unordered_map<uint64_t,uint32_t> distinctvalues;
        out.dictionary_size = 0;
        for(size_t i = 0; i < out.array_length; ++i) {
            if(distinctvalues.find(array[i]) == distinctvalues.end()) {
                distinctvalues.emplace(array[i],out.dictionary_size++);
                assert(out.dictionary_size != 0); // should never happen unless dictionary gets humongous
            }
        }
        out.dictionary = new uint64_t[out.dictionary_size];
        for(auto i = distinctvalues.begin(); i != distinctvalues.end(); ++i)  out.dictionary[i->second] = i->first;
        for(size_t i = 0; i < out.array_length ; ++i) {
            tmpbuffer[i] = distinctvalues[array[i]];
        }
        assert(length % 256 == 0);
        out.bit_width = 32 - __builtin_clz(out.dictionary_size);
        out.compressed_data_size = sizeof(uint32_t) * out.bit_width * length / 32;
        assert(out.array_length * out.bit_width ==  out.compressed_data_size * 8);
        out.compressed_data = new char[out.compressed_data_size];
        avxpackwithoutmask(tmpbuffer,(__m256i *) out.compressed_data, out.array_length, out.bit_width);
        return out;
    }



    /**
    * Silly code that uncompresses an array of 64-bit integers.
    * The out array should have enough space.
    *
    * This could be optimized.
    *
    * For simplicity, array lengths are assumed to be multiples of 256.
    *
    * Return array size
    */
    inline uint32_t uncompress(const dictionary_coded_t & t, uint64_t * out) {
        ensureBufferCapacity(t.array_length);
        assert(t.array_length % 256 == 0);
        assert(t.array_length * t.bit_width ==  t.compressed_data_size * 8);
        avxunpack((const __m256i*) t.compressed_data, tmpbuffer, t.array_length, t.bit_width);
        for(size_t i = 0; i < t.array_length; ++i) {
            out[i] = t.dictionary[tmpbuffer[i]];
        }
        return t.array_length;
    }

    /**
    * Prototype code that uncompresses an array of 64-bit integers.
    * The out array should have enough space.
    *
    * If the size of the compressed data does not fit in fast CPU cache,
    * consider using fastrangeuncompress instead, to decompress data to fast CPU cache
    * in blocks. Pushing data back and forth from RAM can be slow.
    *
    * For simplicity, array lengths are assumed to be multiples of 256.
    *
    * Return array size
    */
    static inline uint32_t fastuncompress(const dictionary_coded_t & t, uint64_t * out) {
        assert(t.array_length % 256 == 0);
        assert(t.array_length * t.bit_width ==  t.compressed_data_size * 8);
        avxunpackdict((const __m256i*) t.compressed_data,
                      (const myint64 *) t.dictionary,(int64_t *)  out, t.array_length, t.bit_width);
        return t.array_length;
    }

    /**
    * Uncompresses size values from index start
    * This can be used to uncompress data to cache.
    *
    * For simplicity, all indexes and lengths are are assumed to be multiples of 256.
    * Return the number of remain values left to be decoded (starting at index start+length)
    */
    static inline uint32_t fastrangeuncompress(const dictionary_coded_t & t, uint64_t * out, size_t start, size_t length) {
        assert(t.array_length % 256 == 0);
        assert(start % 256 == 0);
        assert(length % 256 == 0);
        assert(t.array_length * t.bit_width ==  t.compressed_data_size * 8);
        assert(start + length <= t.array_length);
        avxunpackdict((const __m256i*) ( t.compressed_data + start * t.bit_width / 8),
                      (const myint64 *) t.dictionary,(int64_t *)  out, length, t.bit_width);
        return t.array_length - start - length;
    }


    inline void clearBuffer() {
        buffercapacity = 0;
        delete[] tmpbuffer;
        tmpbuffer = NULL;
    }

private:

    // by design, does not copy
    AVXDictCODEC(const AVXDictCODEC & ) : tmpbuffer(NULL), buffercapacity(0) {}


    AVXDictCODEC& operator=(const AVXDictCODEC & ) {
        // does nothing, by design
        return *this;
    }


    inline void ensureBufferCapacity(size_t desiredcap) {
        if(desiredcap > buffercapacity) {
            delete[] tmpbuffer;
            tmpbuffer = new uint32_t[desiredcap];
            assert(tmpbuffer!= NULL);
            buffercapacity = desiredcap;
        }
    }
    uint32_t * tmpbuffer;
    size_t buffercapacity;
};


#endif
