/* file: primsum.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 27 sep 2020 */
/* version: 1.0 */
/* Description: This program reads from the input an integer n and outputs the nth prime number for
which this property holds. (primal sum)  */

#include <stdio.h>
#include <stdlib.h> 

//This is a prime checker function
int isPrime(int n){ 
   //in case of < 1, exits
	if (n <= 1) 
      return 0; 
   //for even numbers, starting with 2, exits
	if ((n % 2 == 0) && (n > 2)) 
      return 0; 
   //starts with 3 and loops to sqrt(n)
	for (int i = 3; i * i <= n; i += 2) { 
		if (n % i == 0)
		   return 0;
	}
	return 1;
}

//This function iterates over prime numbers and calculates each sum
int primeSeq(int n) {
   int i = 1, count = 0 ,sum = 0;
   while(count != n) {
      if(isPrime(i)) {
         sum += i;
         if(isPrime(sum))
            count++;
      }
      i++;
   }
   /*As we incement i in the while loop, when it exits, 
   the result is by 1 greater*/
   i--;
   return i;
}

int main(int argc, char* argv[]) {
   int n;
   scanf("%d", &n);
   printf("%d\n", primeSeq(n));
   return 0;
}