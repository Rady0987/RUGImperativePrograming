/* file: arrayreduct.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 5 Oct 2020 */
/* version: 1.0 */
/* Description: This program outputs the number of elements in the
maximally reduced array. */

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
   }
}

/* This function finds the index of the maximal element in the array */
int maxValueIndex(int* arr, int length) {
   int maxIndex = 0;
   for (int i = 1; i < length; i++) { 
      if (arr[i] > arr[maxIndex])
         maxIndex = i;
   }
   return maxIndex;
}

/* This function computes the sum of the elements */
int elementsSum(int* arr, int length) {
   int listSum = 0;
   for (int i = 0; i < length; i++) {
      listSum += arr[i];
   }
   return listSum;
}

int main(int argc, char* argv[]) {
   int n, *list, count, maxIndex, listSum;
   scanf("%d:", &n);
   getchar();
   list = safeMalloc(n * sizeof(int));
   readList(list, n);
   count = n;
   /* As long as the number of the element is > 0, it executes the operations */
   while (count > 0) {
      /* Sum of the elements and the index of the max element is 
      calculated every iteration*/
      maxIndex = maxValueIndex(list, n);
      listSum = elementsSum(list, n);
      /* If the result of this subtraction is equal to the max element, 
      then it assigns 0 to it*/
      if (listSum - list[maxIndex] == list[maxIndex]) {
         list[maxIndex] = 0;
         count--;
      /* If there are no more number to satisfy the condition, the loop breaks*/
      } else {
         break;
      }
   }
   printf("%d\n", count);
   free(list);
   return 0;
}