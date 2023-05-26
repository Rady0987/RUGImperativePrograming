/* file: tribonacci.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 11 2019 */
/* version: 1.0 */
/* Description: This program reads an integer and calculates the each sum of the 
 * three preceding terms. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	int n,t0=0,t1=1,t2=1,sum = 0;
	scanf("%d", &n);
	for (int i=2; i < n; i++){
	  sum =t0+t1+t2;
	  t0 = t1;
	  t1 = t2;
	  t2 = sum;  
	};
	if ((n==2) || (n==1)) {
		sum=1;
	  };
	   printf("%d\n", sum);
	  return 0;
	 
 }
