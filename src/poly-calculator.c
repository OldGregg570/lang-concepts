/**
 * In C++ write a polynomial calculator to support the following
 *   var('x y z'); // this declares x,y,z to be variables as in algebra
 *   var('a',10); // this assigns a value to a variable
 *   poly f=2*x^3 + 3*x+10;
 *   poly g=x+1;
 *   poly h= f*g;
 *   poly j=a*x; // uses the variable with value a
 *   print f;
 *   print g;
 *   print h;
 *   print eval(f,x=10);
 *   print eval(h,x=5);
 *   poly u=2*(x+y)^2 + 3*x*y;
 *   poly v=f*u;
 *   print u;
 *   print v;
 *   print eval(u,x=5,y=6);
 *   print eval(u,x=6,y=5);
 *   quit;
 *
 * Please submit your C++ code as well as output of the above (when input
 * to your program). Use good C++ practices, and comments.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/hash-table.h"

void interpretProgram(char*);
void interpretLine(char*);
void interpretVarStatement(char*);

// Characters that can be between a command and its arguments
const char* DELIMITERS_COMMAND = " (";
static hashtable_t* gVariables;

void main() {
 gVariables = ht_create( 65536 );

 char programInput[] = "var('x y z');\nvar('a', 10)\nvar('b', 20)\nvar('c', 30)\nprint a\nquit";
 //hashtable_t* variables = ht_create( 65536 );

 printf("Polynomial Calculater\n-\n-\n");

 interpretProgram(programInput);

 // ht_set( hashtable, "key4", "floyd" );
 // printf( "%s\n", ht_get( hashtable, "key4" ) );

 exit(0);
}

void interpretProgram (char* programString) {
 char* currentLine = programString;

 while(currentLine) {
   char* nextLine = strchr(currentLine, '\n');

   // Temporarily null terminate
   if(nextLine) *nextLine = 0;

   // Interpret the line
   interpretLine(currentLine);

   // Replace the newline character
   if(nextLine) *nextLine = '\n';

   // Increment the current line pointer
   currentLine = nextLine ? (nextLine + 1) : NULL;
 }
}


void interpretLine (char* currentLine) {

 // Interpret the line based on the first token
 if (0 == strncmp(currentLine, "var", 3)) {
  interpretVarStatement(currentLine);

 } else if(0 == strncmp(currentLine, "print", 4)) {
  //interpretPrintStatement(currentLine);

 } else if(0 == strncmp(currentLine, "quit", 4)) {
  exit(0);

 } else {
  printf("Unexpected Token: %s\n", currentLine);
 }

 printf("\n===\n");
}


void interpretVarStatement(char* varStatment) {
 const char* DELIMITERS = "()' ;";
 char* varName;
 int hasAssignment = 1;
 //printf("%s", );

 // Returns the command name ('var')
 char* currentToken = strtok(strchr(varStatment, '('), DELIMITERS);

 printf("%s\n", currentToken);

 // For each token in the current line on the left hand side of the expression
 while(currentToken != NULL && hasAssignment) {
   hasAssignment = strncmp(currentToken, ",", 1);
   currentToken = strtok(NULL, DELIMITERS);

   printf("%s\n", currentToken);
 }

 printf("HAS: %d", hasAssignment);
 // For each token in the current line on the right hand side of the expression
}
