/* file: wfsp.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: THU OCT 10 2019 */
/* version: 1.0 */
/* Description: This program outputs the number of well formed strings of parentheses that have length n. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long double factorial(int n) { //factorial function
return (n == 0 ? 1 : n * factorial(n-1));
}

int catalanSequence(int n){ //using the Catalan sequence, widely used in combinatorics, i find the number of possible expressions
	int rez;
	rez = factorial(2 * n) / (factorial(n + 1) * factorial(n));
	return rez;
}

int main(int argc, char *argv[]) { 
	int n;
	scanf("%d", &n); //scans the number of parenthesis
	if (n % 2 == 1){ //in case there is an odd number of parenthesis is impossible to make a well formed string
		printf("0\n");
	}else{
		printf("%d\n", catalanSequence(n / 2)); // divide by to in order to obtain the number of pairs
	}
	return 0;
}
