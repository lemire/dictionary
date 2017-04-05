# dictionary
High-performance dictionary coding

Suppose you want to compress a large array of values with
(relatively) few distinct values. For example, maybe you have 16 distinct 64-bit
values. Only four bits are needed to store a value in the range [0,16) using
binary packing,  so if you have long arrays, it is possible to save 60 bits per value (compress
the data by a factor of 16).


We consider the following (simple) form of dictionary coding. We
have a dictionary of 64-bit values (could be pointers) stored
in an array. In the compression phase, we convert the values to indexes
and binary pack them. In the decompression phase, we
try to recover the dictionary-coded values as fast as possible.

Dictionary coding is in common use within database systems (e.g., Oracle, Parquet and so forth).

We are going to assume that one has a recent Intel processor
for the sake of this experiment.

## Core Idea

It is tempting in dictionary coding, to first unpack the indexes to a temporary buffer
and then run through it and look-up the values in the dictionary. What if it were possible
to decode the indexes and look-up the values in the dictionary in one step?
It is possible with vector instructions as long as you have access to a ``gather``
instruction. Thankfully, recent commodity x64 processors have such an instruction.

## A word on RAM access

There is no slower processor than an idle processor waiting for the memory
subsystem.

When working with large data sets, it is tempting to decompress them from RAM
to RAM, converting gigabytes of compressed data into (many more) gigabytes of
uncompressed data.

If the purpose of compression is to keep more of the data close to the CPU,
then this is wasteful.

One should engineer applications so as to work on cache-friendly blocks. For
example, if have an array made of billions of values, instead of decoding them
all to RAM, and then reading them, it is much better to decode them in small blocks
at a time. In fact, ideally, one would prefer not to decode the data at all if possible:
working directly over the compressed data would be ideal.

If you must decode gigabytes of data to RAM or to disk, then you should expect
to be wasting enormous quantities of CPU cycles.

## Usage

```bash
make && make test
./decodebenchmark
```

## Experimental results (Skylake, August 24th 2016)

We find that an AVX2 dictionary decoder can be more than twice as fast as a good scalar decoder
on a recent Intel processor (Skylake) for modest dictionary sizes. Even with large
dictionaries, the AVX2 gather approach is still remarkably faster. See results below. We expect results on older
Intel architectures to be less impressive because the ``vpgather`` instruction that we use was
quite slow in its early incarnations.

The case with large dictionary as implemented here is somewhat pessimistic as it assumes
that all values are equally likely. In most instances, a dictionary will have frequent
values, more likely to be repeated. This will reduce the number of cache misses.

Also, in practice one might limit the size of the dictionary by horizontal partitions.

```bash
$ ./decodebenchmark
For this benchmark, use a recent (Skylake) Intel processor for best results.
Intel processor:  Skylake     compiler version: 5.3.0 20151204        AVX2 is available.
Using array sizes of 8388608 values or 65536 kiB.
testing with dictionary of size 2
Actual dict size: 2
        scalarcodec.uncompress(t,newbuf):  4.00 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.06 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.45 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.91 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.15 cycles per decoded value

testing with dictionary of size 4
Actual dict size: 4
        scalarcodec.uncompress(t,newbuf):  3.99 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.06 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.46 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.91 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.19 cycles per decoded value

testing with dictionary of size 8
Actual dict size: 8
        scalarcodec.uncompress(t,newbuf):  3.52 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  2.38 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.49 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.93 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.17 cycles per decoded value

testing with dictionary of size 16
Actual dict size: 16
        scalarcodec.uncompress(t,newbuf):  4.01 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.08 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.50 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.95 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.19 cycles per decoded value

testing with dictionary of size 32
Actual dict size: 32
        scalarcodec.uncompress(t,newbuf):  4.02 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.06 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.51 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.96 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.18 cycles per decoded value

testing with dictionary of size 64
Actual dict size: 64
        scalarcodec.uncompress(t,newbuf):  4.02 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.08 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.54 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.98 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.17 cycles per decoded value

testing with dictionary of size 128
Actual dict size: 128
        scalarcodec.uncompress(t,newbuf):  3.59 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  2.35 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.55 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.99 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.14 cycles per decoded value

testing with dictionary of size 256
Actual dict size: 256
        scalarcodec.uncompress(t,newbuf):  4.03 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.10 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.55 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.00 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.22 cycles per decoded value

testing with dictionary of size 512
Actual dict size: 512
        scalarcodec.uncompress(t,newbuf):  4.04 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.11 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.55 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.01 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.20 cycles per decoded value

testing with dictionary of size 1024
Actual dict size: 1024
        scalarcodec.uncompress(t,newbuf):  4.04 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.11 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.57 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.04 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.18 cycles per decoded value

testing with dictionary of size 2048
Actual dict size: 2048
        scalarcodec.uncompress(t,newbuf):  4.08 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.15 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.67 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.05 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.22 cycles per decoded value

testing with dictionary of size 4096
Actual dict size: 4096
        scalarcodec.uncompress(t,newbuf):  4.14 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.33 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.69 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.12 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.32 cycles per decoded value

testing with dictionary of size 8192
Actual dict size: 8192
        scalarcodec.uncompress(t,newbuf):  4.35 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.65 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  3.85 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.28 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  1.67 cycles per decoded value

testing with dictionary of size 16384
Actual dict size: 16384
        scalarcodec.uncompress(t,newbuf):  4.51 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.95 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  4.07 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  2.55 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  2.12 cycles per decoded value

testing with dictionary of size 32768
Actual dict size: 32768
        scalarcodec.uncompress(t,newbuf):  4.88 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  3.84 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  4.89 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.52 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.02 cycles per decoded value

testing with dictionary of size 65536
Actual dict size: 65536
        scalarcodec.uncompress(t,newbuf):  7.14 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  5.47 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.68 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  5.18 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  4.53 cycles per decoded value

testing with dictionary of size 131072
Actual dict size: 131072
        scalarcodec.uncompress(t,newbuf):  7.96 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.05 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  7.53 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  6.01 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  5.43 cycles per decoded value

testing with dictionary of size 262144
Actual dict size: 262144
        scalarcodec.uncompress(t,newbuf):  8.30 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.35 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  8.08 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  6.46 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  5.66 cycles per decoded value

testing with dictionary of size 524288
Actual dict size: 524288
        scalarcodec.uncompress(t,newbuf):  8.48 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.39 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  8.09 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  6.44 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  5.83 cycles per decoded value

testing with dictionary of size 1048576
Actual dict size: 1048235
        scalarcodec.uncompress(t,newbuf):  11.85 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  10.53 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  11.65 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  8.47 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  8.07 cycles per decoded value
```

## Experimental results (Knights Landing, August 24th 2016)

We find that an AVX-512 dictionary decoder can be than twice as fast as an AVX dictionary
decoder which is in turn twice as fast as a scalar decoder
on a recent Intel processor (Knights Landing) for modest dictionary sizes. 
The case with large dictionary as implemented here is somewhat pessimistic as it assumes
that all values are equally likely.


```bash
$ ./decodebenchmark
For this benchmark, use a recent (Skylake) Intel processor for best results.
Intel processor:  UNKNOWN     compiler version: 5.3.0        AVX2 is available.
Using array sizes of 8388608 values or 65536 kiB.
testing with dictionary of size 2
Actual dict size: 2
        scalarcodec.uncompress(t,newbuf):  7.75 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.39 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.26 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.22 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.06 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.48 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.14 cycles per decoded value

testing with dictionary of size 4
Actual dict size: 4
        scalarcodec.uncompress(t,newbuf):  7.83 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.49 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.35 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.23 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.10 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.49 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.21 cycles per decoded value

testing with dictionary of size 8
Actual dict size: 8
        scalarcodec.uncompress(t,newbuf):  7.27 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.99 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.17 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.23 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.10 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.59 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.25 cycles per decoded value

testing with dictionary of size 16
Actual dict size: 16
        scalarcodec.uncompress(t,newbuf):  7.98 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.65 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.32 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.23 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.16 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.68 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.34 cycles per decoded value

testing with dictionary of size 32
Actual dict size: 32
        scalarcodec.uncompress(t,newbuf):  7.92 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.63 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.27 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.23 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.19 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.65 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.43 cycles per decoded value

testing with dictionary of size 64
Actual dict size: 64
        scalarcodec.uncompress(t,newbuf):  8.05 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.76 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.32 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.31 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.25 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.85 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.66 cycles per decoded value

testing with dictionary of size 128
Actual dict size: 128
        scalarcodec.uncompress(t,newbuf):  6.64 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.36 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.19 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.34 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.28 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.83 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.57 cycles per decoded value

testing with dictionary of size 256
Actual dict size: 256
        scalarcodec.uncompress(t,newbuf):  8.07 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.87 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.39 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.39 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.35 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  1.95 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.69 cycles per decoded value

testing with dictionary of size 512
Actual dict size: 512
        scalarcodec.uncompress(t,newbuf):  8.07 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.87 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.32 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.52 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.48 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  2.04 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.76 cycles per decoded value

testing with dictionary of size 1024
Actual dict size: 1024
        scalarcodec.uncompress(t,newbuf):  8.22 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.97 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.43 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.63 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.57 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  2.05 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.83 cycles per decoded value

testing with dictionary of size 2048
Actual dict size: 2048
        scalarcodec.uncompress(t,newbuf):  7.97 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  7.69 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.37 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.76 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.64 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  2.11 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  1.91 cycles per decoded value

testing with dictionary of size 4096
Actual dict size: 4096
        scalarcodec.uncompress(t,newbuf):  8.53 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  8.20 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.67 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.58 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.56 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  2.55 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  2.35 cycles per decoded value

testing with dictionary of size 8192
Actual dict size: 8192
        scalarcodec.uncompress(t,newbuf):  8.66 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  8.27 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.79 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.92 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.86 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  2.80 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  2.54 cycles per decoded value

testing with dictionary of size 16384
Actual dict size: 16384
        scalarcodec.uncompress(t,newbuf):  8.85 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  8.55 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.95 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  4.05 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.87 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  3.14 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  2.96 cycles per decoded value

testing with dictionary of size 32768
Actual dict size: 32768
        scalarcodec.uncompress(t,newbuf):  6.75 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  6.81 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  6.94 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  3.68 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  3.58 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  3.41 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  3.24 cycles per decoded value

testing with dictionary of size 65536
Actual dict size: 65536
        scalarcodec.uncompress(t,newbuf):  11.75 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  13.76 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  9.64 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  5.29 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  5.50 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  4.54 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  4.66 cycles per decoded value

testing with dictionary of size 131072
Actual dict size: 131072
        scalarcodec.uncompress(t,newbuf):  19.07 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  19.53 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  17.02 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  11.02 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  11.01 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  8.03 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  8.01 cycles per decoded value

testing with dictionary of size 262144
Actual dict size: 262144
        scalarcodec.uncompress(t,newbuf):  22.84 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  23.12 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  20.63 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  16.57 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  16.45 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  13.68 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  13.69 cycles per decoded value

testing with dictionary of size 524288
Actual dict size: 524288
        scalarcodec.uncompress(t,newbuf):  22.34 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  22.54 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  20.36 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  16.30 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  16.34 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  14.91 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  14.94 cycles per decoded value

testing with dictionary of size 1048576
Actual dict size: 1048235
        scalarcodec.uncompress(t,newbuf):  21.93 cycles per decoded value
   decodetocache(&sc, &t,newbuf,bufsize):  22.11 cycles per decoded value
           avxcodec.uncompress(t,newbuf):  19.91 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  16.33 cycles per decoded value
     AVXdecodetocache(&t,newbuf,bufsize):  16.30 cycles per decoded value
AVX512DictCODEC::fastuncompress(t,newbuf):  15.32 cycles per decoded value
  AVX512decodetocache(&t,newbuf,bufsize):  15.31 cycles per decoded value

```

## Limitations
- We support just one dictionary. In practice, one might want to use horizontal partitions.
- We do not have a realistic usage of the dictionary values (we use a uniform distribution).
- For simplicity, we assume that the dictionary is made of 64-bit words. It is hard-coded in the code, but not a fundamental limitation: the code would be faster with smaller words.
- This code is not meant to be use in production. It is a demo.
- This code makes up its own convenient format. It is not meant to plug as-is into an existing framework.
- We assume that the arrays are large. If you have tiny arrays... well...
- We effectively measure steady-state throughput. So we ignore costs such as loading up the dictionary in CPU cache.

## Authors
Daniel Lemire and Eric Daniel (motivated by ``parquet-cpp``)


## Other relevant libraries


* The FastPFOR C++ library : Fast integer compression https://github.com/lemire/FastPFor
* LittleIntPacker: C library to pack and unpack short arrays of integers as fast as possible https://github.com/lemire/LittleIntPacker
* The SIMDComp library: A simple C library for compressing lists of integers using binary packing https://github.com/lemire/simdcomp
* StreamVByte: Fast integer compression in C using the StreamVByte codec https://github.com/lemire/streamvbyte
* MaskedVByte: Fast decoder for VByte-compressed integers https://github.com/lemire/MaskedVByte
* CSharpFastPFOR: A C#  integer compression library  https://github.com/Genbox/CSharpFastPFOR
* JavaFastPFOR: A java integer compression library https://github.com/lemire/JavaFastPFOR
* Encoding: Integer Compression Libraries for Go https://github.com/zhenjl/encoding
* FrameOfReference is a C++ library dedicated to frame-of-reference (FOR) compression: https://github.com/lemire/FrameOfReference
* libvbyte: A fast implementation for varbyte 32bit/64bit integer compression https://github.com/cruppstahl/libvbyte
* TurboPFor is a C library that offers lots of interesting optimizations. Well worth checking! (GPL license) https://github.com/powturbo/TurboPFor
* Oroch is a C++ library that offers a usable API (MIT license) https://github.com/ademakov/Oroch

