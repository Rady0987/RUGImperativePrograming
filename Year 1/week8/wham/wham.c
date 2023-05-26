/* file: wham.c */
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

/*void prefix(int length, int *arr) {
	int *pre;
	int j = 0, l = 0, startIndex = 0, endIndex = 0, finalS = 0, finalE = 0;
	pre = safeMalloc(sizeof(int));
	while (j < length) {
		j = endIndex;
		if (arr[j] < arr[j + 1]) {
			startIndex = j;
			endIndex = j;
			while (arr[endIndex] < arr[endIndex + 1] && endIndex < (length - 1)) {
				endIndex++;
			}
		}
		if((endIndex - startIndex) > (finalE - finalS)) { //compares the staring, ending positions with previous iteration
			finalE = endIndex;
			finalS = startIndex;
		}
	}
	for (int i = startIndex; i <= endIndex; i++) {
		pre = realloc(pre, (l+1)*sizeof(int));
		pre[l] = arr[j];
		pre[l+1] = arr[j+1];
		l++;
	}
}*/
void whamsort(int length, int a[]){
	int *tmp = malloc(len*sizeof(int));
	recWhamsort(0, length, a, tmp);
	free(tmp);
}	

void merge(int start, int r, int s , int arr[]) {
	int idx, l, r;
	idx = l = r = 0;
	l = start;
	while ((l != r) && (r != s)) {
		if (arr[l] <= arr[r]) {
			arr[idx] = arr[l];
			l++;
		} else {
			arr[idx] = b[r];
			r++;
		}
	idx++;
	}
/* process trailing elements: either l==lenA or r==lenB */
	while (l != lenA) {
		arr[idx] = a[l];
		idx++;
		l++;
		}
	while (r != lenB) {
		arr[idx] = b[r];
		idx++;
		r++;
	}
}


void recWhamsort(int start, int length, int a[]){
/* pre start <= length; this function sorts a[start,..,q) */
	int r = start+1;
	while (r < length && a[r-1] <= a[r]) {
		r++;
	}
/* a[start,r) is maximal ascending prefix of a[] */
	while (r < length) { /* note: 2*(r-start)+start==2*r-start */
		int s = (length < 2*r – start ? length : 2*r – start);
		recWhamsort(r, s, a);
		merge(start, r, s, a);
		r = s;
	}
}	
			
int main(int argc, char* argv[]) {
	int n;
	int *series;
	scanf("%d:", &n); //scans the length of series
	series = safeMalloc(n*sizeof(int)); //initialize the first array
	readSeries(n, series); //reads the array
	return 0;
}
