/* file: super.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Thu Sep 19 2019 */
/* version: 1.0 */
/* Description: This program checks how many numbers are super primes from an interval of integers */

#include <stdio.h>
#include <stdlib.h>

int powNumber(int n){ //counts how many digits has a number
	int k=0;
	while(n !=0) {//divides it by 10 until it is not 0
		n=n/10;
		k++;
	}
	return(k);
}

int leftRotation(int n, int k){ //receives the number and number of digits for left rotation
	int rez,exp=1;
	for(int i=1; i<k; i++){ // for the number of digits calculates the 10^k
		exp=exp*10;
	}
	rez=(n%exp)*10 + n/exp;//gets the first digit and multiples it in order to get the digit on the last position
	return(rez);	
}

int nPrime(int n){ //prime checker
	if (n <= 1) return 0; //in case of <1, exits
	if ((n%2 == 0) && (n > 2)) return 0; //for even numbers, starting with 2, exits
	for(int i = 3; i*i <= n; i+= 2){ //starts with 3 and loops to sqrt(n)
		if (n % i == 0)
		return 0;
	}
	return 1;
}

int main(int argc, char*argv[]){
	int a,b,n,ver,k,rez=0;
	scanf("%d" "%d", &a, &b);
	for(int i=a; i<=b; i++){
		k=powNumber(n);//saves the initial number of digits in order to letf rotate properly after 1 interation, especially for numbers like 2000,1000
		n=i;
		ver=1; //variable with true value 
		do {
		if (nPrime(n)==1){ //checks prime
			n=leftRotation(n,k); //initiates the leftRotation function 
			} else {
				ver=0;// in case the number after rotation is not prime, changes the value of ver
				break;
			}
			}while(n != i); //loop continue until the number after rotations reaches the initial number
		if (ver==1) {
			rez++; //counts the super primes 
		}
	}
	printf("%d\n", rez);
	return 0;
}		
			
