/* file: locs.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: TUE OCT 22 2019 */
/* version: 1.0 */
/* Description: This program prints the longest ordered consecutive subsequence of the input sequence. */

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

int  *readSequence(int *p){ //reads the sequence and also returns the length by p pointer
	int  i = 0;
	char s;
	int *sequence;
	sequence = safeMalloc(sizeof(int)); //initialize the sequence
	while(s != '\n'){ //while it is not end of line 
		sequence = realloc(sequence,(i + 1) * sizeof(int));  //if it passes while it allocates one more memory cell for another element
		(void)scanf("%d", &sequence[i]); //scans the number
		s = getchar(); //skips the ','
		i++; // counter to increase the index for *series
	}
	*p = i; //assigns the length of sequence
	return sequence; //returns the sequence
}
 
void printSeries(int *series, int start, int length){ //prints the final series 
	for(int j = start; j <= length; j++){
		printf("%d", series[j]); //print the element
		if(j < length){ //if it is no the last element prints ','
			printf(",");
		}
	}
	printf("\n");
}

void sort(int *series, int i){
	int startIndex = 0, endIndex = 0, j = 0, finalS = 0, finalE = 0;
	while(j < i){ //go through every element until reaches end
		j = endIndex;
		if (endIndex == (i - 1)){ // as we get to the last but one element end, as we compare j and j+1 element
			break;
		}
		if (series[j] > series[j+1]){ //if it encounters a descending pair
			startIndex = j; //saves the initial starting position
			endIndex = j; //also assigns the same value to the end counter
			while(series[endIndex] > series[endIndex + 1] && endIndex < i - 1){ //while the counter remains the same, increases the last position
				endIndex++; 
			}
		}
		if (series[j] < series[j + 1]){ //if it encounters a ascending pair
			startIndex = j; //saves the initial starting position
			endIndex = j; //also assigns the same value to the end counter
			while(series[endIndex] < series[endIndex + 1] &&  endIndex < i - 1){ //while the counter remains the same, increases the last position
				endIndex++;
			}
		}
		if((endIndex - startIndex) > (finalE - finalS)){ //compares the staring, ending positions with previous iteration
			finalE = endIndex;
			finalS = startIndex;
		}
	}
	printSeries(series, finalS, finalE); //prints
}

int main(int argc, char*argv[]){
	int *series; //  int array: the one that is read
	int i;
	series = readSequence(&i);
	sort(series, i);
	free(series);
	return 0;
}
