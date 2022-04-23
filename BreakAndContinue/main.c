#include <stdio.h>

char chararray[] = "Hello world! Goodbye";

void whilebreak() {
	int i;
	char c;
	char str[50];

	i = 0;
	while (i >= 0) {
		c = chararray[i];
		printf("[%d]='%c' ", i, c);
		if (c == '!') {
			str[i] = '\0';
			break;
		}
		str[i] = c;
		i++;
	}
	printf("\nAfter while loop, str='%s'", str);
}

void forbreak() {
	int i;
	char str[50];
	char c;

	// for loop #1 - encrypt string
	for (i = 0; i < 50; i++) {
		c = chararray[i];
		if (c == ' ') {
			str[i] = c;
			continue;
		}
		if (c == '!') {
			str[i] = '\0';
			break;
		}
		str[i] = chararray[i] + 1;
	}
	printf("Encrypted string is '%s'\n", str);

	// for loop #2 - decrypt string
	for (i = 0; i < 50; i++) {
		c = str[i];
		if (c == ' ') {
			continue;
		}
		if (c == '\0') {
			break;
		}

		str[i] = str[i] - 1;
	}
	printf("Decrypted string is '%s'\n", str);
}

int main(int argc, char **argv) {
	forbreak();
	whilebreak();
	return 0;
}