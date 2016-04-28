#include<stdio.h>
#define COLOR_RED         "\x1b[31m"
#define COLOR_GREEN       "\x1b[32m"
#define COLOR_RESET       "\x1b[0m"
#define SUCCESS_STRING    COLOR_GREEN "All tests pass!\n" COLOR_RESET
#define ERROR_STRING      COLOR_RED "Error: %d asserton%c failed\n" COLOR_RESET
#define ASSERT_ERR_STRING COLOR_RED "Assertion Failure: %d == %d\n" COLOR_RESET

/**
 * Print an error message if left does not equal right
 */
int assertIntEquals (int left, int right) {
 if (left != right) {
  printf(ASSERT_ERR_STRING, left, right);
 }
 return left != right;
}

/**
 * If any assertions failed, print an error message and return 1
 * If all assertions pass, print out the output of running the provided function argument with
 * the values 0 through 10, and return 0
 */
int printTestReport(int failedAssertions, int (*fn)(), char* message) {
 int i = 0;

 if (0 == failedAssertions) {
   printf(SUCCESS_STRING);
   printf(message);
   for (i = 0; i < 10; i++) {
     printf("%d, ", fn(i));
   }

   printf("\n");
   return 0;
 } else {
   printf(ERROR_STRING, failedAssertions, 1 == failedAssertions ? '\0' : 's');
   return 1;
 }
}
