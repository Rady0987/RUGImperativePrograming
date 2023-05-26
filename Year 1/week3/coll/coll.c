/* file: coll.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 18 2019 */
/* version: 1.0 */
/* Description: This program involves the Collatz sequence and finds the number that requires
 * the biggest number of interation to reach 1*/

#include <stdio.h>
#include <stdlib.h>

int lengthOfCollatzSequence(int n){ // function that counts the length of sequence
	int numSteps=0;
	while( n!=1){ // until n is 1 checks if it is odd or even 
		if (n%2==0){
			n=n/2;
		} else {
			n=n*3+1;
		}
	numSteps++;	//counts interations
	}
	return(numSteps); //returns the result
}

int main(int argc, char*argv[]){
	int a,b,max=0,rez;
	scanf("%d" "%d", &a, &b); //reads the edges of the row
	for(int i=a;i<=b;i++){
		if (lengthOfCollatzSequence(i)>max){ //compares the length of the i number
			max=lengthOfCollatzSequence(i);
			rez=i; // saves the number
			if ((lengthOfCollatzSequence(i)==max) && (rez >i)){ //in case there are 2 numbers with the same length
				rez=i;
			}
		}
	}
	printf("%d\n",rez); //prints result
	return 0;
}
	
		
		
