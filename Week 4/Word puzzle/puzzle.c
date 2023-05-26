/*file : puzzle.c*/
/*author : Horea Bochis(H.A.Bochis@student.rug.nl)*/
/*date : 07.09.2020 */
/*version : 1 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *safeMalloc(int n) { //Function to safely allocate memory
   void *p = malloc(n);
   if (p == NULL) {
      exit(EXIT_FAILURE);
   }
   return p;
}

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

char **makeCharArray2D(int height, int width) {  //Function to make a dynamic 2D array of integers 
    int col;
    char **arr;
    arr = safeMalloc(height*sizeof(char *));
    for (col=0; col < height; col++) {
        arr[col] = safeMalloc(width*sizeof(char));
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

int main (int argc, char *argv[]) {
	int n, **histogram;
	char word[21], **arr;
	  // in this program I use a histogram in order to mark the words that have been found and print whatever was not
	 	scanf("%d", &n);
		// char arr[21][21], word[21];
		// int histogram[21][21]={0}, n = 0;
		histogram = makeIntArray2D(n,n);
		arr = makeCharArray2D(n,n);
		initializeHist(histogram, n);
		for (int i = 0; i < n; i++){
			scanf("%s", word);
			for (int j = 0; j < n; j++){
				arr[i][j] = word[j];
			}
		}
		while(word[0] != '.'){
			scanf("%s", word);
			if(word[0] == '.'){
					break;
			}
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(word[0] == arr[i][j]){
						checkEast(i, j, word, arr, histogram, n, strlen(word)-1);
						checkSouth(i, j, word, arr, histogram, n, strlen(word)-1);
						checkWest(i, j, word, arr, histogram, n, strlen(word)-1);
						checkNorth(i, j, word, arr, histogram, n, strlen(word)-1);
						checkNorthEast(i, j, word, arr, histogram, n, strlen(word)-1);
						checkNorthWest(i, j, word, arr, histogram, n, strlen(word)-1);
						checkSouthEast(i, j, word, arr, histogram, n, strlen(word)-1);
						checkSouthWest(i, j, word, arr, histogram, n, strlen(word)-1);
					}
				}
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(histogram[i][j]==0){
					printf("%c", arr[i][j]);
				}
			}
		}
		printf("\n");
		return 0;
}
