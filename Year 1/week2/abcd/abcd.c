/* file: abcd.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 11 2019 */
/* version: 1.0 */
/* Description: This program calculates the maximum value of a*b+b*c+c*d under
 * the contraint that the sum of the numbers is a given integer */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]){
	int rez=0,c,b,n,a=1,d=1;
	scanf("%d", &n);
	b = n / 2;
	if (n%2 !=0) {
	 c = n / 2;
	 b = n - c - 2;
	} else {
	  n = n - 2;
	  b = n / 2;
	  c = b; 
	};
	rez =  a * b + b * c + c *d;
	printf("%d\n", rez);
	return 0;	
	}
		
		
