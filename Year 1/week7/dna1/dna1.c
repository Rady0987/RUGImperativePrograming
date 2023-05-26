/* file: dna1.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: SAT OCT 19 2019 */
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

char *readDNA(){ //reads the string of DNA
	char *string; //initialize the address of the string
	char s;
	int i=0; //counter for length
	string = safeMalloc(sizeof(char)); //initialize the string
	scanf("%c", &s); //scans the first letter of DNA
	while(s != '\n'){ //while it is not end of line
		string=realloc(string,(i+2)*sizeof(char));  //if it passes while it allocates one more memory cell for another element
		string[i]=s; //assigns the letter to the element of string 
		string[i+1]='\0'; //in case this iteration is the last, it assigns '\0' as the string is ended
		i++;
		scanf("%c", &s); //scans the next letter of string
	}
	return string; //returns the string
}
	
void matchDNA(char *string1, char *string2, int k){
	int length, dif=0;
	length=strlen(string1); //length of both strings
	for (int j = 0; j < length; j++){ //goes through every element
		if (string1[j] != string2[j]){ //compares each pair
			dif++; //in case of differences +1
		}
	}
	if(dif > k){ //compares the differences and k
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}
		
 	
int main(int argc, char*argv[]){
	int k;
	char *dna1, *dna2;
	scanf("%d", &k); //scans k
	getchar(); //skips the '\n'
	dna1 = readDNA();
	dna2 = readDNA();
	matchDNA(dna1, dna2, k);
	return 0;
}
