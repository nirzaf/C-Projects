#include<stdio.h>

void switchtest(int x) {
	int i = 0;

	switch (x) {
	case 0:
		i += 0;
		break;
	case 1:
		i += 1;
		break;
	default:
		i += 100;
		// break;
	case 2:
		i += 2;
		break;
	}
	printf("x=%d, i=%d\n", x, i);
}

int main(int argc, char** argv) {
	for (int i = 0; i < 4; i++) {
		switchtest(i);
	}
	return 0;
}