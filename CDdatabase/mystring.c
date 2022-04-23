#include <stdio.h>
#include <string.h>
#include "mystring.h"

// reads line from input and returns length of string
int readln(char s[]) {
	char ch;
	int i;
	int chars_remain;

	i = 0;
	chars_remain = 1;
	while (chars_remain) {
		ch = getchar();
		if ((ch == '\n') || (ch == EOF)) {
			chars_remain = 0;
		} else if (i < MAXSTRLEN - 1) {
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0';
	return i;
}

// returns index (0-based) of first char of searchstring in sourcestring
// or -1 if searchstring is not found
int searchstring(char searchstr[], char sourcestr[]) {
	char *ptrtostr;
	int foundat;

	foundat = -1;
	ptrtostr = strstr(sourcestr, searchstr);
	if (ptrtostr != NULL) {
		foundat = (int)((ptrtostr - sourcestr));
	}
	return foundat;
}