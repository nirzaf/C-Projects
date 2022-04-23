#include <stdio.h>

#define MAXSTRLEN 200
#define FILENAME "test.txt"

void readlines() {
	FILE *fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];

	if (fp != NULL) {
		while (fgets(line, sizeof(line), fp) != 0) {
			fputs(line, stdout);
		}
		fclose(fp);
	} else {
		printf("File %s cannot be opened!", FILENAME);
	}
}

void writelines() {
	FILE *fp;

	fp = fopen(FILENAME, "w");
	fputs("Hello world\n", fp);
	fputs("Goodbye Mars\n", fp);
	fclose(fp);
}

void clearfile() {
	FILE *fp;

	fp = fopen(FILENAME, "w");
	fclose(fp);
}

void deletefile() {
	if (remove(FILENAME) == 0) {
		printf("%s file deleted.\n", FILENAME);
	} else {
		printf("Unable to delete the file: %s.\n", FILENAME);
	}
}

int main(int argc, char **argv) {
	// deletefile();
	// clearfile();
	writelines();
	readlines();
	return 0;
}