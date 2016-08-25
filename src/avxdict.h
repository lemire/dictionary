#ifndef DICT_AVXDICT_H
#define DICT_AVXDICT_H
#ifndef __AVX2__
#error This code requires AVX2 support (available on Intel processors made since ~2013).
#endif


#ifdef _MSC_VER
/* Microsoft C/C++-compatible compiler */
#include <intrin.h>
#else
/* Pretty much anything else. */
#include <x86intrin.h>
#endif

#include <cstdint>


/** avxdict **/


typedef long long myint64;

typedef void (*avxunpackdictfnc)(const __m256i * compressed, const myint64 * dictionary, int64_t * pout);
static void avxunpackdict0(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  (void) compressed;
  __m256i * out = (__m256i *) pout;
  const __m256i uniquew = _mm256_set1_epi64x(dictionary[0]);
  for(int k = 0; k < 64; k++) {
    _mm256_storeu_si256(out + k, uniquew);
  }
}


/* we packed 256 1-bit values, touching 1 256-bit words, using 32 bytes */
static void avxunpackdict1(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  1 256-bit word */
  __m256i w0;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(1);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 21) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 23) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 25) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 26) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 27) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 28) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 29) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 30) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 31) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 2-bit values, touching 2 256-bit words, using 64 bytes */
static void avxunpackdict2(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  2 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(3);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 26) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 28) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 30) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 26) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 28) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 30) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 3-bit values, touching 3 256-bit words, using 96 bytes */
static void avxunpackdict3(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  3 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(7);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 21) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 27) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 25) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 28) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 23) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 26) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 29) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 4-bit values, touching 4 256-bit words, using 128 bytes */
static void avxunpackdict4(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  4 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(15);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 28) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 28) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 28) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 28) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 5-bit values, touching 5 256-bit words, using 160 bytes */
static void avxunpackdict5(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  5 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(31);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 25) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 23) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 21) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 26) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 31) ,_mm256_slli_epi32( w1 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 27) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 6-bit values, touching 6 256-bit words, using 192 bytes */
static void avxunpackdict6(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  6 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(63);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 26) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 26) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 7-bit values, touching 7 256-bit words, using 224 bytes */
static void avxunpackdict7(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  7 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(127);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 21) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 24) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 23) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 25) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 8-bit values, touching 8 256-bit words, using 256 bytes */
static void avxunpackdict8(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  8 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(255);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 24) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 9-bit values, touching 9 256-bit words, using 288 bytes */
static void avxunpackdict9(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  9 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(511);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 22) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 21) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 23) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 10-bit values, touching 10 256-bit words, using 320 bytes */
static void avxunpackdict10(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  10 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(1023);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 22) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 22) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 11-bit values, touching 11 256-bit words, using 352 bytes */
static void avxunpackdict11(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  11 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(2047);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 25) ,_mm256_slli_epi32( w0 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 27) ,_mm256_slli_epi32( w0 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 19) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 20) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 21) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 12-bit values, touching 12 256-bit words, using 384 bytes */
static void avxunpackdict12(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  12 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(4095);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 20) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 20) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 20) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 20) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 13-bit values, touching 13 256-bit words, using 416 bytes */
static void avxunpackdict13(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  13 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(8191);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 21) ,_mm256_slli_epi32( w0 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 17) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 18) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 31) ,_mm256_slli_epi32( w1 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 25) ,_mm256_slli_epi32( w0 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 19) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 14-bit values, touching 14 256-bit words, using 448 bytes */
static void avxunpackdict14(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  14 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(16383);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 18) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 18) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 15-bit values, touching 15 256-bit words, using 480 bytes */
static void avxunpackdict15(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  15 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(32767);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 15) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 16) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 27) ,_mm256_slli_epi32( w0 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 19) ,_mm256_slli_epi32( w0 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 17) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 16-bit values, touching 16 256-bit words, using 512 bytes */
static void avxunpackdict16(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  16 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(65535);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 16) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 17-bit values, touching 17 256-bit words, using 544 bytes */
static void avxunpackdict17(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  17 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(131071);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 19) ,_mm256_slli_epi32( w0 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 27) ,_mm256_slli_epi32( w0 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 14) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 13) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 15) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 18-bit values, touching 18 256-bit words, using 576 bytes */
static void avxunpackdict18(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  18 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(262143);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 14) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 14) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 19-bit values, touching 19 256-bit words, using 608 bytes */
static void avxunpackdict19(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  19 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(524287);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 19) ,_mm256_slli_epi32( w1 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 25) ,_mm256_slli_epi32( w0 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 12) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 31) ,_mm256_slli_epi32( w1 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 11) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 21) ,_mm256_slli_epi32( w0 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 13) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 20-bit values, touching 20 256-bit words, using 640 bytes */
static void avxunpackdict20(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  20 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(1048575);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 12) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 12) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 12) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 12) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 21-bit values, touching 21 256-bit words, using 672 bytes */
static void avxunpackdict21(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  21 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(2097151);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 10) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 9) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 19) ,_mm256_slli_epi32( w1 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 27) ,_mm256_slli_epi32( w0 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 25) ,_mm256_slli_epi32( w0 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 14) ,_mm256_slli_epi32( w1 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 13) ,_mm256_slli_epi32( w1 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 11) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 22-bit values, touching 22 256-bit words, using 704 bytes */
static void avxunpackdict22(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  22 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(4194303);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 10) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 14) ,_mm256_slli_epi32( w1 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 10) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 23-bit values, touching 23 256-bit words, using 736 bytes */
static void avxunpackdict23(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  23 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(8388607);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 23) ,_mm256_slli_epi32( w1 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 19) ,_mm256_slli_epi32( w0 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 10) ,_mm256_slli_epi32( w1 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 11) ,_mm256_slli_epi32( w0 , 21 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 7) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 21) ,_mm256_slli_epi32( w0 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 8) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 13) ,_mm256_slli_epi32( w0 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 9) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 24-bit values, touching 24 256-bit words, using 768 bytes */
static void avxunpackdict24(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  24 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(16777215);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 8) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 25-bit values, touching 25 256-bit words, using 800 bytes */
static void avxunpackdict25(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  25 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(33554431);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 11) ,_mm256_slli_epi32( w1 , 21 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 15) ,_mm256_slli_epi32( w0 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 19) ,_mm256_slli_epi32( w1 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 5) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 9) ,_mm256_slli_epi32( w0 , 23 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 13) ,_mm256_slli_epi32( w1 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 6) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 17) ,_mm256_slli_epi32( w0 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 10) ,_mm256_slli_epi32( w1 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 7) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 26-bit values, touching 26 256-bit words, using 832 bytes */
static void avxunpackdict26(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  26 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(67108863);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 14) ,_mm256_slli_epi32( w1 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 10) ,_mm256_slli_epi32( w0 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 6) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 10) ,_mm256_slli_epi32( w1 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 6) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 27-bit values, touching 27 256-bit words, using 864 bytes */
static void avxunpackdict27(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  27 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(134217727);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 7) ,_mm256_slli_epi32( w1 , 25 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 29) ,_mm256_slli_epi32( w0 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 19) ,_mm256_slli_epi32( w0 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 14) ,_mm256_slli_epi32( w1 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 9) ,_mm256_slli_epi32( w0 , 23 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 4) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 31) ,_mm256_slli_epi32( w1 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 11) ,_mm256_slli_epi32( w1 , 21 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 6) ,_mm256_slli_epi32( w0 , 26 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w0 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 23) ,_mm256_slli_epi32( w0 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 13) ,_mm256_slli_epi32( w0 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 3) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 10) ,_mm256_slli_epi32( w0 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 5) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 28-bit values, touching 28 256-bit words, using 896 bytes */
static void avxunpackdict28(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  28 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(268435455);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 4) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 4) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 4) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 27);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 4) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 29-bit values, touching 29 256-bit words, using 928 bytes */
static void avxunpackdict29(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  29 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(536870911);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 23) ,_mm256_slli_epi32( w1 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 11) ,_mm256_slli_epi32( w1 , 21 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 5) ,_mm256_slli_epi32( w1 , 27 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 2) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 31) ,_mm256_slli_epi32( w0 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 25) ,_mm256_slli_epi32( w0 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 19) ,_mm256_slli_epi32( w0 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 13) ,_mm256_slli_epi32( w0 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 10) ,_mm256_slli_epi32( w1 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 7) ,_mm256_slli_epi32( w0 , 25 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 4) ,_mm256_slli_epi32( w1 , 28 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout =  _mm256_and_si256 ( mask, _mm256_srli_epi32( w1 , 1) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 27);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 9) ,_mm256_slli_epi32( w1 , 23 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 28);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 6) ,_mm256_slli_epi32( w0 , 26 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 3) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 30-bit values, touching 30 256-bit words, using 960 bytes */
static void avxunpackdict30(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  30 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(1073741823);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 30) ,_mm256_slli_epi32( w1 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 26) ,_mm256_slli_epi32( w1 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 22) ,_mm256_slli_epi32( w1 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 18) ,_mm256_slli_epi32( w1 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 14) ,_mm256_slli_epi32( w1 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 10) ,_mm256_slli_epi32( w1 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 6) ,_mm256_slli_epi32( w1 , 26 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 4) ,_mm256_slli_epi32( w0 , 28 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 2) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  w1 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 28) ,_mm256_slli_epi32( w1 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 24) ,_mm256_slli_epi32( w1 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 20) ,_mm256_slli_epi32( w1 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 16) ,_mm256_slli_epi32( w1 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 12) ,_mm256_slli_epi32( w1 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 10) ,_mm256_slli_epi32( w0 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 27);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 8) ,_mm256_slli_epi32( w1 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 28);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 6) ,_mm256_slli_epi32( w0 , 26 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 29);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 4) ,_mm256_slli_epi32( w1 , 28 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w1 , 2) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 31-bit values, touching 31 256-bit words, using 992 bytes */
static void avxunpackdict31(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  31 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  const __m256i mask = _mm256_set1_epi32(2147483647);
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  _mm256_and_si256 ( mask,  w0 ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 31) ,_mm256_slli_epi32( w1 , 1 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 30) ,_mm256_slli_epi32( w0 , 2 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 29) ,_mm256_slli_epi32( w1 , 3 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 28) ,_mm256_slli_epi32( w0 , 4 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 27) ,_mm256_slli_epi32( w1 , 5 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 26) ,_mm256_slli_epi32( w0 , 6 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 25) ,_mm256_slli_epi32( w1 , 7 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 24) ,_mm256_slli_epi32( w0 , 8 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 23) ,_mm256_slli_epi32( w1 , 9 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 22) ,_mm256_slli_epi32( w0 , 10 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 21) ,_mm256_slli_epi32( w1 , 11 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 20) ,_mm256_slli_epi32( w0 , 12 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 19) ,_mm256_slli_epi32( w1 , 13 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 18) ,_mm256_slli_epi32( w0 , 14 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 17) ,_mm256_slli_epi32( w1 , 15 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 16) ,_mm256_slli_epi32( w0 , 16 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 15) ,_mm256_slli_epi32( w1 , 17 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 14) ,_mm256_slli_epi32( w0 , 18 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 13) ,_mm256_slli_epi32( w1 , 19 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 12) ,_mm256_slli_epi32( w0 , 20 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 11) ,_mm256_slli_epi32( w1 , 21 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 10) ,_mm256_slli_epi32( w0 , 22 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 9) ,_mm256_slli_epi32( w1 , 23 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 8) ,_mm256_slli_epi32( w0 , 24 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 7) ,_mm256_slli_epi32( w1 , 25 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 6) ,_mm256_slli_epi32( w0 , 26 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 27);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 5) ,_mm256_slli_epi32( w1 , 27 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 28);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 4) ,_mm256_slli_epi32( w0 , 28 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 29);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w0 , 3) ,_mm256_slli_epi32( w1 , 29 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 30);
  wout =  _mm256_and_si256 ( mask,  _mm256_or_si256 (_mm256_srli_epi32( w1 , 2) ,_mm256_slli_epi32( w0 , 30 ) ) ) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  wout = _mm256_srli_epi32( w0 , 1) ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}


/* we packed 256 32-bit values, touching 32 256-bit words, using 1024 bytes */
static void avxunpackdict32(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {
  /* we are going to access  32 256-bit words */
  __m256i w0, w1;
  __m256i wout;
  __m256i * out = (__m256i *) pout;
  w0 = _mm256_lddqu_si256 (compressed);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 0,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 1,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 1);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 2,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 3,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 2);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 4,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 5,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 3);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 6,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 7,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 4);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 8,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 9,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 5);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 10,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 11,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 6);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 12,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 13,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 7);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 14,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 15,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 8);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 16,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 17,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 9);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 18,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 19,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 10);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 20,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 21,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 11);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 22,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 23,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 12);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 24,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 25,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 13);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 26,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 27,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 14);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 28,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 29,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 15);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 30,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 31,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 16);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 32,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 33,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 17);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 34,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 35,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 18);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 36,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 37,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 19);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 38,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 39,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 20);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 40,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 41,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 21);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 42,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 43,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 22);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 44,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 45,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 23);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 46,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 47,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 24);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 48,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 49,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 25);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 50,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 51,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 26);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 52,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 53,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 27);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 54,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 55,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 28);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 56,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 57,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 29);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 58,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 59,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w0 = _mm256_lddqu_si256 (compressed + 30);
  wout =  w0 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 60,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 61,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
  w1 = _mm256_lddqu_si256 (compressed + 31);
  wout =  w1 ; // 256-bit word to be output
  _mm256_storeu_si256(out + 62,_mm256_i32gather_epi64(dictionary,_mm256_castsi256_si128(wout), 8)); // load from dictionary and store
  _mm256_storeu_si256(out + 63,_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store
}

static avxunpackdictfnc avxfuncUnpackDictArr[] = {
&avxunpackdict0,
&avxunpackdict1,
&avxunpackdict2,
&avxunpackdict3,
&avxunpackdict4,
&avxunpackdict5,
&avxunpackdict6,
&avxunpackdict7,
&avxunpackdict8,
&avxunpackdict9,
&avxunpackdict10,
&avxunpackdict11,
&avxunpackdict12,
&avxunpackdict13,
&avxunpackdict14,
&avxunpackdict15,
&avxunpackdict16,
&avxunpackdict17,
&avxunpackdict18,
&avxunpackdict19,
&avxunpackdict20,
&avxunpackdict21,
&avxunpackdict22,
&avxunpackdict23,
&avxunpackdict24,
&avxunpackdict25,
&avxunpackdict26,
&avxunpackdict27,
&avxunpackdict28,
&avxunpackdict29,
&avxunpackdict30,
&avxunpackdict31,
&avxunpackdict32
};
/** end of avxdict **/



void avxunpackdict(const __m256i *  in, const myint64 * dictionary,int64_t *  out, const uint32_t number, const uint32_t bit) {
    for(uint32_t i = 0; i < number / 256; ++i)
        avxfuncUnpackDictArr[bit](in + i * bit, dictionary, out + i * 256);
}
#endif
