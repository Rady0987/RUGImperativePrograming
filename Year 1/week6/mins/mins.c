/* file: mins.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON OCT 14 2019 */
/* version: 1.0 */
/* Description: This program reads from the input integers n and g, in order to output the minimal number of steps that are needed to reach g starting from n. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minSteps(int n, int g, int rez, int *min){ //the formal variables are the numbers, number of interations and the previous minimal interation number
	if (n == g){ //base case: when the both numbers are equal
		if(rez < *min){ //checks if the previous number of steps is greater than the curent one
			*min = rez; //changes th value of the pointer(number of steps)
		}
		return;
	}else if(n > g || rez > *min){//in case g becomes smaller than n or the number of interations in the process of counting becomes bigger than min, there is no sense to continue
		return;
	}else{
		if (g % 3 == 0){ //the fastest way is to /3, so it stays the first in the "if- list"
			minSteps(n, g / 3, rez + 1, min); //recursive call
		}
		if ((g - 1) % 3 == 0){ //a backdoor for special cases, in order to find the best way 
			minSteps(n, (g - 1) / 3, rez + 2, min);
		}
		if (g % 2 == 0){ //the second way, considering the speed 
			minSteps(n, g / 2, rez + 1, min);
		}
		minSteps(n, g - 1, rez + 1, min); //decrement
	}
}

int main(int argc, char*argv[]){
	int n, g, minS = 500; 
	scanf("%d", &n); //scans n
	scanf("%d", &g); //scans g
	minSteps(n, g, 0, &minS); //first call
	printf("%d\n", minS);
	return 0;
}


