#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

// returns index (0-based) of first char of searchstring in sourcestring
// or -1 if searchstring is not found
static int searchstring(char searchstr[], char sourcestr[]) {
	char *ptrtostr;
	int foundat;

	foundat = -1;
	ptrtostr = strstr(sourcestr, searchstr);
	if (ptrtostr != NULL) {
		foundat = (int)((ptrtostr - sourcestr));
	}
	return foundat;
}

char *findsubstring(char searchstr[], char sourcestr[]) {
	char *s;
	int stringpos;

	s = malloc(MAXSTRLEN);
	s[0] = 0;		// need this to initialize the buffer created by malloc
	stringpos = searchstring(searchstr, sourcestr);
	if (stringpos > -1) {
		sprintf(s, "'%s' found in '%s' at index #%d\n", searchstr, sourcestr, stringpos);
	} else {
		sprintf(s, "'%s' not found in '%s'\n", searchstr, sourcestr);
	}
	return s;
}