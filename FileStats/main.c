#include <stdio.h>

#define MAXSTRLEN 200
#define FILENAME "sonnet.txt"
#define EMPTYFILENAME "empty.txt"
#define INVALIDFILENAME "not_here.txt"

void linecount(char *fn) {
	int numlines = 0;
	char line[MAXSTRLEN];

	FILE *fp = fopen(fn, "r");
	if (fp != NULL) {
		while (fgets(line, sizeof(line), fp) != 0) {
			numlines++;
		}
		fclose(fp);
		printf("%s contains %d lines of text.\n", fn, numlines);
	} else {
		printf("File %s cannot be opened!\n", fn);
	}
}

int main(int argc, char **argv) {
	linecount(FILENAME);
	linecount(EMPTYFILENAME);
	linecount(INVALIDFILENAME);
	return 0;
}