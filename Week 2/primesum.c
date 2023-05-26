/* file: primesum.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 21 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the sum of all prime numbers in this series.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int main(int argc, char *argv[]) {
   int n, sum = 0;
   bool flag;
   scanf("%d", &n);
   while (n != 0) {
      flag = true;
// Eliminates the even and and numbers below 1 
      if (n > 1 && (n % 2 != 0 || n == 2) && n >= 2) {
// Iterates for 3 to the sqrt of n and checks if n divides by that number (prime check)
         for (int i = 3; i * i <= n ; i += 2) { 
            if(n % i == 0) {
               flag = false;
               break;
            }
         }
// If the number is prime, flag is true and it is added to sum.
         if (flag) { 
            sum += n;
         } 
      }
      scanf("%d", &n);
   }
   printf("%d\n", sum);
   return 0;
}
