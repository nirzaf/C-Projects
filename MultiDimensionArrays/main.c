#include <stdio.h>

int grid[3][5] = {
	{ 1,   2,   3,   4,   5  },
	{ 6,   7,   8,   9,   10 },
	{ 11,  12,  13,  14,  15 }
};

int main(int argc, char **argv) {
	int row;
	int column;

	for (row = 0; row < 3; row++) {
		printf("--- row %d --- \n", row);
		for (column = 0; column < 5; column++) {
			printf("column[%d], value=%d\n", column, grid[row][column]);
			// uncomment the code below to see how to break out of the inner 'for' loop
			// If I were to put a break here it would break out of the INNER 'for'
			// loop only
			/*
			if (column == 2) {
			break;
			}
			*/
		}
	}
	return 0;
}