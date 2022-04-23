#include <stdio.h>

#define somevalue 10
#define some_other_value 15
#define SERVICE_CHARGE 33

int do_something(int x) {
	return x + somevalue;
}

int Do_Something(int x) {
	return x + some_other_value;
}

int calculate_grand_total(int subtotal) {
	int grand_total;

	grand_total = subtotal + SERVICE_CHARGE;
	return grand_total;
}

int main(int argc, char **argv) {
	printf("%d\n", do_something(500));
	printf("%d\n", Do_Something(600));
	printf("%d\n", calculate_grand_total(700));
	return 0;
}