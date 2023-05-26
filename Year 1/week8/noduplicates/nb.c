/* file: nb.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON OCT 28 2019 */
/* version: 1.0 */
/* Description: This program outpus the same series of numbers in the same order as 
 * the input, but if a number occurs more than once then only its first occurrence is printed */

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

void noDuplicates(int length, int *arr) { //eliminates the duplicate numbers
	int cheker;
	printf("%d", arr[0]); //prints the first element
	for (int i = 1; i < length; i++) { //picks every number from the series and compares it with the next ones
		for (int j = i-1; j >= 0; j--) { //starting from the previous number i, checks if there are similar numbers
			if (arr[i] == arr[j]) {
				cheker = 1; //if the same number is found cheker = 1 and loop breaks for this i
				break;
			} else {
				cheker = 0; //if not then it will be printed
			}
		}
		if (!cheker) { //if cheker for this i is 0 than it will be printed
			printf(",%d", arr[i]);
		}
	}
	printf("\n");
}
					
int main(int argc, char* argv[]) {
	int n;
	int *series;
	scanf("%d:", &n); //scans the length of series
	series = safeMalloc(n*sizeof(int)); //initialize the first array
	readSeries(n, series); //reads the array
	noDuplicates(n, series);
	return 0;
}
