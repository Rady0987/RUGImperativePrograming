/* file: box.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Mon Sep 9 2019 */
/* version: 1.0 */
/* Description: This program calculates the left-bottom and right-top coordinates 
 * of a bounding box of 3 circles*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]) {
	int x1,x2,x3,y1,y2,y3,r1,r2,r3,botx,boty,topx,topy;
	scanf("%d %d %d", &x1, &y1, &r1);
	scanf("%d %d %d", &x2, &y2, &r2);
	scanf("%d %d %d", &x3, &y3, &r3);
	boty=y1-r1;
	if (boty > y2-r2) {
		boty = y2 - r2;
	};
	if (boty > y3 - r3) {
		boty = y3- r3;
	};
	botx = x1 - r1;
	if (botx > x2 - r2) {
		botx = x2 - r2;
	};
	if (botx > x3 - r3) {
		botx = x3 - r3;
	};
	topy = y1 + r1;
	if (topy < y2 + r2) {
		topy = y2 + r2;
	};
	if (topy < y3 + r3) {
		topy = y3 + r3;
	};
	topx = x1 + r1;
	if (topx < x2 + r2) {
		topx = x2 + r2;
	};
	if (topx < x3 + r3) {
		topx = x3 + r3;
	};
	printf("[(%d,%d),(%d,%d)]\n",botx,boty,topx,topy);	
	return 0;
}
