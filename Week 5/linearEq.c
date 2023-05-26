/* file: quadSum.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: THU OCT 10 2020 */
/* version: 1.0 */
/* Description: This program accepts on its input an integer n (where 1 ≤ n ≤ 1600), 
and outputs in how many different ways n can be expressed as a sum of squares of 
positive integers. */

#include <stdio.h>
#include <stdlib.h>

/* This function allocates memory to an array */
void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

/* This function reads an int array */
void readInput(int *arr, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
}

/* This function checks recursively how many combinations of coefficients are equal to b*/
int checkCoeff(int* arr, int start, int n, int b) {
   int combinations = 0;
   /* The base case for the moments when a recursive brach reached a satisfiable result */
   if(b == 0)
      return 1;
   /* The idea is to subtract each coefficient as much as we can by calling the function
   recursively with the indexes fixed on that number*/
   for(int i = start; i <= n; i++) {
      if(arr[i] <= b)
         combinations += checkCoeff(arr, start, i, b - arr[i]);
   }
   return combinations;
}

/* The main function */
int main(int argc, char* argb[]) { 
   int n, *coeff, b;
   scanf("%d:", &n);
   coeff = safeMalloc(n * sizeof(int));
   readInput(coeff, n);
   scanf("%d", &b);
   n--;
   printf("%d\n", checkCoeff(coeff, 0, n,  b));
   free(coeff);
   return 0;
}