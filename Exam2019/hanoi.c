/* file: hanoi.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 2020 */
/* version: 1.0 */
/* Description: This program outputs  */

#include <stdio.h>
#include <stdlib.h> 

int startRod(int n) {
   int rez = n;
   for(int i = n - 1; i > 0; i--) {
      rez *= 10; 
      rez += i;
   }
   return rez;
}

void initArr(int *arr) {
   for(int i = 0; i < 3; i++) {
      arr[i] = 0;
   }
}

int main(int argc, char *argv[]) {
   int n, m, arr[3], from, to;
   scanf("%d %d", &n, &m);
   initArr(arr);
   arr[0] =  startRod(n);
   for(int i = 0 ; i < m; i++) {
      scanf("%d->%d", &from, &to);
      // printf("%d->%d\n", from, to);
      if((arr[from] < arr[to] || arr[to] == 0) && arr[from] != 0) {
         arr[to] *= 10;
         arr[to] += arr[from] % 10;
         arr[from] /= 10;
            // printf("to =%d, from =%d\n", arr[to], arr[from]);
      } else {
         printf("ILLEGAL MOVE %d\n", i + 1);
         return 0;
      }
   }
   if(arr[1] == startRod(n) || arr[2] == startRod(n)) {
      printf("SOLVED\n");
   } else {
      printf("UNSOLVED\n");
   }
   
   return 0;
}