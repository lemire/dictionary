#ifndef DICT_SCALAR_H
#define DICT_SCALAR_H

/**
* This is silly compression/decompression code. Meant to test the basics, not
* for production.
*/
#include <cassert>
#include <cstdint>
#include <cstddef>
#include <unordered_map>
#include "bpacking.h"
#include "dict.h"


/**
* This class is *not* thread-safe, use one instance per thread.
*/
class SimpleDictCODEC {
public:
    SimpleDictCODEC() : tmpbuffer(NULL), buffercapacity(0) {}

    virtual ~SimpleDictCODEC() {
        clearBuffer();
    }

    /**
    * Silly code that compresses an array of 64-bit integers to an array of char,
    * outputting a convenient data structure.
    *
    * This could be *greatly* optimized.
    *
    * For simplicity, array lengths are assumed to be multiples of 32.
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
        assert(length % 32 == 0);
        out.bit_width = 32 - __builtin_clz(out.dictionary_size);
        out.compressed_data_size = sizeof(uint32_t) * out.bit_width * length / 32;
        out.compressed_data = new char[out.compressed_data_size];
        packwithoutmask32(tmpbuffer,(uint32_t *) out.compressed_data, out.array_length, out.bit_width);
        return out;
    }



    /**
    * Silly code that uncompresses an array of 64-bit integers.
    * The out array should have enough space.
    *
    * This could be optimized.
    *
    * For simplicity, array lengths are assumed to be multiples of 32.
    *
    * Return array size
    */
    inline uint32_t uncompress(const dictionary_coded_t & t, uint64_t * out) {
        ensureBufferCapacity(t.array_length);
        assert(t.array_length % 32 == 0);
        unpack32((const uint32_t*) t.compressed_data, tmpbuffer, t.array_length, t.bit_width);
        for(size_t i = 0; i < t.array_length; ++i) {
            out[i] = t.dictionary[tmpbuffer[i]];
        }
        return t.array_length;
    }



    inline void clearBuffer() {
        buffercapacity = 0;
        delete[] tmpbuffer;
        tmpbuffer = NULL;
    }

private:


    // by design, does not copy
    SimpleDictCODEC(const SimpleDictCODEC & ) : tmpbuffer(NULL), buffercapacity(0) {}


    SimpleDictCODEC& operator=(const SimpleDictCODEC & ) {
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
