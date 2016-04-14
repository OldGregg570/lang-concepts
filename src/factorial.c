/**
 * 2. Factorial of n (given n is integral)
 */

#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

const int CORRECT_FACTORIALS[10] = {
  1,   1,    2,
  6,   24,   120,
  720, 5040, 40320,
  362880
};

int factorialIterative (int);
int factorialRecursive(int);

void main() {
  int i, failedAssertions = 0;

  printf("\n~~Factorial~~\n\n");

  for (i = 0; i < 10; i++) {
    // Compare the results the simple fibonacci functiton with the correct values
    failedAssertions += assertIntEquals(factorialIterative(i), CORRECT_FACTORIALS[i]);

    // Compare the results of the recursive fibonacci function with the correct values
    failedAssertions += assertIntEquals(factorialRecursive(i), CORRECT_FACTORIALS[i]);
  }

  if (0 == failedAssertions) {
    printf(SUCCESS_STRING);
    printf("0! to 10!:\n");
    for (i = 0; i < 10; i++) {
      printf("%d, ", factorialIterative(i));
    }

    printf("\n");
    exit(0);
  } else {
    printf(ERROR_STRING, failedAssertions, 1 == failedAssertions ? '\0' : 's');
    exit(1);
  }
}

/**
 * Compute n factorial iteratively
 */
int factorialIterative (int n) {
  int i, retVal = 1;

  for (i = 2; i <= n; i++) {
    retVal *= i;
  }
  return retVal;
}

/**
 * Compute n factorial recursively
 */
int factorialRecursive(int n) {
  if(n <= 1) {
    return 1;
  } else {
    return n * factorialRecursive(n - 1);
  }
}
