#include <stdio.h>

int main(int argc, char **argv) {
	double subtotal;
	double tax;
	double grandtotal;
	double taxrate;

	taxrate = 0.175;
	subtotal = 250;
	tax = subtotal * taxrate;
	grandtotal = subtotal + tax;

	printf("The tax on %.2f is %.2f, so the grand total is %.2f.\n", subtotal, tax, grandtotal);
	return 0;
}