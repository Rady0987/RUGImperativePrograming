/* file: box.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 4 sep 2020 */
/* version: 1.0 */
/* Description: This program prints on the bottom
left corner point and the top right corner point of the bounding box.  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int x1, y1, x2, y2, x3, y3, botX, botY, topX, topY;
   scanf("%d %d", &x1, &y1);
   scanf("%d %d", &x2, &y2);
   scanf("%d %d", &x3, &y3);
   if (x1 <= x2 && x1 <= x3) {
      botX = x1;
   } else if (x2 <= x1 && x2 <= x3) {
      botX = x2;
   } else {
      botX = x3;
   }

   if (y1 <= y2 && y1 <= y3) {
      botY = y1;
   } else if (y2 <= y1 && y2 <= y3) {
      botY = y2;
   } else {
      botY = y3;
   }
   
   if (x1 >= x2 && x1 >= x3) {
      topX = x1;
   } else if (x2 >= x1 && x2 >= x3) {
      topX = x2;
   } else {
      topX = x3;
   }

   if (y1 >= y2 && y1 >= y3) {
      topY = y1;
   } else if (y2 >= y1 && y2 >= y3) {
      topY = y2;
   } else {
      topY = y3;
   } 

   printf("[(%d,%d),(%d,%d)]\n", botX, botY, topX, topY);  
	return 0;
}