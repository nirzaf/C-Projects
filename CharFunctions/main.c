#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mystring[] = "On the 2nd day of Christmas my true love gave to me, 2 turtle doves and a partridge in a pear tree.";

void chartypes() {
	int i;
	char c;
	int numDigits = 0;
	int numLetters = 0;
	int numUpCase = 0;
	int numLowCase = 0;
	int numSpaces = 0;
	int numPunct = 0;
	int numCtrl = 0;
	int numUnknown = 0;
	int lengthOfStr;

	lengthOfStr = strlen(mystring);

	for (i = 0; i < lengthOfStr; i++) {
		c = mystring[i];
		if (isalpha(c)) {
			numLetters++;
			if (isupper(c)) {
				printf("'%c' [uppercase character]\n", c);
				numUpCase++;
			} else {
				printf("'%c' [lowercase character]\n", c);
				numLowCase++;
			}
		} else if (isdigit(c)) {
			printf("'%c' [digit]\n", c);
			numDigits++;
		} else if (ispunct(c)) {
			printf("'%c' [punctuation]\n", c);
			numPunct++;
		} else if (isblank(c)) {
			printf("'%c' [blank]\n", c);
			numSpaces++;
		} else if (iscntrl(c)) {
			printf("'%c' [ctrl]\n", c);
			numCtrl++;
		} else {
			printf("'%c' [unknown]\n", c);
			numUnknown++;
		}
	}
	printf("This string contains %d characters: %d letters (%d uppercase, %d lowercase)\n", lengthOfStr, numLetters, numUpCase, numLowCase);
	printf("%d digits, %d ctrl, %d punctuation characters, %d spaces and %d unclassified characters.\n", numDigits, numCtrl, numPunct, numSpaces, numUnknown);
}

int main(int argc, char **argv) {
	if (isalpha('x')) { 		// try delimiting x as a string instead of a char: "x"
		printf("'x' is a letter\n");
	} else {
		printf("'x' is not a letter\n");
	}
	chartypes();
	return 0;
}