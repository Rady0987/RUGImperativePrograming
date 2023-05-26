/* file:    recurence.c              */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    18.10.2020               */
/* version: 1.0                */
/* Description: This program reads from the input a 
positive integer n and outputs Cn. */

#include <stdlib.h>
#include <stdio.h>

/* This function computes the recurence */
int recurrence(int n) {
   int a = 0, b = 2, c;
   for(int i = 2; i <= n; i++) {
      /* Recurence formula */
      c = 4 * b - a;
      /* Swap past values */
      a = b;
      b = c;
   }
   return c;
}

int main(int argc, char* argv[]) {
   int n;
   scanf("%d: ", &n);
   printf("%d\n", recurrence(n));
   return 0;
}