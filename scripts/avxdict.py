#!/usr/bin/env python
import sys
def howmany(bit):
    """ how many values are we going to pack? """
    return 256

def howmany64perwideword():
    return 256/64

def howmanywords(bit):
    return (howmany(bit) * bit + 255)/256

def howmanybytes(bit):
    return howmanywords(bit) * 16

print("""
/** avxdict **/


typedef long long myint64;
""")

print("""typedef void (*avxunpackdictfnc)(const __m256i * compressed, const myint64 * dictionary, int64_t * pout);""")






def plurial(number):
    if(number <> 1):
        return "s"
    else :
        return ""

print("static void avxunpackdict0(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {");
print("  (void) compressed;");
print("  __m256i * out = (__m256i *) pout;");
print("  const __m256i uniquew = _mm256_set1_epi64x(dictionary[0]);");
print("  for(int k = 0; k < {0}; k++) {{".format(howmany(0)/howmany64perwideword()));
print("    _mm256_storeu_si256(out + k, uniquew);")
print("  }");
print("}");
print("")

for bit in range(1,33):
    print("")
    print("/* we packed {0} {1}-bit values, touching {2} 256-bit words, using {3} bytes */ ".format(howmany(bit),bit,howmanywords(bit),howmanybytes(bit)))
    print("static void avxunpackdict{0}(const __m256i * compressed, const myint64 * dictionary, int64_t * pout) {{".format(bit));
    print("  /* we are going to access  {0} 256-bit word{1} */ ".format(howmanywords(bit),plurial(howmanywords(bit))));
    if(howmanywords(bit) == 1):
      print("  __m256i w0;")
    else:
      print("  __m256i w0, w1;")
    print("  __m256i wout;")
    print("  __m256i * out = (__m256i *) pout;");
    if(bit < 32): print("  const __m256i mask = _mm256_set1_epi32({0});".format((1<<bit)-1));
    maskstr = " _mm256_and_si256 ( mask, {0}) "
    if (bit == 32) : maskstr = " {0} " # no need
    oldword = 0
    print("  w0 = _mm256_lddqu_si256 (compressed);")
    for j in range(howmany(bit)/8):
      firstword = j * bit / 32
      secondword = (j * bit + bit - 1)/32
      if(secondword > oldword):
        print("  w{0} = _mm256_lddqu_si256 (compressed + {1});".format(secondword%2,secondword))
        oldword = secondword
      firstshift = (j*bit) % 32
      firstshiftstr = "_mm256_srli_epi32( w{0} , "+str(firstshift)+") "
      if(firstshift == 0):
          firstshiftstr =" w{0} " # no need
      wfirst = firstshiftstr.format(firstword%2)
      if( firstword == secondword):
          if(firstshift + bit <> 32):
            wfirst  = maskstr.format(wfirst)
          print("  wout = {0}; // 256-bit word to be output".format(wfirst));
          #print("  _mm256_storeu_si256(out + {0}, {1});".format(j,wfirst))
          print("  _mm256_storeu_si256(out + {0},_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,0), 8)); // load from dictionary and store".format(2*j))
          print("  _mm256_storeu_si256(out + {0},_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store".format(2*j+1))
      else:
          secondshift = (32-firstshift)
          wsecond = "_mm256_slli_epi32( w{0} , {1} ) ".format((firstword+1)%2,secondshift)
          wfirstorsecond = " _mm256_or_si256 ({0},{1}) ".format(wfirst,wsecond)
          wfirstorsecond = maskstr.format(wfirstorsecond)
          print("  wout = {0}; // 256-bit word to be output".format(wfirstorsecond));
          print("  _mm256_storeu_si256(out + {0},_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,0), 8)); // load from dictionary and store".format(2*j))
          print("  _mm256_storeu_si256(out + {0},_mm256_i32gather_epi64(dictionary,_mm256_extractf128_si256(wout,1), 8)); // load from dictionary and store".format(2*j+1))
    print("}");
    print("")



print("static avxunpackdictfnc avxfuncUnpackDictArr[] = {")
for bit in range(0,32):
  print("&avxunpackdict{0},".format(bit))
print("&avxunpackdict32")
print("};")
print("/** end of avxdict **/")
