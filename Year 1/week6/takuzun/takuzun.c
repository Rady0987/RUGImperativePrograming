/* file: takuzun.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON OCT 14 2019 */
/* version: 1.0 */
/* Description: This program outputs the number of well formed strings of parentheses that have length n. */

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

int power(int number, int exponent) { //calculates the power for the binary-decimal transformation
	int m = 1;
	while (exponent != 0) {
		if (exponent % 2 == 0) {
			number = number * number;
			exponent = exponent/2;
		} else {
			m = m * number;
			exponent--;
		}
	}
	return m;
}

int binaryDecimal(char *string, int n){ //converts a binary string to a decimal number
	int number = 0, k = n - 1; 
	for (int j = 0; j < n; j++){
		if (string[j] == '0'){
			k--;
		}else{
			number = number + (string[j] - '0') * power(2,k); //transforms the binary digits from char to int and then in a decimal number
			k--;//decreases the counter that represent the positions of the digits when doing the transformation
		} 
	}
	return number;
}

int takuzuChecker(char *string, int n){
	int one = 0, zero = 0;
	if (string[0] == '0'){ //in case the combination starts with '0'
		return 0;
	}
	if (string[1] == '0' && string[2] == '0' && string[3] == '0'){ //in case the 1-4 elements are '0'
		return 0;
	}
	for (int j = 2; j < n; j++){ // checks every 3 elements of the string if they are the same
		if(string[j] == string[j - 1] && string[j - 1] == string[j - 2]){
			return 0;
		}
	}
	for (int i = 0; i < n; i++){
		if (string[i] == '1'){ //counts how many 1s and 0s are in the entire array
			one++;
		}else{
			zero++;
		}
	}
	if(zero == one){ //if the number of 1s and 0s are the same returns 1, unless 0
		return 1;
	}else{
		return 0;
	}
}

void combinations(int n, char *string, int i){
	if (i == n){ //while the index is different from the length of the string 
		if (takuzuChecker(string, n)){ //if the combination fulfils all the takuzu rules, it prints the string and its decimal
			printf("%s:%d\n",string, binaryDecimal(string, n)); //prints the suitable combination and its decimal 
			return;
		}
		}else{
			string[i] = '0'; // the i element becomes '0'
			combinations(n, string, i+1); //recursive call that goes to the i+1 element
			string[i] = '1';
			combinations(n, string, i+1);
		}
}

int main(int argc, char *argv[]) { 
	int n;
	char *string;
	scanf("%d",&n); //scans the length of the future combinations
	string = safeMalloc((1 + n) * sizeof(char)); //mem allocation
	combinations(n, string, 0); //first call
	return 0;
}
	
