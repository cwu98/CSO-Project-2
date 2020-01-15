# Project 2
---

## Makefile and Testing

To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2

To run simple tests on each program you can execute

    make run_problem1
    make run_problem2

To run memory tests on each program you can execute

    make test_problem1
    make test_problem2

To remove all previously compiled and built files, run

    make clean


## Problem 1 (50 points)

This program performs basic operations on a binary search tree.
It reads a sequence of instructions from the standard input stream
and outputs the results to the standard output stream.

The program accepts the following instructions:

- `a value` and the `value` to the tree
- `s` remove the smallest value stored in the current tree (should have no effect
  if the current tree is empty)
- `l` remove the largest value stored in the current tree (should have no effect
  if the current tree is empty)
- `p` print the values stored in the current tree in order of the inorder traversal

The `main` function in `problem1.c` reads and parses the input stream and calls
appropriate functions to perform the instructions. __Your task is to implement
those functions so that the output produced is correct.__


__Example__

__Input:__
```
a park
a snow
a zoo
a car
a dinner
p
s
l
p
a crab
a rank
a herb
a rabbit
a sand
p
l
s
p
s
s
l
l
p
l
s
p
s
p
```

__Output:__
```
car dinner park snow zoo
dinner park snow
crab dinner herb park rabbit rank sand snow
dinner herb park rabbit rank sand
park rabbit


```
(notice that the last two lines of the output are blanks!).

## Problem 2 (50 points)


This program performs basic operations on floating point numbers to illustrate
how they are encoded using the IEEE754 standard.
It reads a sequence of floating point numbers from the standard input stream
and outputs the results to the standard output stream.
The input is terminated by a zero.


Recall the IEEE754 encoding for the floating point numbers represented using
32 bits (`float` type in C).

Your task is to _disassemble_ a floating point number into three separate components:
- `s` sign (either 1 or -1)
- `E` exponent
- `M` mantissa/significand

The floating point number should then be equal to the product of s * M * 2^(E).

The `main` function in `problem2.c` reads and parses the input stream and calls
appropriate functions to perform the _disassembly_. __My task is to implement
those functions so that the output produced is correct.__


__Example__

|__Input:__|__Output:__ |
|:---|:---|
|1024|1 10 1.00000000000000000000<br>1024.00000000000000000000000000000000000000000000000000|
|-1024|-1 10 1.00000000000000000000<br>-1024.00000000000000000000000000000000000000000000000000|
|1023|1 9 1.99804687500000000000<br>1023.00000000000000000000000000000000000000000000000000|
|1025|1 10 1.00097656250000000000<br>1025.00000000000000000000000000000000000000000000000000|
|0.1|1 -4 1.60000002384185791016<br>0.10000000149011611938476562500000000000000000000000|
|0.5|1 -1 1.00000000000000000000<br>0.50000000000000000000000000000000000000000000000000|
|8388608|1 23 1.00000000000000000000<br>8388608.00000000000000000000000000000000000000000000000000|
|8388609|1 23 1.00000011920928955078<br>8388609.00000000000000000000000000000000000000000000000000|
|33554432|1 25 1.00000000000000000000<br>33554432.00000000000000000000000000000000000000000000000000|
|33554432|1 25 1.00000000000000000000<br>33554432.00000000000000000000000000000000000000000000000000|
|1000000000000000.1|1 49 1.77635681629180908203<br>999999986991104.00000000000000000000000000000000000000000000000000|
|1e-40|1 -126 0.00850701332092285156<br>0.00000000000000000000000000000000000000009999946101|
|-1e-40|-1 -126 0.00850701332092285156<br>-0.00000000000000000000000000000000000000009999946101|
|nan|1 255 0.50000000000000000000<br>nan|
|-nan|-1 255 0.50000000000000000000<br>nan|
|inf|1 255 0.00000000000000000000<br>inf|
|-inf|-1 255 0.00000000000000000000<br>-inf|
|0| |


