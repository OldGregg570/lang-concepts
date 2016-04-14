#include<stdio.h>
#define COLOR_RED         "\x1b[31m"
#define COLOR_GREEN       "\x1b[32m"
#define COLOR_RESET       "\x1b[0m"
#define SUCCESS_STRING    COLOR_GREEN "All tests pass!\n" COLOR_RESET
#define ERROR_STRING      COLOR_RED "Error: %d asserton%c failed\n" COLOR_RESET
#define ASSERT_ERR_STRING COLOR_RED "Assertion Failure: %d == %d\n" COLOR_RESET

int assertIntEquals (int, int);

/**
 * Print an error message if left does not equal right
 */
int assertIntEquals (int left, int right) {
 if (left != right) {
  printf(ASSERT_ERR_STRING, left, right);
 }
 return left != right;
}
