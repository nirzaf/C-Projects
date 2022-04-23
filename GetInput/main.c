#include <stdio.h>

char *gets(char*);		// no longer defined in C11 standard

void flush_input() {
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF);
}

void getinput_with_gets() {
	char firstname[5];
	char lastname[5];

	printf("Enter your first name:");
	gets(firstname);
	printf("Enter your last name:");
	gets(lastname);
	printf("Hello, %s, %s\n", firstname, lastname);
}


void getinput_with_fgets() {
	char firstname[5];
	char lastname[5];

	printf("Enter your first name:");
	fgets(firstname, 5, stdin);
	printf("Enter your last name:");
	// fflush(stdin);	// This function may not (invariably) work with input!
	// Try commenting out the next line
	flush_input();
	fgets(lastname, 5, stdin);
	// Try commenting out the next line
	flush_input();
	printf("Hello, %s, %s\n", firstname, lastname);
}

int main(int argc, char **argv) {
	/*
	Try uncommenting to the call (below) to
		getinput_with_gets();
	When promptedm enter:
		1234567890
	And:
		abcdfeghi

	The actual behaviour of the program is unpredictable. In all probability
	it will crash.

	Now comment out that function call to execute
		getinput_with_fgets();
	Try entering the same data when prompted. Now the entered strings are truncated.
	But the program will not crash.
	*/

	// getinput_with_gets();
	getinput_with_fgets();
	return 0;
}