# Project 1

__Due date: Sunday, March 10 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

## Makefile and Testing

The `Makefile` provided with this project compiles and builds all of the required programs. __Your code will be compiled using this `Makefile` by the graders and it is your responsibility to make sure that your code can be compiled successfully on `crackle1`!__

To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2
    ...

To run simple tests on each program you can execute

    ./problem1 < test1.in
    ./problem2 < test2.in
    ...
(You should test your code much more extensively than these simple test cases provided with the assignment do.)

To remove all previously compiled and built files, run

    make clean

## Building and compiling with multiple files.

Majority of the programs you write consist of more than a single file. The organization of
programs with multiple files in C follows somewhat different rules than in Java.

In general the goal is to separate declaration of functions and definitions of functions.
The declarations are written in the header files (the ones with a .h extension) and the corresponding
definitions are provided in the source code files (the ones with a .c extension).

In order to create an actual program we need to make sure that the compiler proper
knows about the locations of the header files and that the linker knows where the
definitions are. This requires something called _separate compilation_. You can find a detailed tutorial
on the topic at
_[A Tutorial on Separate Compilation in C/C++](http://www.compsci.hunter.cuny.edu/~sweiss/resources/separateCompilation.pdf)_ by Stewart Weiss or any C programming textbook.

For the purpose of this assignment here are a few facts you need to know about.

- All function declarations are provided for you in the header files. You should add to those files
declarations for any other functions that you create.

- The content of the header file is surrounded by header guards. These are preprocessor
directives that prevent the declarations to be included multiple times within a single program
(this confuses the linker). Here is an example of a header guard:

    #ifndef FILENAME_H
    #define FILENAME_H
      //content of the file  
    #endif

- There are a few ways to compile your programs (although you should just use the
  provided `Makefile` to do so). Assume that the program consists of three source code
  files `f1.c`, `f2.c` and `main.c` and two header files `f1.h` and `f2.h`.
    - Compile everything together (not a good idea if you have a lot of code):

          gcc f1.c f2.c main.c -o progname

    - Compile each file separately and combine them into a sinlge program (this way
      if changes are made to the source code of one file, only that one file needs to
      be recompiled):

          gcc -c f1.c
          gcc -c f2.c
          gcc -c main.c
      (this produced three object files called `f1.o`, `f2.o` and `main.o`)

          gcc f1.o f2.o main.o -o progname

- __Dos and don'ts__ of separate compilation
    - NEVER use the `#include` directive to include a file with the `.c` extension.
    You should include the corresponding header file instead.
    - NEVER include the list of the header files when compiling the code using
    `gcc`. The header files are brought in by the preprocessor when it scans your code.

    



## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates. (Although in this project, there should not be a need to allocate any memory. )
- __The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.__
- The code has to build correctly using the provided `Makefile`.
- The code has to follow C programming conventions.
- The code has to be formatted properly.  

In addition, __you are required to make at least 5 commits to your repository.__ Each time you make a significant change/improvement to your solutions, you should commit and push the changes to the remote repository. This way, if there are any problems with your local copy of the files, you have a recent version of the code available.
Your commits should be distributed over time - they should not be all made within an hour before the due date.



## Problem 1 (50 points)


__Input__

__Output__


__Example__

Input:

Output:



__Deliverables__
Implementation of the program in `problem1.c` file.





## Problem 2 (50 points)


Recall the IEEE754-like encoding for the floating point numbers represented using.

Your task is to _disassemble_ a floating point number into three separate components:
- sign
- exponent
- mantissa/significand

Your program should read floating point numbers from the standard input stream.
The program should store each of them as a `float` (not as a `double`).
The program should print the three components into which each of those numbers is _disassembled_
with a single space between each.
Notice that the sign and the exponent are always going to be integers: (1 or -1 for
the sign). The mantissa should be printed as a floating point number with exactly 10 digits
after the decimal.






__Input__

A sequence of floating point numbers terminated by 0.0. The output for 0.0 should not be displayed.

__Output__

Three values into which the values are decomposed into with a single space in between the values.

__Example__

Input:



Output:





__Deliverables__
Implementation of the program in `problem2.c` file.


__Restrictions__

Your program is not allowed to use ANY of the functions defined in the `math.h` header file.
Specifically, it is not allowed to use the `pow()` functions to compute values of powers of 2.




__Deliverables__
Implementation of the program in `problem3.c` file.
