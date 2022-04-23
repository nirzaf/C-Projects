#include <stdio.h>

int main(int argc, char **argv) {
	int subtotal;
	int tax;
	int grandtotal;
	double taxrate;

	taxrate = 0.175;
	subtotal = 250;
	tax = subtotal * taxrate;					// this should produce a warning message about possible data loss
	grandtotal = subtotal + tax;

	printf("The tax on %d is %d, so the grand total is %d.\n", subtotal, tax, grandtotal);
	return 0;
}