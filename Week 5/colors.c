/* file:    colors.c              */
/* author:  Radu Rusu (email:rusu@student.rug.nl) */
/* date:    12.10.2020               */
/* version: 1.0                */
/* Description: This program outputs the solution of the puzzle that is a grid in which
some cells have been coloured already, the puzzle is to colour the remaining cells such that no
cell has a neighbour (north, east, south, west) with the same colour, or ’NO SOLUTION’ if no solution
exists */

#include <stdlib.h>
#include <stdio.h>

/* This function allocates memory to an array */
void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

/* This function dynamically allocates memory for a new 2D grid */
char **makeNewGrid(int width, int height) { 
	char **grid;
	grid = safeMalloc(height * sizeof(char *)); 
	for (int row = 0; row < height; row++) {
		grid[row] = safeMalloc(width * sizeof(char));
	}
	return grid;
}

/* This function reads the input 2D array */
void readPuzzle (char **puzzle) {
	for (int i = 0; i < 9 ; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%c", &puzzle[i][j]);
			if (j == 8) 
				getchar();
		}
	}
}

/* This function checks how many similar letters are in a given column */
int checkColumn (char **puzzle, char letter, int col) {
	int columnLetter = 0;
	for (int i = 0; i < 9; i++) {
		if (puzzle[i][col] == letter) {
			columnLetter++; 
		}
	}
	if (columnLetter <= 1) 
		return 1;
	return 0;
}

/* This function checks how many similar letters are in a given row */
int checkRow (char **puzzle, char letter, int row) {
	int rowLetter = 0;
	for (int i = 0; i < 9 ; i++) {
		if (puzzle[row][i] == letter) {
			rowLetter++;
		}
	}
	if (rowLetter <= 1) 
		return 1;
	return 0;
}

/* This function returns 1 if the input indexes is the corner element */
int isBound(int row, int column) {
	 /* NORTH-WEST*/
	if (row == 0 && column == 0) 
		return 1;
	/*NORTH-EAST*/
	if (row == 0 && column == 8) 
		return 1; 
	/*SOUTH-WEST*/
	if (row == 8 && column == 0) 
		return 1; 
	/*SOUTH-EAST*/
	if (row == 8 && column == 8) 
		return 1; 
	return 0;
}

/* This function checks the neighbours of the corner elements */
int fitsBounds(char **puzzle, char letter, int row, int col) {
	if (row == 0) {
		if (col == 0 && puzzle[row + 1][col] != letter && puzzle[row][col + 1] != letter) 
			return 1; 
		if (col == 8 && puzzle[row + 1][col] != letter && puzzle[row][col -1] != letter)
			return 1; 
	}
	if (row == 8) {
		if (col == 8 && puzzle[row - 1][col] != letter && puzzle[row][col - 1] != letter) 
			return 1; 
		if (col == 0 && puzzle[row - 1][col] != letter && puzzle[row][col +1] != letter) 
			return 1; 
	}
	return 0;
}

/* This function checks if we do not have a same letter in the neighbourhood as the currrent one*/
int fitsNeighbours(char **puzzle, char letter, int row, int col) {
	/* The first row -> no NORTH elements */
	if (row == 0 && !isBound(row,col)) { 
		if (puzzle[row +1][col] != letter && puzzle[row][col + 1] != letter && puzzle[row][col - 1] != letter) 
			return 1;
	}
	/*The first column -> no WEST elements */
	if (col == 0 && !isBound(row,col)) {
		if (puzzle[row][col + 1] != letter && puzzle[row +1][col] != letter && puzzle[row - 1][col] != letter) 
			return 1;
	}
	/* The last row -> no SOUTH elements */
	if (row == 8 && !isBound(row,col)) {
		if (puzzle[row - 1][col] != letter && puzzle[row][col + 1] != letter && puzzle[row][col - 1] != letter) 
			return 1;
	}
	/* The last column -> no EAST elements */
	if (col == 8 && !isBound(row,col)) { 
		if (puzzle[row][col - 1] != letter && puzzle[row +1][col] != letter && puzzle[row - 1][col] != letter) 
			return 1;
	}
	/* Element != 1s row || last row -> check all 4 neighbours */
	if (!isBound(row,col) && row != 0) { 
		if (puzzle[row - 1][col] != letter && puzzle[row +1][col] != letter && puzzle[row][col + 1] != letter && puzzle[row][col - 1] != letter) 
			return 1;
	}
	/* Special test for bound elements */
	if (isBound(row,col) != 0) {
		if (fitsBounds(puzzle,letter,row,col)) 
			return 1;		
	}
	return 0;
}


/* This function tests and decides if a letter can be placed in a certain position */
int validLetter (char **puzzle, char letter, int row, int column) {
	return checkColumn(puzzle, letter, column) && checkRow(puzzle, letter, row) && 
	fitsNeighbours(puzzle, letter, row, column);
}

/* This function returns via pointers the column and row of a wildcard */
int nextWildCard(char **puzzle, int *row, int *col) {
	for (*row = 0; *row < 9; (*row)++) {
		for (*col = 0; *col < 9; (*col)++) {
			if (puzzle[*row][*col] == '#') {
				return 1;
			}
		}
	}
	/* If there are no more wildcards in the grid return 0 */
	return 0;
}

/* This function recursively solves the puzzle, looking for suitable letters for each # */
int solverFunction(char **puzzle) {
	char letters[5] = {'G', 'Y', 'R', 'W', 'B'};
	int r = 0, c = 0;
	/* The base case, when we cannot find any more wildcars, function returns 1 */
	if (!nextWildCard(puzzle, &r, &c)) 
		return 1;
	for (int i = 0; i < 5; i++) {
		if (validLetter(puzzle, letters[i], r, c)) {
			puzzle[r][c] = letters[i];
			if (solverFunction(puzzle)) 
				return 1;
			puzzle[r][c] = '#';
		}
	}
	return 0;
}

/* This function prints the output 2D array */
void printPuzzle (char **puzzle) {
	for (int i = 0; i < 9 ; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%c", puzzle[i][j]);
			if (j == 8) 
				printf("\n");
		}
	}
}

/* This function frees the memory of the grid */
void destroyIntArray2D(char **arr, int x) { 
	for (int i = 0; i < x; i++){
		free(arr[i]); 
	}
	free(arr);
}

int main(int argc, char *argv[]) {
	//char puzzle[9][9];
	char **puzzle = makeNewGrid(9, 9);
	readPuzzle(puzzle);
	/* Solver function should return 1 in order to print the grid */
	if (solverFunction(puzzle)) { 
		printPuzzle(puzzle);
	} else {
		printf("NO SOLUTION\n");
	}
	destroyIntArray2D(puzzle, 9);
	return 0;
}
