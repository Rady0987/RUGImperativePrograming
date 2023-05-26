/* file: stableford.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 25 2019 */
/* version: 1.0 */
/* Description: This program .*/
 
#include <stdio.h>

int main(int argc, char *argv[]) {
  int par, index, handicap, strokes, score=0;
  scanf("%d", &handicap);
  for (int hole=0; hole<18; hole++) {
    scanf("%d %d %d", &par, &index, &strokes);
    par += handicap/18 + (index <= handicap%18);
    if (strokes < par + 2) {
      score += 2 + par - strokes;
    }  
  }

  printf("%d\n", score);
  return 0;
}
