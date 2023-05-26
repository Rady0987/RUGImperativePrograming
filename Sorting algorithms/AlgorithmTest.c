#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void swap(int i, int j, int arr[]) {
   int h = arr[i];
   arr[i] = arr[j];
   arr[j] = h;
}

void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

void shiftRight(int length, int arr[], int idx) {
   int i;
   for (i = length; i > idx; i--) {
      arr[i] = arr[i - 1];
   }
}
int searchIndex(int length, int arr[], int value) {
   int i = 0;
   while ((i < length) && (arr[i] <= value)) {
      i++;
   }
   return i;
}
void insert(int length, int arr[], int value) {
   int idx = searchIndex(length, arr, value);
   shiftRight(length, arr, idx);
   arr[idx] = value;
}
void insertionSort(int length, int arr[]) {
   int i;
   for (i = 1; i < length; i++) {
      insert(i, arr, arr[i]);
   }
}

int partition(int length, int arr[]) {
   int left = 0;
   int right = length;
   int pivot = arr[0];
   while (left < right) {
      while ((left < right) && (arr[left] <= pivot)) {
         left++;
      }
      while ((left < right) && (pivot < arr[right - 1])) {
         right--;
      }
      if (left < right) {
         swap(left, right - 1, arr);
      }
   }
   left--;
   arr[0] = arr[left];
   arr[left] = pivot;
   return left;
}

void quickSort(int length, int *arr) {
   if (length <= 1) {
      return; /* nothing to sort */
   }
   int boundary = partition(length, arr);
   quickSort(boundary, arr);
   quickSort(length - boundary - 1, &arr[boundary + 1]);
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

int* copyArray(int length, int arr[]) {
   int *copy = safeMalloc(length * sizeof(int));
   for(int i = 0; i < length; i++) {
      copy[i] = arr[i];
   }
   return copy;
}

int main(int argc, char *argv[]) {
   int n, arr[6] = {280000, 200000, 150000, 100000, 50000, 10000};
   int *cpy, *cpy1;
   FILE *fpt;

   fpt = fopen("results1.txt", "w+");

   for (int a = 0; a < 6; a++) {
      fprintf(fpt, "----------------\n");
      fprintf(fpt, "N is %d\n", arr[a]);
      fprintf(fpt, "----------------\n");

      n = arr[a];
      int array[n];

      for (int j = 0; j < 5; j++) {
         fprintf(fpt, "Iteration %d:\n", j);

         for (int i = 0; i < n; i++) {
            array[i] = rand();
         }

         cpy = copyArray(n, array);
         cpy1 = copyArray(n, array);

         clock_t begin = clock();
         insertionSort(n, cpy);
         clock_t end = clock();
         double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
         fprintf(fpt, "Insertion sort: %f\n", time_spent);

         clock_t begin1 = clock();
         mergeSort(n, cpy1);
         clock_t end1 = clock();
         double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
         fprintf(fpt, "Merger sort: %f\n", time_spent1);

         clock_t begin2 = clock();
         quickSort(n, array);
         clock_t end2 = clock();
         double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
         fprintf(fpt, "Quick sort: %f\n", time_spent2);
         fprintf(fpt, "\n");
         free(cpy);
         free(cpy1);
      }
   }
   fclose(fpt);
   return 0;
}
