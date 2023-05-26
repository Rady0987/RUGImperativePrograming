/* file: repro.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 4 2019 */
/* version: 1.0 */
/* Description: This program calculates the number of packages 
 * that must be fetched from the warehouse */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]) {
	int n, x;
	scanf("%d", &n);
	x=n/500;
	if (n % 500 !=0) {
		x=x+1;
	}
	printf("%d\n", x);
	return 0;
}
