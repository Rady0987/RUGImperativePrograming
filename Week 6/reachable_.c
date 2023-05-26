/* file:    reachable?.c */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    18.10.2020 */
/* version: 1.0 */
/* Description: This program outputs YES if you are able to 
reach the last index according to the maximum jump length 
at each position, otherwise it should output NO */

#include <stdlib.h>
#include <stdio.h>

/* This function allocates memory to an array */
void *safeMalloc(int n) {
   void *p = malloc(n);
   if(p == NULL) {
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

/* This function checks if it is possible 
to reach the last index of a particular array*/
void reachable(int *arr, int n, int jump, int i) {
   int max = 0, maxIndex = 0;
   /* The first base case, when you get in a position 
   with no more jumps, return 0*/
   if(i != n - 1 && jump == 0) {
      printf("NO\n");
      return;
   }
   /* The second base case, when you get at he last index */
   if(i >= n - 1 || max > n) {
      printf("YES\n");
      return;
   }
   /* At every recursive level we look for the position 
   with the greatest jump possibility starting from the 
   next position of the current one*/
   for(int j = i + 1; j <= i + jump; j++) {
      if(j + arr[j] > max) {
         max = arr[j] + j;
         maxIndex = j;
      }
   }
   /* Recursive call with the index of the position which has 
   the best jump */
   reachable(arr, n, arr[maxIndex], maxIndex);
}

int main(int argc, char* argv[]) {
   int n, *arr;
   scanf("%d: ", &n);
   arr = safeMalloc(n * sizeof(int));
   readInput(arr, n);
   reachable(arr, n, arr[0], 0);
   free(arr);
   return 0;
}