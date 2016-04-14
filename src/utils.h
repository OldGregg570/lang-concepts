#include<stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define SUCCESS_STRING     ANSI_COLOR_GREEN "All tests pass!\n" ANSI_COLOR_RESET
#define ERROR_STRING       ANSI_COLOR_RED "Error: %d asserton%c failed\n" ANSI_COLOR_RESET

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
