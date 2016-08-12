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

We are going to assume that one has a recent (Haswell from 2013 or better) Intel processor
for the sake of this experiment.
