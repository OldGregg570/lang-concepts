/**
 * 3. Calculate the number of times Collatz function is called for n, before n=1
 */

#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

const int CORRECT_COLLATZ[20] = {
 0,  0,  1,  7,  2,
 5,  8,  16, 3,  19,
 6,  14, 9,  9,  17,
 17, 4,  12, 20, 20
};

int collatzCountIterative(int);

void main() {
  int i, failedAssertions = 0;

  printf("\n~~Collatz~~\n\n");

  for (i = 0; i < 20; i++) {
    // Compare the results the simple collatz functiton with the correct values
    failedAssertions += assertIntEquals(collatzCountIterative(i), CORRECT_COLLATZ[i]);
  }

  if (0 == failedAssertions) {
    printf(SUCCESS_STRING);
    printf("Collatz sequence lengths from 0 to 20:\n");
    for (i = 0; i < 20; i++) {
      printf("%d, ", collatzCountIterative(i));
    }

    printf("\n");
    exit(0);
  } else {
    printf(ERROR_STRING, failedAssertions, 1 == failedAssertions ? '\0' : 's');
    exit(1);
  }
}

/**
 * Compute number of times collatz function is called iteratively
 */
int collatzCountIterative (int n) {
  int count = 0;

  while (n > 1) {
    if(n % 2 == 0) {
      n /= 2;
    } else {
      n = (3 * n) + 1;
    }
    count++;
  }

  return count;
}
