/* file: abc.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Tue Sep 1 2019 */
/* version: 1.0 */
/* Description: This program */

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *string;
  int index, curentLength = 1, nbrOfA, nbrOfB, nbrOfC;
  string = (char *) malloc(sizeof(char));
  scanf("%s", string);
  while (string[curentLength] != '\0') {
    nbrOfA = 0;
    nbrOfB = 0;
    nbrOfC = 0;
    index = 0;
    while (index < curentLength) {
      if (string[index] == 'a')
        nbrOfA++;
      if (string[index] == 'b')
        nbrOfB++;
      if (string[index] == 'c')
        nbrOfC++;
      index++;
    }
    if ((nbrOfB > nbrOfA) || (nbrOfC > (nbrOfB + nbrOfA))){
      printf("INVALID\n");
      return 0;
    }
    curentLength++;
  }
  free(string);
  printf("VALID\n");
  return 0; 
}
