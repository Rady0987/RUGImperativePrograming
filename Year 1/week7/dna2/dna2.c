/* file: dna2.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: TUE OCT 22 2019 */
/* version: 1.0 */
/* Description: This program outputs YES if we can transform the 
 * first string into the second by changing most k letters. Otherwise, the output should be NO.  */

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

char *readDNA(int *p ){ //reads the string of DNA
	char *string; //initialize the address of the string
	char s;
	int i=0; //counter for length
	string = safeMalloc(sizeof(char)); //initialize the string
	scanf("%c", &s); //scans the first letter of DNA
	while(s != '\n'){ //while it is not end of line
		string=realloc(string,(i+2)*sizeof(char));  //if it passes while it allocates one more memory cell for another element
		string[i]=s; //assigns the letter to the element of string 
		i++;
		scanf("%c", &s); //scans the next letter of string
	}
	string[i]='\0'; //in case this interation is the last, it assigns '\0' as the string is ended
	*p=i;
	return string; //returns the string
}

int swapLetters(char *string1, char *string2, int j, int length){
	int possibleSwap;
		for(int i = j + 1; i < length; i++){ //starting with the next index, compares each element from string2 with the saved one from string1
			if ((string1[j] == string2[i]) && (string1[i] != string2[i])){ //tries to find the element that is the same as that from string1, but different from that which is on the same position
				possibleSwap = string2[j];
				string2[j] = string1[i];
				string2[i] = possibleSwap;
				return 1;
				}
			}
	return 0;
}

int matchDNA(char *string1, char *string2, int length){
	int  dif=0;
	for (int j = 0; j < length; j++){ //goes through every element
		if (string1[j] != string2[j]){ //compares each pair
			if(swapLetters(string1, string2, j, length) == 0){ //if swap is not possible 
			dif++; //in case of differences +1
			}
		}
	}
	return dif;
}

int main(int argc, char*argv[]){
	int k, length, diff;
	char *dna1, *dna2;
	scanf("%d", &k); //scans k
	getchar(); //skips the '\n'
	dna1 = readDNA(&length);
	dna2 = readDNA(&length);
	diff = matchDNA(dna1, dna2, length);
	if(diff > k){ //if the number of differences - possible swaps is greater that k print NO
		printf("NO\n");
	}else{
		printf("YES\n");
	} 
	return 0;
}
