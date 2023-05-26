/* file: rook.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: Wed Sep 2 2019 */
/* version: 1.0 */
/* Description: This program */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	char c;
	int row, col, dr, dc;
	scanf("%c", &c);
	scanf("%d", &row);
	col = c - 'a' + 1;
	scanf("%d", &dc);
	scanf("%d", &dr);
	while (dc != 0 || dr != 0){
		row += dr;
		col += dc;
		if (( dc && dr) || (dc == dr) || row < 1 || row > 8 || col < 1 || col > 8){
			printf ("INVALID\n");
			return 0;
		}
		scanf ("%d", &dc);
		scanf ("%d", &dr);
	}
	printf ("%c%d\n", col-1+'a', row);
	return 0;
}
