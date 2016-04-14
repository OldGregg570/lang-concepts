#include<stdio.h>
#include<stdlib.h>

int assertIntEquals (int, int);

/**
 * Print an error message if left does not equal right
 */
int assertIntEquals (int left, int right) {
 if (left != right) {
  printf("Assertion Failure: %d == %d\n", left, right);
 }
 return left != right;
}
