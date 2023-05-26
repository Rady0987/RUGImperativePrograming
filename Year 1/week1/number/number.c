/* file: number.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Thu Sep 5 2019 */
/* version: 1.0 */
/* Description: This program checks if 2 numbers are the same when 
 * their digits are reversed */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]) {
	int n1, n2, rest, rn = 0;
	scanf("%d" "%d", &n1, &n2);
	if (n1 > 0) {
	rest = n1%10;
	rn = rn*10+rest;
	n1 = n1/10;
}
	if (n1 > 0) {
	rest = n1 % 10;
	rn = rn * 10 + rest;
	n1 = n1/10;
}
    if (n1 > 0) {
	rest = n1 % 10;
	rn = rn * 10 + rest;
	n1 = n1/10;
}
    if (n1 > 0) {	
	rest = n1 % 10;
	rn = rn * 10 + rest;
	n1 = n1/10;
}
	if (rn==n2) {
	  printf("YES\n");
	} else {
	  printf("NO\n");
}
	return 0;
}
