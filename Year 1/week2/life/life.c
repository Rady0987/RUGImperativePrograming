/* file: life.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 11 2019 */
/* version: 1.0 */
/* Description: This program counts how many numbers after performing a special interation
 * give 42 as a result*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[]){
	int a=0,digit,n,m,sum = 0;
	scanf("%d %d" ,&n, &m);
	for(int i=n; i<m; i++){
	 n = i;
	 do {
	  sum=0;
	  while (n != 0) {
	   digit = n%10;
	   sum +=digit*digit;
	   n = n/10;
	  }
	  n = sum;
	  if(sum == 42) {
	   a++; 	
	  } 
	 }while((n != 1) && (n != 42));
	
    }
	printf("%d\n",a);	
return 0;
}

		
