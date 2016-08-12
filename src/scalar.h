/**
* This is silly compression/decompression code. Meant to test the basics, not
* for production.
*/

#include <stdint>
#include <unordered_map>
#include "bpacking.h"

typedef struct dictionary_coded_s {
    int64_t * dictionary;
    uint32_t dictionary_size;

    char *compressed_data;
    size_t array_length;// uncompressed length in 64-bit words
    int bit_width;
} dictionary_coded_t;

dictionary_coded_delete(dictionary_coded_t * t) {
    delete[] t->dictionary;
    t->dictionary = NULL;
    delete[] compressed_data;
    t->compressed_data = NULL;
    t->dictionary_size = 0;
    t->array_length = 0;
    t->bit_width = 0;
}

/**
* This class is *not* thread-safe, use one instance per thread.
*/
class SimpleDictCODEC {
public:
    SimpleDictCODEC() : tmpbuffer(NULL), buffercapacity(0) {}


    /**
    * Silly code that compresses an array of 64-bit integers to an array of char,
    * outputting a convenient data structure.
    *
    * This could be *highly* optimized.
    *
    * For simplicity, array lengths are assumed to be multiples of 32.
    */
    inline dictionary_coded_t compress(uint64_t * array, size_t length) {
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
        for(auto i = distinctvalues.begin(); i != distinctvalues.end(); ++i)  array[i->second] = i->first;
        for(size_t i = 0; i < out.array_length ; ++i) {
            tmpbuffer[i] = distinctvalues[array[i]];
        }
        assert(length % 32 == 0);
        out.bit_width = 32 - __builtin_clz(out.dictionary_size);
        out.compressed_data = new char[sizeof(uint32_t) * out.bit_width * length / 32];
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
    */
    inline void compress(dictionary_coded_t t, uint64_t * out) {
        ensureBufferCapacity(t.array_length);
        assert(t.array_length % 32 == 0);
        unpack32((const uint32_t*) t.compresseddata, tmpbuffer, t.array_length, t.bit_width);
        for(size_t i = 0; i < length; ++i) {
            out[i] = t.dictionary[tmpbuffer[i]];
        }
    }



    inline void clearBuffer() {
        buffercapacity = 0;
        delete[] tmpbuffer;
        tmpbuffer = NULL;
    }
private:
    inline void ensureBufferCapacity(size_t desiredcap) {
        if(desiredcap < buffercapacity) {
            delete[] tmpbuffer;
            tmpbuffer = new uint32[desiredcap];
            assert(tmpbuffer!= NULL);
            buffercapacity = desiredcap;
        }
    }
    uint32_t * tmpbuffer;
    size_t buffercapacity;


};
