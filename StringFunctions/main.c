#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 200

char mystring[] = "On the 2nd day of Christmas my true love gave to me, 2 turtle doves and a partridge in a pear tree.";
char tens[] = "         10        20        30        40        50";
char nums[] = "123456789012345678901234567890123456789012345678901234567890";
// I will concat strings to msg1 and msg2 so I need to set aside enough memory (the array size)
// to accomodate the additional characters...
char msg1[MAXSTRLEN] = "Result1: ";
char msg2[MAXSTRLEN] = "Result2: ";
char myotherstr[6];

void showstring() {
	printf("\n\n%s\n", mystring);
	printf("%s\n%s\n", tens, nums);
}

void searchstring(char searchstr[]) {
	char *ptrtostr;
	int foundat;
	ptrtostr = strstr(mystring, searchstr);
	foundat = (int)((ptrtostr - mystring) + 1);
	if (ptrtostr != NULL)
		printf("\n'%s' found at position %d\n", searchstr, foundat);
	else
		printf("\n'%s' not found\n", searchstr);
}

void copystring() {
	// Many modern C11 compilers provide safer string functions ending with _s
	// This example shows strncpy_s but this is not yet supported by all compilers
	/*	strncpy_s(myotherstr, 6, "Easter", 4);
	printf("\nstrncpy_s: Copied this string: '%s'", myotherstr); */
	myotherstr[0] = 0;
	strncpy(myotherstr, "Easter", 4);
	printf("\nCopied this string: '%s'", myotherstr);
}

void concatstring() {
	strcat(msg1, "Easter");
	printf("\n\nstrcat: '%s'", msg1);
	strncat(msg2, "Easter", 4);
	printf("\nstrncat: '%s'\n", msg2);
}

int main(int argc, char **argv) {
	printf("Length of mystring = %d", strlen(mystring));
	printf("\nLength of 'Hello' = %d", strlen("Hello"));
	showstring();
	searchstring("2nd");
	searchstring("Christmas");
	searchstring("Easter");
	copystring();
	concatstring();
	return 0;
}