#!/usr/bin/env python
import sys
def howmany(bit):
    """ how many values are we going to pack? """
    return 512

def howmany64perwideword():
    return 512/64

def howmanywords(bit):
    return (howmany(bit) * bit + 511)/512

def howmanybytes(bit):
    return howmanywords(bit) * 64

print("""
/** avxdict512 **/


typedef long long myint64;
""")

print("""typedef void (*avx512unpackdictfnc)(const __m512i * compressed, const myint64 * dictionary, int64_t * pout);""")






def plurial(number):
    if(number <> 1):
        return "s"
    else :
        return ""

print("static void avx512unpackdict0(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {");
print("  (void) compressed;");
print("  __m512i * out = (__m512i *) pout;");
print("  const __m512i uniquew = _mm512_set1_epi64(dictionary[0]);");
print("  for(int k = 0; k < {0}; k++) {{".format(howmany(0)/howmany64perwideword()));
print("    _mm512_storeu_si512(out + k, uniquew);")
print("  }");
print("}");
print("")

for bit in range(1,33):
    print("")
    print("/* we packed {0} {1}-bit values, touching {2} 512-bit words, using {3} bytes */ ".format(howmany(bit),bit,howmanywords(bit),howmanybytes(bit)))
    print("static void avx512unpackdict{0}(const __m512i * compressed, const myint64 * dictionary, int64_t * pout) {{".format(bit));
    print("  /* we are going to access  {0} 512-bit word{1} */ ".format(howmanywords(bit),plurial(howmanywords(bit))));
    if(howmanywords(bit) == 1):
      print("  __m512i w0;")
    else:
      print("  __m512i w0, w1;")
    print("  __m512i wout;")
    print("  __m512i * out = (__m512i *) pout;");
    if(bit < 32): print("  const __m512i mask = _mm512_set1_epi32({0});".format((1<<bit)-1));
    maskstr = " _mm512_and_si512 ( mask, {0}) "
    if (bit == 32) : maskstr = " {0} " # no need
    oldword = 0
    print("  w0 = _mm512_loadu_si512 (compressed);")
    for j in range(howmany(bit)/16):
      firstword = j * bit / 32
      secondword = (j * bit + bit - 1)/32
      if(secondword > oldword):
        print("  w{0} = _mm512_loadu_si512 (compressed + {1});".format(secondword%2,secondword))
        oldword = secondword
      firstshift = (j*bit) % 32
      firstshiftstr = "_mm512_srli_epi32( w{0} , "+str(firstshift)+") "
      if(firstshift == 0):
          firstshiftstr =" w{0} " # no need
      wfirst = firstshiftstr.format(firstword%2)
      if( firstword == secondword):
          if(firstshift + bit <> 32):
            wfirst  = maskstr.format(wfirst)
          print("  wout = {0}; // 512-bit word to be output".format(wfirst));
          print("  _mm512_storeu_si512(out + {0},_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store".format(2*j))
          print("  _mm512_storeu_si512(out + {0},_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store".format(2*j+1))
      else:
          secondshift = (32-firstshift)
          wsecond = "_mm512_slli_epi32( w{0} , {1} ) ".format((firstword+1)%2,secondshift)
          wfirstorsecond = " _mm512_or_si512 ({0},{1}) ".format(wfirst,wsecond)
          wfirstorsecond = maskstr.format(wfirstorsecond)
          print("  wout = {0}; // 512-bit word to be output".format(wfirstorsecond));
          print("  _mm512_storeu_si512(out + {0},_mm512_i32gather_epi64(_mm512_castsi512_si256(wout),dictionary, 8)); // load from dictionary and store".format(2*j))
          print("  _mm512_storeu_si512(out + {0},_mm512_i32gather_epi64(_mm512_extracti64x4_epi64(wout,1),dictionary, 8)); // load from dictionary and store".format(2*j+1))
    print("}");
    print("")



print("static avx512unpackdictfnc avx512funcUnpackDictArr[] = {")
for bit in range(0,32):
  print("&avx512unpackdict{0},".format(bit))
print("&avx512unpackdict32")
print("};")
print("/** end of avxdict **/")
