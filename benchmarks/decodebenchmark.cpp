#include <cstdint>
#include <cassert>
#include <iostream>

#include <stdlib.h>

#include "benchmark.h"

#ifdef __AVX2__
#include "avxcodec.h"
#endif

#include "scalar.h"


void fill_buffer(uint64_t * buf, uint32_t length, uint32_t distinct)
{
    srand(1);
    for(size_t i = 0; i < length; i++) {
        buf[i] = rand() % distinct;
        //buf[i] = i % distinct;     // would produce streaming reads from the dictionary
    }
}

void scalartest(uint32_t distinct, uint32_t length = 1<<16, int repeat = 500) {
    uint64_t * buf = new uint64_t[length];
    fill_buffer(buf, length, distinct);

    SimpleDictCODEC scalarcodec;
    dictionary_coded_t t = scalarcodec.compress(buf, length);
    std::cout << "Actual dict size: " << t.dictionary_size << std::endl;
    uint64_t * newbuf = new uint64_t[length];
    BEST_TIME(scalarcodec.uncompress(t,newbuf), length, repeat, length);
    for(size_t i = 0; i < length; i++) {
        assert(buf[i] == newbuf[i]);
    }
    delete[] newbuf;
    delete[] buf;
}

#ifdef __AVX2__
void mediumtest(uint32_t distinct, uint32_t length = 1<<16, int repeat = 500) {
    uint64_t * buf = new uint64_t[length];
    fill_buffer(buf, length, distinct);

    AVXDictCODEC codec;
    dictionary_coded_t t (codec.compress(buf, length) );
    uint64_t * newbuf = new uint64_t[length];
    BEST_TIME(codec.uncompress(t,newbuf), length, repeat, length);
    for(size_t i = 0; i < length; i++) {
        assert(buf[i] == newbuf[i]);
    }
    delete[] newbuf;
    delete[] buf;
}


void fasttest(uint32_t distinct, uint32_t length = 1<<16, int repeat = 500) {
    uint64_t * buf = new uint64_t[length];
    fill_buffer(buf, length, distinct);

    AVXDictCODEC codec;
    dictionary_coded_t t (codec.compress(buf, length) );
    uint64_t * newbuf = new uint64_t[length];
    BEST_TIME(AVXDictCODEC::fastuncompress(t,newbuf), length, repeat, length);
    for(size_t i = 0; i < length; i++) {
        assert(buf[i] == newbuf[i]);
    }
    delete[] newbuf;
    delete[] buf;
}
#endif

int main() {
    printf("For this benchmark, use a recent (Skylake) Intel processor for best results.\n");
    tellmeall();
    uint32_t length = 1<<23;    // larger than L3 cache
    int repeat = 5;
    for(uint32_t distinct = 2; distinct <= (1<<20); distinct *=2) {
        std::cout << "testing with dictionary of size " << distinct << std::endl;
        scalartest(distinct, length, repeat);
#ifdef __AVX2__
        mediumtest(distinct, length, repeat);
        fasttest(distinct, length, repeat);
#endif
        std::cout<<std::endl;
    }
    return 0;
}
