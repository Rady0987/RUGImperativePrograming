#include <stdio.h>
#include <stdlib.h> 

void swap(int i, int j, int arr[]) {
   int h = arr[i];
   arr[i] = arr[j];
   arr[j] = h;
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
         /* (arr[left] > pivot) && (arr[right-1] <= pivot) : swap */
         swap(left, right - 1, arr);
      }
   }
   /* put pivot in right location: swap(0,left-1,arr) */
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

int main(int argc, char *argv[]){
   int n = 10;
   int array[10] = {2, 4, 11, 4, 5, 2, 4, 22, 1000, 0};
   for (int i = 0; i < n; i++) {
      printf("%d, ", array[i]);
   }
   quickSort(n, array);
   printf("-------------\n");
   for (int i = 0; i < n; i++) {
      printf("%d, ", array[i]);
   }
   return 0;
}
