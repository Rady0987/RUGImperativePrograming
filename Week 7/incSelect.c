/* file:    incSelect.c */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    26.10.2020 */
/* version: 1.0 */
/* Description: This program  */

#include <stdlib.h>
#include <stdio.h>

/* This function allocates memory to an arr */
void *safeMalloc(int n) {
   void *p = malloc(n);
   if(p == NULL) {
      printf("Error: malloc(%d) failed. Out of memory?\n", n);
      exit(EXIT_FAILURE);
   }
   return p;
}

/* This function reads an int arr */
void readInput(int *arr, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
}

/* This function makes a subArray */
int* copySubArray(int left, int right, int arr[]) {
   int length = right - left;
   int *copy = safeMalloc(length * sizeof(int));
   for(int i = 0; i < length; i++) {
      copy[i] = arr[i + left];
   }
   return copy;
}

/* This function merges and sorts two arrays */
void merge(int lenA, int a[], int lenB, int b[], int arr[]) {
   int idx=0, l=0, r=0;
   while ((l != lenA) && (r != lenB)) {
   if(a[l] <= b[r]) {
      arr[idx] = a[l];
      l++;
   } else {
      arr[idx] = b[r];
      r++;
   }
   idx++;
   }
/* process trailing elements: either l==lenA or r==lenB */
   while(l != lenA) {
      arr[idx] = a[l];
      idx++;
      l++;
   }
   while(r != lenB) {
      arr[idx] = b[r];
      idx++;
      r++;
   }
}

/* This function recursively sorts the input arr using Divide and Conquer algorithm */
void mergeSort(int length, int arr[]) {
   /* Base case */
   if(length <= 1) { 
      return;
   }
/* Recursive case: length >= 2, so 0 < length/2 < length */
   int mid = length / 2;
/* Make two subarrays (DIVIDE) and sort recursively*/
   int *left = copySubArray(0, mid, arr);
   mergeSort(mid, left);
   int *right = copySubArray(mid, length, arr);
   mergeSort(length - mid, right);
   /* Merge sorted arrays (CONQUER) */
   merge(mid, left, length - mid, right, arr);
   free(right);
   free(left);
}

// This function counts the length of the longest sequence */
int countWays(int *arr, int n) {
	int counter = 1, maxCounter = 0, resultingCounter = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) { // If the arr element is smaller than the next element, count.
			counter++;
			maxCounter = counter; // We copy the biggest counter till the if condition is not met.
		} else {
			if (resultingCounter < maxCounter) { // Keeping track of the biggest value maxCounter has achieved till current iteration.
				resultingCounter = maxCounter;
			}
			counter = 1;
		}
	}
	if (maxCounter == 0) 
      return counter; // If we do not have any consecutive integers (we have only the same integer repeated n times)
	if (resultingCounter > maxCounter) return resultingCounter; // maxCounter may have changed, when we have a second sequence.
	return maxCounter;
}

int main(int argc, char *argv[]) {
	int *arr, n;
	scanf("%d", &n);
	arr = safeMalloc(n * sizeof(int));
	readArr(arr, n);
	mergeSort(n, arr);
	printf("%d\n",countWays(arr, n));
	return 0;
}

