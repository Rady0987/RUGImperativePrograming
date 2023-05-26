/* file: pprimes.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON Sep 30 2019 */
/* version: 1.0 */
/* Description: This program .*/

#include <stdio.h>
#include <stdlib.h>

int isPrime (int n){
	if (n ==1) return 0;
	if (n % 2 == 0) return (n == 2);
	for (int i = 3; i*i < n; i+=2){
		if ( n%i == 0) return 0;	
		}
		return 1;
}
int main(int argc, char *argv[]) { 
	int p = 2, idx =1 , cnt = 0;
	scanf("%d", &cnt);
	while (cnt > 0) {
		if (isPrime(p)){
			cnt -= isPrime(idx);
			idx ++;
			}
			p ++;
		}
		printf("%d\n", p-2);
		return 0;
}
