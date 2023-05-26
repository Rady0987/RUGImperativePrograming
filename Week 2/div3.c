/* file: div3.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 20 sep 2020 */
/* version: 1.0 */
/* Description: This program reads from the input 
an integer n (where n > 9) and outputs the steps that 
this method makes to determine whether n is divisible by 3 or not  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int n, sum = 0;
   scanf("%d", &n);
   printf("%d", n);
   do {
      sum = 0;
      while (n != 0) {
         sum += n % 10;
         n /= 10;
      };
      printf(" -> %d", sum);
      n = sum;
   } while(n >= 10);
   printf("\n");
   if (sum == 3 || sum == 9 || sum == 6) {
      printf("YES\n");
   } else {
      printf("NO\n");
   };
   return 0;
}