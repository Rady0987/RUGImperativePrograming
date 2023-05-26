/* file: remOccurrences.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 2020 */
/* version: 1.0 */
/* Description: This program outputs  */

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

/* This function reads the numbers of the array */
void readList(int* list, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &list[i]);
      getchar(); 
   }
}

int maxElement(int *arr, int n) {
   int max = arr[0];
   for(int i = 1; i < n; i++) {
      if(arr[i] > arr[0])
         max = arr[i];
   }
   return max;
}

/* This function initialize the histogram with -1 */
void initializeHist(int* arr, int length) {
   for (int i = 0; i < length; i++) {
      arr[i] = 0;
   }
}

void printArray(int *arr, int n) {
   printf("%d", arr[0]);
   for(int i = 1; i < n; i++) {
      printf(",%d", arr[i]);
   }
   printf("\n");
}

int main(int argc, char* argv[]) {
   int n, k, *arr, *histogram, histLength, count = 0;
   scanf("%d %d:", &n, &k);
   int finalArr[n];
   //finalArr = safeMalloc(sizeof(int));
   arr = safeMalloc(n * sizeof(int));
   readList(arr, n);
   //printArray(arr, n);
   histLength = maxElement(arr, n) + 1;
   histogram = safeMalloc(histLength * sizeof(int));
   initializeHist(histogram, histLength);
   for(int i = 0; i < n; i++) {
      histogram[arr[i]]++;
   }
   //printArray(histogram, histLength);
   for(int i = 0; i < n; i++) {
      if(histogram[arr[i]] < k && histogram[arr[i]] != 0) {
         //printf("%d, ", arr[i]);
         finalArr[count] = arr[i];
         count++;
      }
   }
   printArray(finalArr, count);
   free(arr);
   free(histogram);
   return 0;
}