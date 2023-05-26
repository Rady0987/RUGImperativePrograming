/* file: hkpf.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: WED Sep 25 2019 */
/* version: 1.0 */
/* Description: This program accepts two positive integers on the input, 
 * and outputs their highest common prime factor*/
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, hcpf=1;
  
  scanf("%d %d", &a, &b);
  for(int i=2; (i <= a) && (i <= b); i++) {
    if ((a%i == 0) && (b%i == 0)) {//checks if d is a divisor of both
      hcpf = i;
    }
    while (a%i == 0) {
      a = a/i;
    }
    while (b%i == 0) {
      b = b/i;
    }
  }
  printf("%d\n", hcpf);
  return 0;
}
