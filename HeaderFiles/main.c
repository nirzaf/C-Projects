#include <stdio.h>
#include "mystring.h" 

char b[BUFSIZE];
char teststring[] = "Hello world";

int main(int argc, char **argv) {
	int i;
	int stringpos;

	printf("starting...\n");
	i = readln(b, sizeof(b));
	printf("b=%s; i=%d\n", b, i);
	stringpos = searchstring(b, teststring);
	if (stringpos > -1) {
		printf("'%s' found in '%s' at index #%d\n", b, teststring, stringpos);
	} else {
		printf("'%s' not found in '%s'\n", b, teststring);
	}
	return 0;
}