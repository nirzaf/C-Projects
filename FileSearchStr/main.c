#include <stdio.h>
#include <string.h>

#define FILENAME "sonnet.txt"
#define MAXSTRLEN 200

// returns index (0-based) of first char of searchstring in sourcestring
// or -1 if searchstring is not found
static int searchstring(char searchstr[], char sourcestr[]) {
	char *ptrtostr;
	int foundat;

	foundat = -1;
	ptrtostr = strstr(sourcestr, searchstr);
	if (ptrtostr != 0) {
		foundat = (int)((ptrtostr - sourcestr));
	}
	return foundat;
}

void findstrings(char *fileName, char *ss) {
	FILE *f;
	int count;
	char line[MAXSTRLEN];

	f = fopen(fileName, "r");			// open file read only
	if (f == NULL) {
		printf("Can't open the file: '%s'\n", FILENAME);
	} else {
		count = 0;						// initialize the count
		while (fgets(line, MAXSTRLEN, f) != 0) {
			if (searchstring(ss, line) >= 0) {
				count++;
			}
		}
		printf("'%s' was found in %d lines\n", ss, count);
		fclose(f);						// close it
	}
}

int main(int argc, char **argv) {
	findstrings(FILENAME, "then");
	findstrings(FILENAME, "my");
	findstrings(FILENAME, "snodgrass");
	return 0;
}