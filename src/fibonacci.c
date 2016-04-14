/**
 * LAB1 (Due 04/13/2016)
 *   1. nth Fibonacci number
 */

#include<stdio.h>
#include "utils.h"

const int CORRECT_FIBS[20] = {
   1,    1,    2,    3,    5,
   8,   13,   21,   34,   55,
  89,  144,  233,  377,  610,
 987, 1597, 2584, 4181, 6765
};

int fibonacciSimple (int);
int fibonacciRecursive(int, int, int);

void main() {
  int i = 0;

  for (i = 0; i < 20; i++) {
   // Compare the results the simple fibonacci functiton with the correct values
    assertIntEquals(fibonacciSimple(i), CORRECT_FIBS[i]);

    // Compare the results of the recursive fibonacci function with the correct values
    assertIntEquals(fibRecursive(i), CORRECT_FIBS[i]);
  }

  // Compare the results of the fibonacci functions with oneanother
  for (i = 0; i < 10000; i++) {
    assertIntEquals(fibonacciSimple(i), fibRecursive(i));
  }
}

/**
 * Return the nth fibonacci number
 */
int fibonacciSimple (int n) {
  int current = 1,
      previous = 1,
      next,
      i;

  for (i = 1; i < n; i++) {
    next = current + previous;
    previous = current;
    current = next;
  }
  return current;
}

/**
 * Compute the nth fibonacci value using recursion
 */
int fibRecursive(int n) {
  // Call recursive function with initial parameters
  return _fibRecursive(n, 1, 1);
}
int _fibRecursive (int n, int current, int previous) {
 if(n == 0) return previous;
 if(n == 1) return current;
 return _fibRecursive(n - 1, current + previous, current);
}
