/* file: eqsolver.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 21 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the number of combinations (a, b, c) 
(where a, b, c are non-negative integers) that satisfy the above equations. */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
   int m, n, p , q, r, a, b = 0, c = 0, combin = 0;
   scanf("%d %d %d %d %d", &m, &n, &p, &q, &r);
   // This 2 loops iterate over from m to 0 and vice versa in order to satisfy the formulas
   for(a = m; a >= 0; a--) { 
      for(b = 0; b <= m; b++) { 
         // Compute the c variable for future comparation
         if(m - b - a >= 0) 
            c = m - b - a;
            if((a * p + b * q + c * r == n) && (a + b + c == m)) 
               combin++;
      }
   }
   printf("%d\n", combin);
   return 0;
}
