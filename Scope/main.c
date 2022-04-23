#include <stdio.h>
#include "mystring.h"

// Global scope
char b[MAXSTRLEN];
char teststring[] = "Hello world";
int num = 10;

void addnumbers() {
	static int x = 0;
	int y = 0;

	x++;
	y++;
	printf("In addnumbers() x=%d, y=%d\n", x, y);
}

void globalnum() {
	printf("In globalnum, num is %d\n", num);
}

void localnum() {
	int num;

	num = 100;
	printf("In localnum, num is %d\n", num);
}

int main(int argc, char **argv) {
	int i;
	//int stringpos;

	printf("starting...\n");
	i = readln(b, sizeof(b));
	printf("b=%s; i=%d\n", b, i);
	/* // --- This can't be run as long as searchstring() is a static function
	stringpos = searchstring(b, teststring);
	if(stringpos > -1){
	printf( "'%s' found in '%s' at index #%d\n", b, teststring, stringpos);
	}else{
	printf( "'%s' not found in '%s'\n", b, teststring);
	}
	*/
	printf(findsubstring(b, teststring));
	localnum();
	globalnum();
	addnumbers();
	addnumbers();
	addnumbers();
	return 0;
}