/* file: eval.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: TUE Sep 17 2019 */
/* version: 1.0 */
/* Description: This program reads an integer and a set of letters then executes the 
 * functions which corespond to that letters*/

#include <stdio.h>
#include <stdlib.h>

int f(int x) {
	return (x*x); //function f
}

int g(int x) {
	return (x+1); //function g
}

int h(int x) {
	return (x-1); //function h
}

int main(int argc, char*argv[]){
	char s;
	int n;
	scanf("%d", &n); //reads the number
	while(s !='=') { //until reaches '=' reads every letter
		s = getchar();
		if (s=='f') {//trigger for f function
			n=f(n);
		}
		if (s=='g') {//trigger for g function
			n=g(n);
		}
		if (s=='h') {//trigger for h function
			n=h(n);
		}
	}
	printf("%d\n", n);//prints the result
	return 0;
}
