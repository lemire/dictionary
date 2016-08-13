# dictionary
Experiments with dictionary coding

Status: at this point, this is just a technology demo to see what might be possible.
This repository might evolve, later, into something that's useful. Ideas, contributions,
criticism, collaboration are invited. (Please don't use this code in production.)

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

We are going to assume that one has a recent Intel processor
for the sake of this experiment.

## Core Idea

It is tempting in dictionary coding, to first unpack the indexes to a temporary buffer
and then run through it and look-up the values in the dictionary. What if it were possible
to decode the indexes and look-up the values in the dictionary in one step?
It is possible with vector instructions as long as you have access to a ``gather`` 
instruction. Thankfully, recent commodity x64 processors have such an instruction.

## Credit

Builds on work done by Eric Daniel for ``parquet-cpp``.  

## Usage

```bash
make && make test
./decodebenchmark
```

## Experimental results (August 12th 2016)

We find that an AVX2 dictionary decoder can be more than twice as fast as a good scalar decoder
on a recent Intel processor (Skylake). See results below. We expect results on older
Intel architectures to be less impressive because the ``vpgather`` instruction that we use was 
quite slow in its early incarnations.

```bash
$ ./decodebenchmark
For this benchmark, use a recent (Skylake) Intel processor for best results.
Intel processor:  Skylake	 compiler version: 5.3.0 20151204		AVX2 is available.
testing with dictionary of size 2
        scalarcodec.uncompress(t,newbuf):  3.07 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.15 cycles per decoded value

testing with dictionary of size 4
        scalarcodec.uncompress(t,newbuf):  2.93 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.19 cycles per decoded value

testing with dictionary of size 8
        scalarcodec.uncompress(t,newbuf):  2.40 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.18 cycles per decoded value

testing with dictionary of size 16
        scalarcodec.uncompress(t,newbuf):  2.92 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.23 cycles per decoded value

testing with dictionary of size 32
        scalarcodec.uncompress(t,newbuf):  2.94 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.18 cycles per decoded value

testing with dictionary of size 64
        scalarcodec.uncompress(t,newbuf):  2.97 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.18 cycles per decoded value

testing with dictionary of size 128
        scalarcodec.uncompress(t,newbuf):  2.32 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.18 cycles per decoded value

testing with dictionary of size 256
        scalarcodec.uncompress(t,newbuf):  3.17 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.32 cycles per decoded value

testing with dictionary of size 512
        scalarcodec.uncompress(t,newbuf):  3.44 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.46 cycles per decoded value

testing with dictionary of size 1024
        scalarcodec.uncompress(t,newbuf):  3.49 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.51 cycles per decoded value

testing with dictionary of size 2048
        scalarcodec.uncompress(t,newbuf):  3.67 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.72 cycles per decoded value

testing with dictionary of size 4096
        scalarcodec.uncompress(t,newbuf):  3.72 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.69 cycles per decoded value

testing with dictionary of size 8192
        scalarcodec.uncompress(t,newbuf):  3.72 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.74 cycles per decoded value

testing with dictionary of size 16384
        scalarcodec.uncompress(t,newbuf):  3.24 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.45 cycles per decoded value

testing with dictionary of size 32768
        scalarcodec.uncompress(t,newbuf):  2.67 cycles per decoded value
  AVXDictCODEC::fastuncompress(t,newbuf):  1.41 cycles per decoded value

```

## Limitations
- For simplicity, we assume that the dictionary is made of 64-bit words. It is hard-coded in the code, but not a fundamental limitation: the code would be faster with smaller words.
- This code is not meant to be use in production. It is a demo.
- This code makes up its own convenient format. It is not meant to plug as-is into an existing framework.
- We assume that the arrays are large. If you have tiny arrays... well...
- We effectively measure steady-state throughput. So we ignore costs such as loading up the dictionary in CPU cache.

