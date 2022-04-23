#include <stdio.h>

void test() {
	{
		int i = 0;
		printf("%d\n", i);
	}
	// printf("%d\n", i); // <----- error
	for (int i = 0; i < 10; i++) {
		printf("%d\n", i);
	}
	// printf("%d\n", i); // <----- error	
}

int main(int argc, char **argv) {
	test();
	return 0;
}