/* file:    submatrix.c */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    26.10.2020 */
/* version: 1.0 */
/* Description: This program  */

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

/* This function frees the memory of a 2D array */
void destroyIntArray2D(int **arr, int height) { 
	for(int i = 0; i < height; i++) {
		free(arr[i]); 
	}
	free(arr);
}

/* This function counts the occurances of the submatrix */
int search(int **matrix, int **subMatrix, int m, int n, int a, int b) {
   int rez = 0, startIndex, startRow, flag = 0, t, j;
   if(a >= 1 && a <= m && b >= 1 && b <= n) {
      /* Iterate over every row of the main matrix */
      for(int i = 0; i < m; i++) {
         /* Save the row number for future iterations and 
         search for the element[0][0] of the sub matrix */
         startRow = i;
         for(startIndex = 0; startIndex < n; startIndex++) {
            if(m - startRow >= a && n - startIndex >= b) {
               int c = startIndex;
               for(j = 0; j < a; j++) {
                  for(t = 0; t < b; t++) {
                     if(matrix[startRow][c] == subMatrix[j][t]) {
                        c++;
                     } else {
                        /* In case numbers are not ==, break and go to next row*/
                        flag = 1;
                        break;
                     } 
                  }
                  /* Break the second loop */
                  if(flag == 1) {
                     flag = 0;
                     break;
                  }
               /* Go to next row and reset the column var */
               if(startRow < m - 1) {
                  startRow++;
                  c = startIndex;
               }
            }
            /* If the loops reach the last element of subMatrix we found an instance*/
            if(j == a && t == b)
               rez++;
            }
         }
      }
      return rez;
   } else {
      return 0;
   }
}

// int search(int **matrix, int **subMatrix, int m, int n, int a, int b) {
//    int count = 0, result = 0;
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(array[i][j] == subMatrix[0][0] && (m - i) >= a && (n - j) >= b){
//                 for(int k = 0; k < a; k++){
//                     for(int l = 0; l < b; l++){
//                         if(subMatrix[k][l] == array[k + i][l + j]){
//                             count++;
//                         }
//                     }
//                 }
//                 if(counter == a * b){
//                     result++;
//                 }
//                 count = 0;
//             }
//         }
//     }
//    return count;


/* The main function */
int main(int argc, char* argv[]) {
   int **subMatrix, **matrix, m, n, a, b;
   scanf("%d %d", &m, &n);
   matrix = makeIntArray2D(m, n);
   read2DArray(matrix, m, n);
   scanf("%d %d", &a, &b);
   subMatrix = makeIntArray2D(a, b);
   read2DArray(subMatrix, a, b);
   printf("%d\n", search(matrix, subMatrix, m, n, a, b));
   destroyIntArray2D(matrix, m);
   destroyIntArray2D(subMatrix, a);
   return 0;
}