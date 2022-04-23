#include <stdio.h>

int main(int argc, char **argv) {
	char str1[] = "Hello";
	char *str2 = "Goodbye";

	// str2 = &str1;
	// str2 = str1;
	printf("%d %d %s\n", &str1, str1, str1);
	printf("%d %d %s\n", &str2, str2, str2);
	return 0;
}