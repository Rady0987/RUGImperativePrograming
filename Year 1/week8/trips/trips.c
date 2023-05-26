/* file: trips.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: SUN OCT 27 2019 */
/* version: 1.0 */
/* Description: This program determines the number of triplets (a, b, c) drawn from 
 * this series such that a < b < c and a + b + c = n */

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
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		getchar(); //skips ','
	}
}

int *copySubArray(int left, int right, int arr[]) { //creates a sub array
	int i, *copy;
	copy = malloc((right - left)*sizeof(int)); //mem allocation
	for (i=left; i < right; i++) {
		copy[i - left] = arr[i];
	}
	return copy; //returns the created array
}

void mergeSort(int length, int arr[]) { //sorts the series in an ascending way
	int l, r, mid, idx, *left, *right;
	if (length <= 1) { //base case, if the array can't be halved anymore 
		return;
	}
	mid = length/2; //halves the series of numbers 
	left = copySubArray(0, mid, arr); //creates an array of the 0 to mid elements 
	right = copySubArray(mid, length, arr); //creates an array of mid (included) to length
	mergeSort(mid, left); //recalls the function but now for the left array
	mergeSort(length - mid, right); //recalls the function for the rigth array
	idx = 0;
	l = 0;
	r = 0;
	while ((l < mid) && (r < length - mid)) { //while indexes don't exceed the bounds for left and right, as they are halved by mid
		if (left[l] < right[r]) { //compares the elements from the 2 arrays
			arr[idx] = left[l]; //assigns the smallest element
			l++; //increase index counter
		} else {
			arr[idx] = right[r]; //assigns the smallest element
			r++;
		}
		idx++;//next element in the main array
	}
	while (l < mid) { //for all left elements 
		arr[idx] = left[l];
		idx++;
		l++;
	}
	while (r < length - mid) { //for all right elements
		arr[idx] = right[r];
		idx++;
		r++;
	}
	free(left);  //free memory
	free(right);
}

int c(int length, int a[], int rest) { //binary search funtion
	int left=0; //start index
	int right = length; // the end index 'right' has the length value
	while (left < right - 1) { //until the indexes aren't the same
		int mid = (left + right) / 2; //calculates the middle
		if (rest < a[mid]) { // if the target is smaller than the middle
			right = mid; // middle is assgined to the right bound 
		} else {
			left = mid; //middle is assgined to the left bound 
		}
	}
	if ((left < length) && (a[left] == rest)) { //if the target is found
		return 1;
	}
	return -1;
}

void ab(int length, int *arr, int sum){
	int rest, equal, last, rez = 0;
	last = length - 1; //last element of the arr
	for (int j = last; j > 0; j--) { //loop that goes from the last element to the first
		for (int i = 0; i < j; i++) { //loop that goes from the first element to the j index for the previous loop
			equal = arr[i] + arr[j]; //sum of the 2 elements selected
			if (equal < sum) { //if the sum is lower than the target sum
				rest = sum - equal; //calculates the rest that is needed to reach the target
				if ((rest > arr[i]) && (rest < arr[j])) { //a < b < c
					if (c(length, arr, rest) == 1) { //if there is such an element in the arr
						rez++; //counter
					}
				}
			} else {
				break; // if the sum is greater than the target, stop and go to the next index
			}
		}
	}
	printf("%d\n", rez); //prints the number of combinations
}
			
int main(int argc, char* argv[]) {
	int n, sum;
	int *series;
	scanf("%d, %d:", &n, &sum); //scans the length of series
	series = safeMalloc(n*sizeof(int)); //initialize the first array
	readSeries(n, series); //reads the array
	mergeSort(n, series);
	ab(n, series, sum);
	free(series);
	return 0;
}
