/* file: friday.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Tue Sep 1 2019 */
/* version: 1.0 */
/* Description: This program  reads from the input a positive integer 
 * n (where n < 1000), and outputs the nth next year (starting from 2017 
 * for n=0) in which the 13th of October is a Friday.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	int rez=5,a=0, startYear=2017,nYear;
	scanf("%d",&nYear);
	while(a != nYear){
		startYear++;
		if(rez>7){
			rez-=7;
		}
		if (((startYear%4==0) && (startYear%100 !=0)) || (startYear%400==0)){
			rez+=2;	
		}else{
			rez+=1;
		}
		if(rez==5){
			a++;
		}
	}
	printf("%d\n",startYear);
	return 0;
}
	
