/* file: quadSum.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: THU OCT 10 2020 */
/* version: 1.0 */
/* Description: This program accepts on its input an integer n (where 1 ≤ n ≤ 1600), 
and outputs in how many different ways n can be expressed as a sum of squares of 
positive integers. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function calculates the number of ways a 
prositive integer can be written as a sum of squares*/
int quadSum(int i, int n) {
   int quad;
   /* The square for every recursive call*/
   quad = i * i;
   /* This base case ends a recursive branch if n - (new square) is a negative number*/
   if(n - quad < 0) 
      return 0;
   /* When we reach a brach that is equal to n, we return +1*/
   if(n - quad == 0) {
      return 1;
   } else {
   /* This part creates several branches and increments i */
      return quadSum(i + 1, n) + quadSum(i + 1, n - quad);
   }
}


int main(int argc, char* argv[]) {
   int n;
   scanf("%d", &n);
   printf("%d\n", quadSum(1, n));
   return 0;
}