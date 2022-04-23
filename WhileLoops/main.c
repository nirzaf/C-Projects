#include <stdio.h>

void dowhiletest() {
	char c;
	c = 'y';
	printf("\ngetchar() with do...while loop...\n");
	do {
		printf("\nEnter y or n: ");
		c = getchar();
		getchar();
	} while (c != 'y');
	printf("\nThat's all folks!\n");
}

void whiletest() {
	char c;
	c = 'y';
	printf("\ngetchar() with while loop...\n");
	while (c != 'y') {
		printf("\nEnter y or n: ");
		c = getchar();
		getchar();
	}
	printf("\nThat's all folks!\n");
}

int main(int argc, char **argv) {
	whiletest();
	dowhiletest();
	return 0;
}