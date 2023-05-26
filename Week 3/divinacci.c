/* file: divinacci.next */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 27 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the number that is the 
output that is obtained by applying the given sequence of 
functions to the input number  */

#include <stdio.h>
#include <stdlib.h> 

//This function takes n and returns the sum of divisors 
int divSum(int n) {
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

//This function takes n and returns the nth divinacci number 
int divinacci(int n) {
   int a = 0, b = 1, next;
   //The element 1 -> return 1
   if (n == 1)
      return b;
   //Start with 2nd element to n, add the prev numbers and compute the next
   for (int i = 2; i <= n; i++) {
      next = divSum(a) + divSum(b);
      //Switch the values 
      a = b;
      b = next;
   }
   return next;
}

int main(int argc, char* argv[]) {
   int n;
   scanf("%d", &n);
   printf("%d\n", divinacci(n));
   return 0;
}