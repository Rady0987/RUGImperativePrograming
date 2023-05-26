/* file: takuzu.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: SAT OCT 5 2019 */
/* version: 1.0 */
/* Description: This program reads from the input a completely filled 8 × 8 grid of 0s
and 1s, it outputs CORRECT if the grid satisfies all the rules of a Takuzu
puzzle, otherwise it should output INCORRECT. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int number, int exponent) { //calculates the power for the binary-decimal transformation
	int m=1;
	while (exponent!=0) {
		if (exponent%2 == 0) {
			number = number*number;
			exponent = exponent/2;
		} else {
			m = m*number;
			exponent--;
		}
	}
	return m;
}

int main(int argc, char *argv[]) { 
	char matrix[8][8]; //initializes a 2d array of chars
	int one = 0, number0=0, number1=0, zero = 0; //counters
	char *s0, *s1;
	s0 = malloc((1 + 8)*sizeof(char));
	s1 = malloc((1 + 8)*sizeof(char));
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			scanf("%c", &matrix[i][j]); //reads the imput
			if(j == 7){
				getchar(); //skips the '\n'
			}
			if (matrix[i][j] == '1'){ //counts how many 1s and 0s are in the entire array
				zero++;
			}else{
				one++;
			}
		}
	}
	
	for (int i = 0; i < 8; i++){ // checks if there are same rows
		number0 = 0;
		for (int j = 0; j < 8; j++){ 
			s0[j] = matrix[i][j]; //assigns all the elements from matrix[i][j] to s0
			number0 = number0 + (s0[j]-'0') * power(2,j); //transforms the binary digits from char to int and then in a decimal number
		}
		for (int p = i + 1; p < 7; p++){
			number1 = 0;
			for (int q = 0; q < 8; q++){
				s1[q] = matrix[p][q];
				number1 = number1 + (s1[q] - '0') * power(2,q);	
			}
			if(number1 == number0){ //compares the decimal numbers that represent the each row of the matrix
				printf("INCORRECT\n");
				return 0;
			}
		}
	}
				
	for (int i = 0; i < 8; i++){ // checks if there are same column
		number0 = 0;
		for (int j = 0; j < 8; j++){ 
			s0[j] = matrix[j][i]; //assigns all the elements from matrix[j][i] to s0
			number0 = number0 + (s0[j]-'0') * power(2,j); //transforms the binary digits from char to int and then in a decimal number
		}
		for (int p = i + 1; p < 7; p++){
			number1 = 0;
			for (int q = 0; q < 8; q++){
				s1[q] = matrix[q][p];
				number1 = number1 + (s1[q] - '0') * power(2,q);	
			}
			if(number1 == number0){ //compares the decimal numbers that represent the each row of the matrix
				printf("INCORRECT\n");
				return 0;
			}
		}
	}						
	for (int i = 2; i < 8; i++){
		for (int j = 2; j < 8; j++){ //checks every 3 elements of the array, the loop ends with 5 as in the comparison it increases i and j with 2 
			if((matrix[i][j]==matrix[i][j - 1] && matrix[i][j - 1]==matrix[i][j - 2]) || (matrix[i][j]==matrix[i - 1][j] && matrix[i - 1][j]==matrix[i - 2][j])){
				printf("INCORRECT\n"); //if 3 elements are the same prints 'incorrect'
				return 0;
			}
		}
	}
	if(zero == one){ //if the number of 1s and 0s are the same prints 'correct' 
		printf("CORRECT\n");
	}else{
		printf("INCORRECT\n");
	} 	
return 0;
}
