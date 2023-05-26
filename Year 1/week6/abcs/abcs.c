/* file: abcs.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: THU OCT 10 2019 */
/* version: 1.0 */
/* Description: This program reads from the input a wilcard pattern and outputs in lexicographic order all possible
combinations that match this pattern. */


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

void combinations(char *string, char *abc, int i){ 
	int l;
	l = strlen(string); //the length of the string
	if (i == l){ //until it reaches the last character
		printf("%s\n", string);
		return;
	}else{	
		if ('?' == string[i]){ //checks if the element is ?
			for(int h = 0; h < 3; h++){ //each element becomes A,B,C
				string[i] = abc[h]; 
				combinations(string, abc, i+1); //switches to the next element
				string[i] = '?'; //condition that provides backtracking, as it marks the last element which was outputed with different combinations 
			}
		}else{
			combinations(string, abc, i+1); //if the last element reached is not ?, prints and ends the combination
		}	
	}
}

int main(int argc, char *argv[]) { 
	char *string;
	char abc[3] = {'A','B','C'}; //characters with which combinations are done
	string = safeMalloc((1 + 32) * sizeof(char));
	scanf("%s", string); //scans initial string 
	combinations(string, abc, 0); //first function call
	return 0;
}
