/* file: missn.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: TUE OCT 22 2019 */
/* version: 1.0 */
/* Description: This program determines the maximum number 'n' from a series, and
next outputs all integers 'a' with 0 ≤ a < n that are missing from the input series */

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc(int n) {//allocates memory for an array
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

void readSeries(int n , int *arr) { //reads the numbers from series
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		getchar(); //skips ','
	}
}

void showArray(int length, int arr[]) { //prints the series
	printf("%d", arr[0]); //prints 1st number
	for (int i = 1; i < length; i++) {
		printf(",%d", arr[i]); //prints the rest
	}
	printf("\n");
}

void noDuplicates(int length, int *arr) {
	int cheker;
	for (int i = 0; i < length; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[i] == arr[j]) {
				cheker = 1;
				break;
			} else {
				cheker = 0;
			}
		}
		if (cheker == 0) {
			printf("%d\n", arr[i]);
		}
	}
}
					
int main(int argc, char* argv[]) {
	int n;
	int *series;
	scanf("%d:", &n); //scans the length of series
	series = safeMalloc(n*sizeof(int)); //initialize the first array
	readSeries(n, series); //reads the array
	showArray(n, series);
	noDuplicates(n, series);
	return 0;
}
