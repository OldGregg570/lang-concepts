/**
 * 1. In C/C++ write a Fibonacci Encoder, which converts a given number
 *    into a sequence of Fibonacci numbers’s index [Hint: consider the examples
 *    given below]
 *
 *  Example 1:
 *    Fib enc of 1987 is 1597 (@ 17) (remaining) 390
 *    Fib enc of 390 is 377 (@ 14) (remaining) 13
 *    Fib enc of 13 is 13 (@ 7) (remaining) 0
 *    Fib enc of 1987 = [17,14,7]
 *
 *  Example 2:
 *    Fib enc of 6543 is 4181 (@ 19) (remaining) 2362
 *    Fib enc of 2362 is 1597 (@ 17) (remaining) 765
 *    Fib enc of 765 is 610 (@ 15) (remaining) 155
 *    Fib enc of 155 is 144 (@ 12) (remaining) 11
 *    Fib enc of 11 is 8 (@ 6) (remaining) 3
 *    Fib enc of 3 is 3 (@ 4) (remaining) 0
 *    Fib enc of 6543 = [19,17,15,12,6,4]
 *
 *    Submit your code as well as output of encoding for your student number,
 *    the square of your student number and the cube of your student number.
 *    Please include the output of your code verbatim in the PRINT OUT.
 */

#include<stdio.h>
#include<stdlib.h>
#include"../include/fibonacci.h"

void main() {
  printf("Fibonacci Encoder\n\n");

  unsigned int inputNumber = 482259191688;
  unsigned int fibonacciNumbers[128] = { 0, 1, 1, 2, 3, 5 };
  unsigned int encoded[128] = { 0 };
  unsigned int n = 0;
  unsigned int i;
  unsigned int encodingIndex = 0;
  unsigned int currentNumber = inputNumber;
  unsigned int difference;
  unsigned int previousFibonacci;
  unsigned int len;

  if (0 == inputNumber) {
   printf("Fib enc of 0 is 0");
   exit(0);
  }

  // Repeat until the remainder is zero
  do {

    // Repeat until we have all of the fibonacci values we need
    do {
     n++;

     // Keep track of fibonacci values that have already been computed
     if (!fibonacciNumbers[n]) {
      fibonacciNumbers[n] = fibonacci(n);
     }
    } while (fibonacciNumbers[n] <= currentNumber);

    // Print out the string like above
    previousFibonacci = fibonacciNumbers[n - 1];
    difference = currentNumber - fibonacciNumbers[n - 1];
    printf("Fib enc of %d is %d (@ %d) (remaining) %d\n", currentNumber, previousFibonacci, n - 1, difference);

    encoded[encodingIndex] = n - 1;

    // Pick the closes fibonacci number below our current number
    currentNumber = currentNumber - previousFibonacci;
    n = 0;

    encodingIndex++;
  } while(currentNumber > 0);

  // Print the encoded comma separated list of integers
  for (i = 0; i < encodingIndex; i++) {
      printf("%d%c", encoded[i], i != len ? ',' : 0);
  }

  exit(0);
}
