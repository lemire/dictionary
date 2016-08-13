#include <cstdint>
#include <cassert>
#include <iostream>

#include "benchmark.h"
#include "avxcodec.h"
#include "scalar.h"



void scalartest(uint32_t numberdistinct, uint32_t length = 1<<16, int repeat = 500) {
    uint64_t * buf = new uint64_t[length];
    for(size_t i = 0; i < length; i++) {
        buf[i] = (i % numberdistinct) * UINT64_C(0xcb9fe8c7cff9982a) + 77777 ;// made up
    }
    SimpleDictCODEC scalarcodec;
    dictionary_coded_t t = scalarcodec.compress(buf, length);
    uint64_t * newbuf = new uint64_t[length];
    BEST_TIME(scalarcodec.uncompress(t,newbuf), length, repeat, length);
    for(size_t i = 0; i < length; i++) {
        assert(buf[i] == newbuf[i]);
    }
    delete[] newbuf;
    delete[] buf;
}


void fasttest(uint32_t distinct, uint32_t length = 1<<16, int repeat = 500) {
    uint64_t * buf = new uint64_t[length];
    for(size_t i = 0; i < length; i++) {
        buf[i] = (i % distinct) * UINT64_C(0xcb9fe8c7cff9982a) + 77777 ;// made up
    }
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


int main() {
    printf("For this benchmark, use a recent (Skylake) Intel processor for best results.\n");
    tellmeall();
    for(uint32_t distinct = 2; distinct < 65536; distinct *=2) {
        std::cout << "testing with dictionary of size " << distinct << std::endl;
        scalartest(distinct);
        fasttest(distinct);
        std::cout<<std::endl;
    }
    return 0;
}
