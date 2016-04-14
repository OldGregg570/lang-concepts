# lang-concepts
Programming Language Concepts labs and assignments

# Lab 1 (Due 04/13/2016)
Write C/C++ code to compute
  1. nth Fibonacci number
  2. Factorial of n (given n is integral)

  The table for Fib and Fac is given in the course material page.

  3. Calculate the number of times Collatz function is called for n, before n=1 Collatz function is defined in the notes as C(n) = n/2 for n even, and 3n+1 when n is odd. For every n (by the Collatz conjecture), C(n) approaches 1 eventually.

  Please test your code on some numbers to make sure there are no trivial bugs.

# Usage

```
$ make all
$ make run
```

## Expected Output:

```
$ make run
./bin/fibonacci

~~Fibonacci~~

All tests pass!
Fibonacci sequence from 0 to 20:
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
./bin/factorial

~~Factorial~~

All tests pass!
0! to 10!:
1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
./bin/collatz

~~Collatz~~

All tests pass!
Collatz sequence lengths from 0 to 20:
0, 0, 1, 7, 2, 5, 8, 16, 3, 19, 6, 14, 9, 9, 17, 17, 4, 12, 20, 20,

```
