#include <stdio.h>

int intarray[] = { 1,2,3,4,5 };
/*
double doublearray2[] = {2.1, 2.3, 2.4, 2.5};
char chararray[] = {'h', 'e', 'l', 'l', 'o', '\0' };
char chararray2[] = "world";
* */


int main(int argc, char **argv) {
	int i;

	for (i = 0; i < 5; i++) {
		intarray[i] = (i + 1) * 100; // note use of parentheses here!
	}

	printf("--- for loop ---\n");
	for (i = 0; i < 5; i++) {
		printf("%d\n", intarray[i]);
	}

	printf("--- while loop (i = 0) ---\n");
	i = 0;
	while (i < 5) {
		printf("%d\n", intarray[i]);
		i++;
	}

	printf("--- do...while loop (i = 0) ---\n");
	i = 0;
	do {
		printf("%d\n", intarray[i]);
		i++;
	} while (i < 5);

	printf("--- while loop (i = 5) ---\n");
	i = 5;
	while (i < 5) {
		printf("%d\n", intarray[i]);
		i++;
	}

	printf("--- do...while loop (i = 5) ---\n");
	i = 5;
	do {
		printf("%d\n", intarray[i]);
		i++;
	} while (i < 10);
	/*
	printf("%s", chararray);
	printf(" %s", chararray2); */
	return 0;
}