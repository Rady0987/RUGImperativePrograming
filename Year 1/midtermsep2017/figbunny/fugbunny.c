/* file: tribonacci.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 11 2019 */
/* version: 1.0 */
/* Description: This program reads from the input a year 
 * (a positive integer which is at most 50), and outputs the number 
 * of rabbit pairs in that year.*/
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a,b,c,d,e,n;
  scanf("%d", &n);
  a = 1;
  b=c=d=e=0;
  while (n>0) {
    int babies = b+c+d+e;
    e=d;
    d=c;
    c=b;
    b = a;
    a = babies;
    n--;
  }
  printf("%d\n", a+b+c+d+e);
  return 0;
}
