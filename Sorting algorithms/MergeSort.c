#include <stdio.h>
#include <stdlib.h> 

void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
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

int main(int argc, char *argv[]){

   return 0;
}
