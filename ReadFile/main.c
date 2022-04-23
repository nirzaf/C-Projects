#include <stdio.h>
#include <stdlib.h>

void readin(char *filename) {
	FILE *f;
	long size;
	char *b;
	size_t items_read;  				// size_t is a long unsigned int
	int linecount;
	int i;

	linecount = 0;
	f = fopen(filename, "rb");			// open file read only in binary mode
	if (f == NULL){						// get out if no good
		printf("Cannot open '%s'\n", filename);
	} else {
		fseek(f, 0, SEEK_END);			// seek to end of file
		size = ftell(f);				// get the current position (now at the end of the file)
		rewind(f);						// move the seek pointer to the start
		b = malloc(size);				// alloc some memory
		if (b == NULL) {
			printf("help!!\n");
		} else {
			items_read = fread(b, 1, size, f);		// read the lot in
			fclose(f);						// close it
			for (i = 0; i < size; i++) {
				if (b[i] == '\n') {
					linecount++;
				}
			}
			linecount++;				// the last line doesn't have a line feed at the end
			printf("number of lines was %d with %d chars (%d items read).\n", linecount, i, items_read);
			free(b);
		}
	}
}

int main(int argc, char **argv) {
	readin("sonnet.txt");
	return 0;
}