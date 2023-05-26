/* file: enclosed.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: WED Sep 25 2019 */
/* version: 1.0 */
/* Description: This program */

#include <stdio.h>

int main() {
  int x1, x2, y1, y2, xtr1, xtr2, xtr3, ytr1, ytr2, ytr3;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &xtr1, &ytr1);
  scanf("%d %d", &xtr2, &ytr2);
  scanf("%d %d", &xtr3, &ytr3);
  if ((x1 <= xtr1 && x1 <= xtr2 && x1 <= xtr3 && x2 >= xtr1 && x2 >= xtr2 && x2 >= xtr3) ||
  (x1 >= xtr1 && x1 >= xtr2 && x1 >= xtr3 && x2 <= xtr1 && x2 <= xtr2 && x2 <= xtr3)) {
    if ((y1 <= ytr1 && y1 <= ytr2 && y1 <= ytr3 && y2 >= ytr1 && y2 >= ytr2 && y2 >= ytr3) ||
    (y1 >= ytr1 && y1 >= ytr2 && y1 >= ytr3 && y2 <= ytr1 && y2 <= ytr2 && y2 <= ytr3)) {
      printf("%s\n", "YES");
    } else {
      printf("%s\n", "NO");
    }
  } else {
    printf("%s\n", "NO");
  }
    return (0);
}

