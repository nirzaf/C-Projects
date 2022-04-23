#include <stdio.h>

char *chartype;

void findchartype2(char c) {
	switch (c) {
	case '\0':
		chartype = "Null";
		break;
	case '\t':
		chartype = "Tab";
		break;
	case '\n':
		chartype = "LineFeed";
		break;
	case '\r':
		chartype = "Carriage Return";
		break;
	case ' ':
		chartype = "Space";
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		chartype = "Number";
		break;
		/*
		case 'A' ... 'Z':
		chartype = "Uppercase Letter";
		break;
		case 'a' ... 'z':
		chartype = "Lowercase Letter";
		break;
		*/
	default:
		chartype = "Character";
		break;
	}
}


void findchartype(int i) {
	switch (i) {
	case 0:
		chartype = "Null";
		break;
	case 7:
		chartype = "Bell";
		break;
	case 8:
		chartype = "BackSpace";
		break;
	case 9:
		chartype = "Tab";
		break;
	case 10:
		chartype = "LineFeed";
		break;
	case 13:
		chartype = "Carriage Return";
		break;
	case 32:
		chartype = "Space";
		break;
	case 48:
	case 49:
	case 50:
	case 51:
	case 52:
	case 53:
	case 54:
	case 55:
	case 56:
	case 57:
		chartype = "Number";
		break;
		/*
		// These use ranges (values between 65 and 90; values between 97 and 122)
		// Ranges in Switch/case are an extension to standard C and this syntax
		// is not supported by all C compilers
		case 65 ... 90:
		chartype = "Uppercase Letter";
		break;
		case 97 ... 122:
		chartype = "Lowercase Letter";
		break;
		*/
	default:
		chartype = "Character"; // This is a single line comment
		break;
	}
}


void showascii() {
	int i;
	char c;

	for (i = 0; i <= 127; i++) {
		findchartype(i);
		printf("%d = %c\t\t[%s]\n", i, i, chartype);
	}
	printf("\nPress Enter to continue...\n");
	c = getchar();
	for (i = 0; i <= 127; i++) {
		findchartype2(i);
		printf("%d = %c\t\t[%s]\n", i, i, chartype);
	}
}

int main(int argc, char **argv) {
	showascii();
	return 0;
}