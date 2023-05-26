/* file: equation.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: WED Sep 25 2019 */
/* version: 1.0 */
/* Description: This program */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b,rez;
  char op;
  if (scanf("%d", &a) == 1) {
    scanf("%c", &op);
    if (scanf("%d", &b) == 1) {
		if (op=='+'){
			rez=a+b;
			printf("x=%d\n",rez);
		}else if (op=='-'){
			rez=a-b;
			printf("x=%d\n",rez);
		}
	} else {
      scanf("x=%d", &b);
      printf("x=%d\n", (op=='+' ? b-a : a-b));
    }
  } else {
    scanf("x%c%d=%d", &op, &a, &b);
    printf("x=%d\n", (op=='+' ? b-a : b+a));
  }
  return 0;
}
