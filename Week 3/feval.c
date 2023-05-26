/* file: feval.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 26 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the number that is the 
output that is obtained by applying the given sequence of 
functions to the input number  */

#include <stdio.h>
#include <stdlib.h> 

//This function takes n and returns the sum of divisors 
int g(int n) {
   int sum = 0;
   //Iterate to the square root of number
   for(int i = 1; i * i <= n; i++) {
      //Check if divisible
      if(n % i == 0) {
         //In case the divisors are eqal we add only one
         if (n / i == i) {
            sum += i;
         } else {
            sum += i + n/i;  
         }
      }
   }
   return sum;
}

//This function returns the reverse of input n
int f(int n) {
   int rev = 0;
   //While n is not 0, add each digit to the rev
   while(n != 0) {
      rev *= 10;
      rev += n % 10;
      n /= 10;
   }
   return rev;
}

//This function returns the sum of the digits
int h(int n) {
   int sum = 0;
   while (n != 0) {
      sum += n % 10;
      n /= 10;
   }
   return sum;
}

int main(int argc, char *argv[]) {
   int n, rez;
   char s;
   scanf("%d", &n);
   getchar();
   s = getchar();
   while(s != '=') {
      if(s == 'f')
         rez = f(n);

      if(s == 'h')
         rez = h(n);

      if(s == 'g')
         rez = g(n);

      n = rez;
      s = getchar();
   }
   printf("%d\n", n);
   return 0;
}