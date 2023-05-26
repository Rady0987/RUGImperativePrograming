#include <stdio.h>
#include <stdlib.h>

int isMatch(char *pattern, char *string) {
   if(pattern[0] == '\0' || string == '\0') 
      return 1;

   if(pattern[0] == string[0])
      return isMatch(pattern + 1, string + 1);

/* Implement the body of this function.
* Moreover, this function must be recursive, or
* it should call a recursive helper function.
*/
}
int main(int argc, char *argv[]) {
   char pattern[30], string[30];
   scanf("%s %s", pattern, string);
   if (isMatch(pattern, string) == 0) {
      printf("NO ");
   }
   printf("MATCH\n");
   return 0;
}