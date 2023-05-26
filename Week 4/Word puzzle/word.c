/* file:    word.c              */
/* author:  Radu Rusu (email: rusu@student.rug.nl) */
/* date:    29.09.2020               */
/* version: 1.0                */
/* Description: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkNorth(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght>p){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p-j][q]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p-j][q]++;
		}
		return;
}

void checkSouth(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght+p>n){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p+j][q]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p+j][q]++;
		}
		return;
}

void checkWest(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght>q){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p][q-j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p][q-j]++;
		}
		return;
}


void checkEast(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(q+lenght>n){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p][q+j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p][q+j]++;
		}
		return;
}


void checkNorthEast(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght>p*p+(n-q)*(n-q)){
			return;
		}
	  for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p+j][q-j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p+j][q-j]++;
		}
		return;
}

void checkNorthWest(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght>p*p+q*q){
		  return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p-j][q-j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p-j][q-j]++;
		}
		return;
}


void checkSouthEast(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght>(n-p)*(n-p)+(n-q)*(n-q)){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p+j][q+j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p+j][q+j]++;
		}
		return;
}

void checkSouthWest(int p, int q, char word[], char **arr, int **histogram, int n, int size){
		int lenght = size;
		if(lenght> p*p+(n-q)*(n-q)){
			return;
		}
		for(int j=1; j<=lenght; j++){
			if(word[j]!=arr[p-j][q+j]){
				return;
			}
		}
		for(int j=0; j<=lenght; j++){
			histogram[p-j][q+j]++;
		}
		return;
}

void *safeMalloc(int n) { //Function to safely allocate memory
   void *p = malloc(n);
   if (p == NULL) {
      exit(EXIT_FAILURE);
   }
   return p;
}

void printer (char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (i < length - 1) {
            printf("%c,",input[i]);
        } else {
            printf ("%c\n",input[i]);
        }
    }
}

void readWord (char* wordString, char x) { //Function to read the input
    int i = 0;
    while (x != '\n') {
        wordString = realloc (wordString, (i + 1) * sizeof(char) ); // Allocating enough memory for the next char
        wordString[i] = x;
        i++;
        x = getchar();
    }
    //wordString[i] = '\0'; // To finish the string
} 

char **makeCharArray2D(int height, int width) {  //Function to make a dynamic 2D array of integers 
    int col;
    char **arr;
    arr = safeMalloc(height*sizeof(int *));
    for (col=0; col < height; col++) {
        arr[col] = safeMalloc(width*sizeof(int));
    }
    return arr; 
}

int **makeIntArray2D(int height, int width) {  //Function to make a dynamic 2D array of integers 
    int col;
    int **arr;
    arr = safeMalloc(height*sizeof(int *));
    for (col=0; col < height; col++) {
        arr[col] = safeMalloc(width*sizeof(int));
    }
    return arr; 
}

/* This function initialize the histogram with -1 */
void initializeHist(int** arr, int length) {
   for (int i = 0; i < length; i++) {
       for(int j = 0; j < length; j++) {
           arr[i][j] = 0;
       }
   }
}


void destroyCharArray2D(char **arr, int x) { // frees the memory
	for (int i = 0; i < x; i++){
		free(arr[i]); // the lines
	}
	free(arr); // the colomn
}

void destroyIntArray2D(int **arr, int x) { // frees the memory
	for (int i = 0; i < x; i++){
		free(arr[i]); // the lines
	}
	free(arr); // the colomn
}

int main(int argc, char *argv[]) {
    int n, row, column, **histogram;
    char x = '-', **wordPuzzle, *word;
    scanf("%d", &n);
    wordPuzzle = makeCharArray2D(n,n);
    histogram = makeIntArray2D(n,n);
    initializeHist(histogram,n);
    for (row = 0 ; row < n; row++){ // This nested for-loops are scanning the input and inserting the values in the array
        for (column = 0; column < n; column++){
            wordPuzzle[row][column] = getchar();
        }
    }

    printf("------------------------------------\n");
     for (row = 0 ; row < n; row++){ // This nested for-loops are scanning the input and inserting the values in the array
        for (column = 0; column < n; column++){
            printf("%c",wordPuzzle[row][column]);
                
        }
		  printf("\n");
    }

  
    while (x != '.') {
        x = getchar();
        word = safeMalloc(sizeof(char));
        readWord(word , x);
        for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(word[0] == wordPuzzle[i][j]){
						checkEast(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkSouth(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkWest(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkNorth(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkNorthEast(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkNorthWest(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkSouthEast(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
						checkSouthWest(i, j, word, wordPuzzle, histogram, n, strlen(word)-1);
					}
				}
			}
        printer(word);
        free(word);
    }
    		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(histogram[i][j]==0){
					printf("%c", wordPuzzle[i][j]);
				}
			}
		}
    
    destroyCharArray2D(wordPuzzle, n);
    destroyIntArray2D(histogram, n);
    return 0;
}
