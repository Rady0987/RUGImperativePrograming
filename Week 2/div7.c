/* file: div7.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 20 sep 2020 */
/* version: 1.0 */
/* Description: This program reads from the input 
an integer n (where n > 0) and outputs the number of steps that 
this method makes to determine whether n is divisible by 3 or not  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int n, steps = 0;
   scanf("%d", &n);
   while(n > 7 && n != 49) {
      n = n / 10 + 5 * (n % 10);
      steps++;
   };
   printf("%d\n", steps);
   if(n == 7 || n == 49) {
      printf("YES\n");
   } else {
      printf("NO\n");
   };
   return 0;
}