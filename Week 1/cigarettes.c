/* file: cigarettes.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 4 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the number of cigarettes that can be
 smoked that day.  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int n, cig;
	scanf("%d", &n);
	cig = (n - 1) / 3;
	printf("%d\n", cig);
	return 0;
}