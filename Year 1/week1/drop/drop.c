/* file: drop.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Thu Sep 5 2019 */
/* version: 1.0 */
/* Description: This program drops reversal non-negative integers*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]) {
	int n, nr2=0;
	scanf("%d", &n);
	if (n > 100000000) {
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if  (n > 1000000){
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if (n > 100000) {
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if (n > 10000) {
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if (n > 1000) {
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	printf("%d\n", nr2);
	exit(0);
}	
if (n > 100) {
	nr2 = nr2 * 10 +n % 10;
	n = n/100;
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if (n > 10) {
	nr2 = nr2 * 10 +n % 10;
	printf("%d\n", nr2);
	exit(0);
}
if (n <10) {
	nr2=n;
	printf("%d\n", nr2);
	exit(0);
}
return 0;
}
