/* file: pit.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 2 2019 */
/* version: 1.0 */
/* Description: This program */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	int n,a,b,c=0,m=2,rez=0;
	scanf("%d", &n);
	while ((a+b+c) < n){
		for (int i=1; i<m; i++){
			a=m*m-i*i;
			b=2*m*i;
			c=m*m+i*i;
			if  ((a+b+c) > n){
				break;
			}
		}
		if(a*a+b*b==c*c){
			rez++;
		}
		m++;
	}
	printf("%d\n",rez);
	return 0;
}
