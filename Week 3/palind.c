/* file: palind.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 27 sep 2020 */
/* version: 1.0 */
/* Description: This program reads two integers p and q, where p is the 
smallest palindromic number p such that p ≥ n which can be written as the sum
of two palindromic numbers. */

#include <stdio.h>
#include <stdlib.h> 

//This function checks if a number is a palindrome
int isPalindrome(int n) {
   int revN = 0, initN;
   initN = n;
   //Computes the reverse of the number
   while(n != 0) {
      revN = revN * 10 + n % 10;
      n /= 10;
   }
   //If the reverse is equal to the copy of the initial value -> palindrome
   if(initN == revN) {
      return 1;
   } else {
      return 0;
   }
}

//This function takes an int and returns the next palindrome greater than n
int nextPalindrme(int n) {
   while(!isPalindrome(n)){
      n++;
   }
   return n;
}

//The main function with the loop for finding palindromes and their sum
int main(int argc, char* argv[]) {
   int n, counter = 0, sum = 0;
   scanf("%d", &n);
   //Iterate until we find the right values
   while(counter == 0) {
      //In case of unsuccessful verification we should find the next palindrome
      n = nextPalindrme(n);
      //Iterate to the half of the n, because the numbers of the sum are eqal and at most half of n
      for(int i = 1; i <= (n / 2); i++) {
         sum = i + (n-i);
         //Check the values
         if(isPalindrome(i) && isPalindrome(n - i) &&  sum == n)
            counter++;
      }
      //Increment n if the prev values were not satisfiable
      if(counter == 0)
         n++;
   } 
   printf("%d %d\n", n, counter);
   return 0;
}