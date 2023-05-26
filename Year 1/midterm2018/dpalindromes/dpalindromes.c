/* file: dpalindromes.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 2 2019 */
/* version: 1.0 */
/* Description: This program */

#include <stdio.h>
#include <stdlib.h>

int reverse (int n, int base){
	int r = 0;
	while (n > 0){
		r = base * r+ n% base;
		n /= base;
		}
		return r;
	}

int main(int argc, char *argv[]) {    
	int count=0,a,b;       
	scanf("%d",&a);
	scanf("%d",&b);
	for (int i=a; i<= b; i++){
		count += (i == reverse(i,10) && i == reverse(i,2));
	}    
	printf("%d",count);
	return 0;  
}
