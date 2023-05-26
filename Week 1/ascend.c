/* file: ascend.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 4 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs YES if n is an ascending number,
 or NO otherwise.  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int n, lastDig;
   scanf("%d", &n);
	lastDig = n % 10;
	n /= 10;
	if (lastDig >= n % 10) {
		lastDig = n % 10;
		n /= 10;
		if (lastDig >= n % 10) {
			lastDig = n % 10;
			n /= 10;
			if (lastDig >= n % 10) {
				lastDig = n % 10;
				n /= 10;
				if (lastDig >= n % 10) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
