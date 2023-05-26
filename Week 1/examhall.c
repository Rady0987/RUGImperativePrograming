/* file: examhall.c */
/* author: Radu Rusu (email: rusu@student.rug.nl) */
/* date: 4 sep 2020 */
/* version: 1.0 */
/* Description: This program outputs the number of students
    that can do an exam at the same time  */

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
	int w, h, n, s;
	scanf("%d %d %d", &n, &w, &h);
	s = (w / n) * (h / n);
	printf("%d\n", s);
	return 0;
}