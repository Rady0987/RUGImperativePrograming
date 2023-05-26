/* file:    dimenPoints.c */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    23.10.2020 */
/* version: 1.0 */
/* Description: This program prints on
the output how many times a given point p occurs in this series */

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

/* This function allocates memory to a 2D array */
int **makeIntArray2D(int height, int width) { 
	int row, **matrix;
	matrix = safeMalloc(height * sizeof(int *)); 
	for(row = 0; row < height; row++) {
		matrix[row] = safeMalloc(width * sizeof(int));
	}
	return matrix;
}

/* This function reads an int 2D array */
void read2DArray(int **matrix, int height, int width){
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			scanf("%d", &matrix[i][j]); 
         if (j == 8) 
				getchar();
      }
   }		
}

/* This function reads an int array */
void readInput(int *arr, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
}

/* This function frees the memory of a 2D array */
void destroyIntArray2D(int **arr, int height) { 
	for(int i = 0; i < height; i++) {
		free(arr[i]); 
	}
	free(arr);
}

/* This function counts for how many times the point p occurs in the series*/
int search(int **matrix, int *arr, int height, int width) {
	int count, rez = 0;
	/* Iterate over first number of each matrix column 
	and check for similarities */
   for(int i = 0; i < width; i++) {
      if(matrix[0][i] == arr[0]) {
			count = 1;
			/* Check the rest numbers of the column */
         while(count < height) {
				if(matrix[count][i] == arr[count]){
					count++;
				} else {
					break;
				}
			}
			/* In case the last number from a row is reached */
			if(count == height)
				rez++;
      }
   }
	return rez;
}

/* The main function */
int main(int argc, char* argv[]) {
   int *arr, n, k, **matrix;
   scanf("%d %d", &n, &k);
   matrix = makeIntArray2D(n, k);
   arr = safeMalloc(n * sizeof(int));
   read2DArray(matrix, n, k);
   readInput(arr, n);
	printf("%d\n", search(matrix, arr, n, k));
   destroyIntArray2D(matrix, n);
   free(arr);
   return 0;
}