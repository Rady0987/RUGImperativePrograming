/* file:    filterSum.c              */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    18.10.2020               */
/* version: 1.0                */
/* Description: This program outputs the sum of the
numbers on the second line that also occur in the series 
given in the first line.*/

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

/* This function search binary in an array */
int binarySearch(int length, int a[], int target) { 
   int left = 0;
   int right = length; 
   /* Loop until the indexes aren't the same */
   while (left < right - 1) { //until the indexes aren't the same
      int mid = (left + right) / 2; 
      /* If the target is smaller than the middle */
      if (target < a[mid]) { 
         /* Middle is assgined to the right bound */
         right = mid; 
      } else {
         /* Middle is assgined to the left bound */
         left = mid; 
      }
   }
   /* The case when the target is found */
   if ((left < length) && (a[left] == target)) { 
      return 1;
   }
   return 0;
}

/* The main function */
int main(int argc, char* argv[]) {
   int n, *arr, num, sum = 0;
   scanf("%d: ", &n);
   arr = safeMalloc(n * sizeof(int));
   readInput(arr, n);
   /* Scan every number until 0 and check using 
   binary search if it occurs in the read array */
   do {
      scanf("%d", &num);
      if(binarySearch(n, arr, num))
         sum += num;
   } while(num != 0);
   printf("%d\n", sum);
   free(arr);
   return 0;
}