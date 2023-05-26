/* file: crack.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 3 Oct 2020 */
/* version: 1.0 */
/* Description: This program outputs YES if there exists a code book 
such that encrypting the first string using this code book yields the second string, and NO otherwise. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This function initialize the map with '@' */
void initializeMap(char* encryptMap) {
   for (int i = 0; i < 26; i++) {
      encryptMap[i] = '@';
   }
}

/* This function loops through the words and adds each new letter to the map, 
if the map index of a letter is already filled checks the mapping */
int checkEncryption(char* wordOne, char* wordTwo) {
   int n = 0;
   char encryptMap[26];
   initializeMap(encryptMap);
   while(n != strlen(wordTwo)) {
      if (encryptMap[wordOne[n] - 'A'] == '@') {
         encryptMap[wordOne[n] - 'A'] = wordTwo[n];
      } else {
         if (encryptMap[wordOne[n] - 'A'] != wordTwo[n])
         return 0;
      }
      n++;
   }
   /* Check for edge cases when two letters from the first word are mapped to the same */
   for(int i = 0; i < 26; i++) {
      for(int j = i + 1; j < 26; j++) {
         if(encryptMap[i] == encryptMap[j] && encryptMap[i] != '@') {
            return 0;
         }
      }
   }
   return 1;
}

int main(int argc, char* argv[]) {
   char wordOne[100], wordTwo[100];
   int result;
   scanf("%s", wordOne);
   scanf("%s", wordTwo);
   result = checkEncryption(wordOne, wordTwo);
   if (result == 1) {
      printf("YES\n");
   } else {
      printf("NO\n");
   }
   return 0;
}