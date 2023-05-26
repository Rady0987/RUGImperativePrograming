/* file: mtrans.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: SUN OCT 6 2019 */
/* version: 1.0 */
/* Description: This program reads from the input a 2D matrix, and outputs its transpose. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *safeMalloc(int n) {//allocates memory for an array
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

int **makeIntArray2D(int width, int height) { //allocates memory for the 2D array
	int row, **matrix;
	matrix = safeMalloc(height*sizeof(int *)); //for the collomns of the array
	for (row=0; row < height; row++) {
		matrix[row] = safeMalloc(width*sizeof(int));// for each row
	}
	return matrix; //returns the made array
}

void readArray(int **matrix, int x, int y){ //reads the imput
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			scanf("%d", &matrix[i][j]); //includes all the values in the matrix[i][j]
			getchar();
		}
		getchar();
		getchar();
	}
}

void flip(int **dest, int **src, int x, int y){ //flips the intial 2D matrix
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			dest[i][j]=src[j][i]; //sets the source array elements to the destination one by inversing the way i,j increase
		}
	}
}

void printArray(int **matrix, int x, int y){ //prints the array
	printf("%dx%d:{{",y,x); //the dimensions
	for(int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			printf("%d", matrix[i][j]);// the elements 
			if (j < (x - 1)){ //prints ',' after every element if it is not the last from the row
				printf(",");
			}
			if (j == (x - 1) && i < (y - 1)){ // prints '},{' if the last element from the row, but not the last colomn
				printf("},{");
			}		
		}
	}
	printf("}}"); //prints the last '}}'
	printf("\n");
}

void destroyIntArray2D(int **arr, int x) { // frees the memory
	for (int i=0; i<x; i++){
		free(arr[i]); // the lines
	}
	free(arr); // the colomn
}

int main(int argc, char *argv[]) { 
	int x, y;
	int **matrix, **flippedMatrix; //arrays
	scanf("%dx%d:{{", &x, &y); //scans the initial dimensions
	matrix=makeIntArray2D(y,x);
	readArray(matrix, x,y);
	flippedMatrix=makeIntArray2D(x,y);
	flip(flippedMatrix, matrix, x, y);
	printArray(flippedMatrix, x, y);
	destroyIntArray2D(matrix, x);
	destroyIntArray2D(flippedMatrix, y);
	return 0;
}
