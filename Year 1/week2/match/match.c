/* file: match.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 11 2019 */
/* version: 1.0 */
/* Description: This program checks if all the parentheses are written correctly and 
 * each of them is closed */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EOL '\n'

int main(int argc, char*argv[]){
	char s;
	int p1=2,p2=0;
	s = getchar();
	if (s == ')') {
	  printf("INCORRECT\n");
	  return 0;
    } else { 
	   while(s != '\n'){ 
	   s= getchar();
	   if (s=='(') {
         p1++;
	   } else { 
		  p2++;
		 };  
	   }
     } 
	if (p1==p2) {
	  printf("CORRECT\n");
	  }else 
	  printf("INCORRECT\n");
  	
return 0;	
	}
