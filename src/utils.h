#include<stdio.h>

void assertIntEquals (int, int);

/**
 * Print an error message if left does not equal right
 */
void assertIntEquals (int left, int right) {
 if (left != right) printf("Assertion Failure: %d == %d\n", left, right);
}
