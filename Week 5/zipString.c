/* file: zipString.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: THU OCT 10 2020 */
/* version: 1.0 */
/* Description: This program determines whether the third string 
can be produced from the first two strings by zipping the first two strings
in such a way that the order of the letters of both strings is preserved.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function allocates memory to an array */
void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

/* This recursively checks if the third word can be produced out of the first two */
int checkZip(char* wordOne, char* wordTwo, char* wordZip, int n) {
   /* Check if we have enough letters to produce the zip word*/
   if(strlen(wordOne) + strlen(wordTwo) + n < strlen(wordZip)) {
      return 0;
   } else {

      /* Base case for the moment when we get to the end of all words*/
      if(wordOne[0] == '\0' && wordTwo[0] == '\0' && wordZip[0] == '\0') 
         return 1;

      /* If the first letter of word one is equal to the zip word one, 
      call the function with the strings pointing to the next letters*/
      if(wordOne[0] == wordZip[0])
         return checkZip(wordOne + 1, wordTwo, wordZip + 1, n);
      
      if(wordTwo[0] == wordZip[0])
         return checkZip(wordOne, wordTwo + 1, wordZip + 1, n);
      
      if(wordZip[0] != wordOne[0] && wordZip[0] != wordTwo[0] && n != 0)
         return checkZip(wordOne, wordTwo, wordZip + 1, n--);
   }
   return 0;
}

int main(int argc, char* argv[]) {
   int n, normal, viceversa;
   char *wordOne, *wordTwo, *wordZip;
   scanf("%d", &n);
   wordOne = safeMalloc(32 * sizeof(char));
   wordTwo = safeMalloc(32 * sizeof(char));
   wordZip = safeMalloc(32 * sizeof(char));
   getchar();
   scanf("%s", wordOne);
   scanf("%s", wordTwo);
   scanf("%s", wordZip);
   /* The check function is called twice to verify the case with swapped words*/
   normal = checkZip(wordOne, wordTwo, wordZip, n);
   viceversa = checkZip(wordTwo, wordOne, wordZip, n);
   if(normal || viceversa) {
      printf("YES\n");
   } else {
      printf("NO\n");
   }
   free(wordOne);
   free(wordZip);
   free(wordTwo);
   return 0;
}