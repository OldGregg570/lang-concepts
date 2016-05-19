/**
 * Compute fibonacci numbers
 */

#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

const int CORRECT_FIBS[20] = {
  0,   1,   1,    2,    3,
  5,   8,   13,   21,   34,
  55,  89,  144,  233,  377,
  610, 987, 1597, 2584, 4181
};

int fibonacci(int);
int fibonacciIterative (int);
int fibonacciRecursive(int);

void fibonacci_test();

/**
 * Return the nth fibonacci number
 */
int fibonacci (int n) {
 return fibonacciIterative(n);
}

/**
 * Return the nth fibonacci number iteratively
 */
int fibonacciIterative (int n) {
  int current = n == 0 ? 0 : 1,
      previous = 1,
      next,
      i;

  for (i = 2; i < n; i++) {
    next = current + previous;
    previous = current;
    current = next;
  }
  return current;
}

/**
 * Compute the nth fibonacci value using recursion
 */
int fibonacciRecursive (int n) {
  // Call recursive function with initial parameters
  return _fibonacciRecursive(n, 1, 0);
}
int _fibonacciRecursive (int n, int current, int previous) {
  if(n == 0) return previous;
  if(n == 1) return current;
  return _fibonacciRecursive(n - 1, current + previous, current);
}

void fibonacci_test() {
  int i, failedAssertions = 0;

  printf("\n~~Fibonacci~~\n\n");

  for (i = 0; i < 20; i++) {
    // Compare the results the simple fibonacci functiton with the correct values
    failedAssertions += assertIntEquals(fibonacciIterative(i), CORRECT_FIBS[i]);

    // Compare the results of the recursive fibonacci function with the correct values
    failedAssertions += assertIntEquals(fibonacciRecursive(i), CORRECT_FIBS[i]);
  }

  // Compare the results of the fibonacci functions with one another
  for (i = 0; i < 50; i++) {
    failedAssertions += assertIntEquals(fibonacciIterative(i), fibonacciRecursive(i));
  }

  exit(printTestReport(failedAssertions, &fibonacciIterative, "Fibonacci sequence from 0 to 10:\n"));
}
