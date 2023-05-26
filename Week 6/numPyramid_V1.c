/* file:    numPyramid.c              */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    18.10.2020               */
/* version: 1.0                */
/* Description: This program outputs YES if it is possible to construct a number
pyramid from the input array, and NO otherwise. */

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

int* copySubArray(int left, int right, int arr[]) {
   int length = right - left;
   int *copy = safeMalloc(length * sizeof(int));
   for(int i = 0; i < length; i++) {
      copy[i] = arr[i + left];
   }
   return copy;
}

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

/* This function recursively sorts the input array using Divide and Conquer algorithm */
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

/* This function counts how many sequences(layers) there are in the array */
int countLayers(int *arr, int n) {
   int counter = 1;
   for(int i = 0; i < n - 1; i++) {
      if(arr[i] < arr[i + 1])
         counter++;
   }
   return counter;
}

/* This function counts how many number are in every sequence and puts 
the results in "layers" array*/
void numbersOnLayer(int *arr, int *layers, int n) {
   int counter = 0, j = 0;
   for(int i = 0; i < n - 1; i++) {
      counter++;
      if(arr[i] != arr[i + 1]) {
         layers[j] = counter;
         j++;
         counter = 0;
      }
   }
   layers[j] = counter + 1;
}

/* This function checks if it is possible to construct a number pyramid 
from the input array */
void checkLayers(int *layers, int n) {
   int sum = layers[0];
   for(int i = 1; i < n; i++) {
      if(layers[i] <= sum) {
         printf("NO\n");
         return;
      }
      sum += layers[i];
   }
   printf("YES\n");
}

int main(int argc, char* argv[]) {
   int n, *arr, *layers, nrLayers;
   scanf("%d: ", &n);
   arr = safeMalloc(n * sizeof(int));
   readInput(arr, n);
   /* Sort the input array */
   mergeSort(n, arr);
   nrLayers = countLayers(arr, n);
   layers = safeMalloc(nrLayers * sizeof(int));
   numbersOnLayer(arr, layers, n);
   /* Sort the array with layers */
   mergeSort(nrLayers, layers);
   checkLayers(layers, nrLayers);
/* Free the dynamically allocated memory */
   free(layers);
   free(arr);
   return 0;
}
