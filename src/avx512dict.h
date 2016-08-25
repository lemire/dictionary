#ifndef DICT_AVX512DICT_H
#define DICT_AVX512DICT_H
#ifndef __AVX512F__
#error This code requires AVX-512 support (available on some Intel processors made since 2016)
#endif


#ifdef _MSC_VER
/* Microsoft C/C++-compatible compiler */
#include <intrin.h>
#else
/* Pretty much anything else. */
#include <x86intrin.h>
#endif

#include <cstdint>




/** avxdict512 **/


typedef long long myint64;

typedef void (*avx512unpackdictfnc)(const __m512i * compressed, const myint64 * dictionary, int64_t * pout);
static void avx512unpackdict0(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  (void) compressed;
  __m512i * out = (__m512i *) pout;
  const __m512i uniquew = _mm512_set1_epi64(dictionary[0]);
  for(int k = 0; k < 64; k++) {
    _mm512_storeu_si512(out + k, uniquew);
  }
}


/* we packed 512 1-bit values, touching 1 512-bit words, using 64 bytes */
static void avx512unpackdict1(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  1 512-bit word */
  __m512i w0;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(1);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 21) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 23) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 25) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 26) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 27) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 28) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 29) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 30) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 31) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 2-bit values, touching 2 512-bit words, using 128 bytes */
static void avx512unpackdict2(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  2 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(3);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 26) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 28) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 30) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 26) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 28) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 30) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 3-bit values, touching 3 512-bit words, using 192 bytes */
static void avx512unpackdict3(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  3 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(7);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 21) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 27) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 25) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 28) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 23) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 26) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 29) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 4-bit values, touching 4 512-bit words, using 256 bytes */
static void avx512unpackdict4(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  4 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(15);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 28) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 28) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 28) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 28) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 5-bit values, touching 5 512-bit words, using 320 bytes */
static void avx512unpackdict5(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  5 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(31);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 25) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 23) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 21) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 26) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 31) ,_mm512_slli_epi32( w1 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 27) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 6-bit values, touching 6 512-bit words, using 384 bytes */
static void avx512unpackdict6(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  6 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(63);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 26) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 26) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 7-bit values, touching 7 512-bit words, using 448 bytes */
static void avx512unpackdict7(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  7 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(127);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 21) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 24) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 23) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 25) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 8-bit values, touching 8 512-bit words, using 512 bytes */
static void avx512unpackdict8(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  8 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(255);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 24) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 9-bit values, touching 9 512-bit words, using 576 bytes */
static void avx512unpackdict9(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  9 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(511);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 22) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 21) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 23) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 10-bit values, touching 10 512-bit words, using 640 bytes */
static void avx512unpackdict10(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  10 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(1023);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 22) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 22) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 11-bit values, touching 11 512-bit words, using 704 bytes */
static void avx512unpackdict11(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  11 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(2047);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 25) ,_mm512_slli_epi32( w0 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 27) ,_mm512_slli_epi32( w0 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 19) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 20) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 21) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 12-bit values, touching 12 512-bit words, using 768 bytes */
static void avx512unpackdict12(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  12 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(4095);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 20) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 20) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 20) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 20) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 13-bit values, touching 13 512-bit words, using 832 bytes */
static void avx512unpackdict13(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  13 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(8191);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 21) ,_mm512_slli_epi32( w0 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 17) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 18) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 31) ,_mm512_slli_epi32( w1 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 25) ,_mm512_slli_epi32( w0 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 19) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 14-bit values, touching 14 512-bit words, using 896 bytes */
static void avx512unpackdict14(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  14 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(16383);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 18) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 18) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 15-bit values, touching 15 512-bit words, using 960 bytes */
static void avx512unpackdict15(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  15 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(32767);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 15) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 16) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 27) ,_mm512_slli_epi32( w0 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 19) ,_mm512_slli_epi32( w0 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 17) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 16-bit values, touching 16 512-bit words, using 1024 bytes */
static void avx512unpackdict16(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  16 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(65535);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 16) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 17-bit values, touching 17 512-bit words, using 1088 bytes */
static void avx512unpackdict17(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  17 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(131071);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 19) ,_mm512_slli_epi32( w0 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 27) ,_mm512_slli_epi32( w0 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 14) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 13) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 15) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 18-bit values, touching 18 512-bit words, using 1152 bytes */
static void avx512unpackdict18(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  18 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(262143);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 14) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 14) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 19-bit values, touching 19 512-bit words, using 1216 bytes */
static void avx512unpackdict19(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  19 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(524287);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 19) ,_mm512_slli_epi32( w1 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 25) ,_mm512_slli_epi32( w0 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 12) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 31) ,_mm512_slli_epi32( w1 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 11) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 21) ,_mm512_slli_epi32( w0 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 13) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 20-bit values, touching 20 512-bit words, using 1280 bytes */
static void avx512unpackdict20(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  20 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(1048575);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 12) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 12) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 12) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 12) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 21-bit values, touching 21 512-bit words, using 1344 bytes */
static void avx512unpackdict21(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  21 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(2097151);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 10) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 9) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 19) ,_mm512_slli_epi32( w1 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 27) ,_mm512_slli_epi32( w0 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 25) ,_mm512_slli_epi32( w0 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 14) ,_mm512_slli_epi32( w1 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 13) ,_mm512_slli_epi32( w1 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 11) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 22-bit values, touching 22 512-bit words, using 1408 bytes */
static void avx512unpackdict22(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  22 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(4194303);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 10) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 14) ,_mm512_slli_epi32( w1 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 10) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 23-bit values, touching 23 512-bit words, using 1472 bytes */
static void avx512unpackdict23(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  23 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(8388607);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 23) ,_mm512_slli_epi32( w1 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 19) ,_mm512_slli_epi32( w0 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 10) ,_mm512_slli_epi32( w1 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 11) ,_mm512_slli_epi32( w0 , 21 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 7) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 21) ,_mm512_slli_epi32( w0 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 8) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 13) ,_mm512_slli_epi32( w0 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 9) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 24-bit values, touching 24 512-bit words, using 1536 bytes */
static void avx512unpackdict24(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  24 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(16777215);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 8) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 25-bit values, touching 25 512-bit words, using 1600 bytes */
static void avx512unpackdict25(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  25 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(33554431);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 11) ,_mm512_slli_epi32( w1 , 21 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 15) ,_mm512_slli_epi32( w0 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 19) ,_mm512_slli_epi32( w1 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 5) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 9) ,_mm512_slli_epi32( w0 , 23 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 13) ,_mm512_slli_epi32( w1 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 6) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 17) ,_mm512_slli_epi32( w0 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 10) ,_mm512_slli_epi32( w1 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 7) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 26-bit values, touching 26 512-bit words, using 1664 bytes */
static void avx512unpackdict26(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  26 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(67108863);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 14) ,_mm512_slli_epi32( w1 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 10) ,_mm512_slli_epi32( w0 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 6) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 10) ,_mm512_slli_epi32( w1 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 6) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 27-bit values, touching 27 512-bit words, using 1728 bytes */
static void avx512unpackdict27(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  27 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(134217727);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 7) ,_mm512_slli_epi32( w1 , 25 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 29) ,_mm512_slli_epi32( w0 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 19) ,_mm512_slli_epi32( w0 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 14) ,_mm512_slli_epi32( w1 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 9) ,_mm512_slli_epi32( w0 , 23 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 4) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 31) ,_mm512_slli_epi32( w1 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 11) ,_mm512_slli_epi32( w1 , 21 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 6) ,_mm512_slli_epi32( w0 , 26 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w0 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 23) ,_mm512_slli_epi32( w0 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 13) ,_mm512_slli_epi32( w0 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 3) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 10) ,_mm512_slli_epi32( w0 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 5) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 28-bit values, touching 28 512-bit words, using 1792 bytes */
static void avx512unpackdict28(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  28 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(268435455);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 4) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 4) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 4) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 27);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 4) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 29-bit values, touching 29 512-bit words, using 1856 bytes */
static void avx512unpackdict29(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  29 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(536870911);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 23) ,_mm512_slli_epi32( w1 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 11) ,_mm512_slli_epi32( w1 , 21 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 5) ,_mm512_slli_epi32( w1 , 27 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 2) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 31) ,_mm512_slli_epi32( w0 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 25) ,_mm512_slli_epi32( w0 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 19) ,_mm512_slli_epi32( w0 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 13) ,_mm512_slli_epi32( w0 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 10) ,_mm512_slli_epi32( w1 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 7) ,_mm512_slli_epi32( w0 , 25 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 4) ,_mm512_slli_epi32( w1 , 28 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout =  _mm512_and_si512 ( mask, _mm512_srli_epi32( w1 , 1) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 27);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 9) ,_mm512_slli_epi32( w1 , 23 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 28);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 6) ,_mm512_slli_epi32( w0 , 26 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 3) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 30-bit values, touching 30 512-bit words, using 1920 bytes */
static void avx512unpackdict30(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  30 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(1073741823);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 30) ,_mm512_slli_epi32( w1 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 26) ,_mm512_slli_epi32( w1 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 22) ,_mm512_slli_epi32( w1 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 18) ,_mm512_slli_epi32( w1 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 14) ,_mm512_slli_epi32( w1 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 10) ,_mm512_slli_epi32( w1 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 6) ,_mm512_slli_epi32( w1 , 26 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 4) ,_mm512_slli_epi32( w0 , 28 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 2) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  w1 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 28) ,_mm512_slli_epi32( w1 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 24) ,_mm512_slli_epi32( w1 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 20) ,_mm512_slli_epi32( w1 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 16) ,_mm512_slli_epi32( w1 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 12) ,_mm512_slli_epi32( w1 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 10) ,_mm512_slli_epi32( w0 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 27);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 8) ,_mm512_slli_epi32( w1 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 28);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 6) ,_mm512_slli_epi32( w0 , 26 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 29);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 4) ,_mm512_slli_epi32( w1 , 28 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w1 , 2) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 31-bit values, touching 31 512-bit words, using 1984 bytes */
static void avx512unpackdict31(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  31 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  const __m512i mask = _mm512_set1_epi32(2147483647);
  w0 = _mm512_loadu_si512 (compressed);
  wout =  _mm512_and_si512 ( mask,  w0 ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 31) ,_mm512_slli_epi32( w1 , 1 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 30) ,_mm512_slli_epi32( w0 , 2 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 29) ,_mm512_slli_epi32( w1 , 3 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 28) ,_mm512_slli_epi32( w0 , 4 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 27) ,_mm512_slli_epi32( w1 , 5 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 26) ,_mm512_slli_epi32( w0 , 6 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 25) ,_mm512_slli_epi32( w1 , 7 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 24) ,_mm512_slli_epi32( w0 , 8 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 23) ,_mm512_slli_epi32( w1 , 9 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 22) ,_mm512_slli_epi32( w0 , 10 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 21) ,_mm512_slli_epi32( w1 , 11 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 20) ,_mm512_slli_epi32( w0 , 12 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 19) ,_mm512_slli_epi32( w1 , 13 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 18) ,_mm512_slli_epi32( w0 , 14 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 17) ,_mm512_slli_epi32( w1 , 15 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 16) ,_mm512_slli_epi32( w0 , 16 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 15) ,_mm512_slli_epi32( w1 , 17 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 14) ,_mm512_slli_epi32( w0 , 18 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 13) ,_mm512_slli_epi32( w1 , 19 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 12) ,_mm512_slli_epi32( w0 , 20 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 11) ,_mm512_slli_epi32( w1 , 21 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 10) ,_mm512_slli_epi32( w0 , 22 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 9) ,_mm512_slli_epi32( w1 , 23 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 8) ,_mm512_slli_epi32( w0 , 24 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 7) ,_mm512_slli_epi32( w1 , 25 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 6) ,_mm512_slli_epi32( w0 , 26 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 27);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 5) ,_mm512_slli_epi32( w1 , 27 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 28);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 4) ,_mm512_slli_epi32( w0 , 28 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 29);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w0 , 3) ,_mm512_slli_epi32( w1 , 29 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 30);
  wout =  _mm512_and_si512 ( mask,  _mm512_or_si512 (_mm512_srli_epi32( w1 , 2) ,_mm512_slli_epi32( w0 , 30 ) ) ) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  wout = _mm512_srli_epi32( w0 , 1) ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}


/* we packed 512 32-bit values, touching 32 512-bit words, using 2048 bytes */
static void avx512unpackdict32(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  32 512-bit words */
  __m512i w0, w1;
  __m512i wout;
  __m512i * out = (__m512i *) pout;
  w0 = _mm512_loadu_si512 (compressed);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 0,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 1,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 1);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 2,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 3,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 2);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 4,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 5,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 3);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 6,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 7,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 4);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 8,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 9,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 5);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 10,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 11,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 6);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 12,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 13,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 7);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 14,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 15,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 8);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 16,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 17,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 9);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 18,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 19,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 10);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 20,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 21,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 11);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 22,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 23,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 12);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 24,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 25,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 13);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 26,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 27,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 14);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 28,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 29,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 15);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 30,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 31,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 16);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 32,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 33,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 17);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 34,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 35,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 18);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 36,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 37,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 19);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 38,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 39,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 20);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 40,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 41,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 21);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 42,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 43,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 22);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 44,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 45,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 23);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 46,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 47,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 24);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 48,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 49,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 25);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 50,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 51,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 26);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 52,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 53,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 27);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 54,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 55,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 28);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 56,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 57,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 29);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 58,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 59,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w0 = _mm512_loadu_si512 (compressed + 30);
  wout =  w0 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 60,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 61,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
  w1 = _mm512_loadu_si512 (compressed + 31);
  wout =  w1 ; // 512-bit word to be output
  _mm512_storeu_si512(out + 62,_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store
  _mm512_storeu_si512(out + 63,_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store
}

static avx512unpackdictfnc avx512funcUnpackDictArr[] = {
&avx512unpackdict0,
&avx512unpackdict1,
&avx512unpackdict2,
&avx512unpackdict3,
&avx512unpackdict4,
&avx512unpackdict5,
&avx512unpackdict6,
&avx512unpackdict7,
&avx512unpackdict8,
&avx512unpackdict9,
&avx512unpackdict10,
&avx512unpackdict11,
&avx512unpackdict12,
&avx512unpackdict13,
&avx512unpackdict14,
&avx512unpackdict15,
&avx512unpackdict16,
&avx512unpackdict17,
&avx512unpackdict18,
&avx512unpackdict19,
&avx512unpackdict20,
&avx512unpackdict21,
&avx512unpackdict22,
&avx512unpackdict23,
&avx512unpackdict24,
&avx512unpackdict25,
&avx512unpackdict26,
&avx512unpackdict27,
&avx512unpackdict28,
&avx512unpackdict29,
&avx512unpackdict30,
&avx512unpackdict31,
&avx512unpackdict32
};
/** end of avxdict **/



void avx512unpackdict(const __m512i *  in, const myint64 * dictionary,int64_t *  out, const uint32_t number, const uint32_t bit) {
    for(uint32_t i = 0; i < number / 512; ++i)
        avx512funcUnpackDictArr[bit](in + i * bit, dictionary, out + i * 512);
}
#endif
