/* file: crandom.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 3 Oct 2020 */
/* version: 1.0 */
/* Description: This program reads from the input the 
parameters X0, a, c, and m (in that order) of a pseudo random 
generator, and outputs the period of this generator */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* This function allocates memory to an array */
void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

/* This function initialize the histogram with -1 */
void initializeHist(int* arr, int length) {
   for (int i = 0; i < length; i++) {
      arr[i] = -1;
   }
}

/* This is the main function */
int main(int argc, char* argv[]) {
   int x0, a, c, m, *hist, *arr, i = 1;
   scanf("%d %d %d %d", &x0, &a, &c, &m);
   hist = safeMalloc(m * sizeof(int));
   arr = safeMalloc(m * sizeof(int));
   initializeHist(hist, m);
   arr[0] = x0;
   hist[x0] = 0;
   /* Iterate over numbers and compute Xi, adding 
   them in an array and saving their i in hist */
   while(true) {
      arr[i] = (a * arr[i - 1] + c) % m;
      /* If the hist[Xi] is not -1 then Xi has been encountered earlier */
      if(hist[arr[i]] != -1) {
         printf("%d\n", i - hist[arr[i]]);
         break;
      /* In case hist[Xi] = -1, then it saves the index of the first occurrence */
      } else {
         hist[arr[i]] = i;
      }
      i++;
   }
   free(arr);
   free(hist);
   return 0;
}