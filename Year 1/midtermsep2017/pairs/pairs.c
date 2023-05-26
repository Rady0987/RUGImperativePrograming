/* file: pairs.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: WED Sep 25 2019 */
/* version: 1.0 */
/* Description: This program */
 
#include <stdio.h>
#include <stdlib.h>

int divSum(int n){
  int sum = 1;
  for(int i=2; 2*i <= n; i++){
    if (n%i == 0) {
      sum += i;
    }
  }
  return sum;
}


int main(int argc, char *argv[]){
  int n1, n2;
  scanf("%d %d", &n1, &n2);
  if (divSum(n1)==n2 && divSum(n2)==n1){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
