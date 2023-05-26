/* file: shell.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON Sep 30 2019 */
/* version: 1.0 */
/* Description: This program program prints the position of the ball 
 * after shuffles in the shell game.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	int intPos,n,m,finPos;
	scanf("%d", &intPos);
	do {
		scanf("%d",&n);
		if(n==0){
			break;
		}
		scanf("%d", &m);
		if(n==intPos) {
			finPos=m;
			intPos=m;
		}else if (m==intPos){
			finPos=n;
			intPos=n;
		}
	}while(1==1);
	
	if(finPos==1){
		printf("POSITION 1\n");
	}else if(finPos==2){
		printf("POSITION 2\n");
	}else if(finPos==3){
		printf("POSITION 3\n");
	}
	return 0;
}
