#include <stdio.h>

int main(int argc, char **argv) {
#define TAXRATE_DEFINED 0.175
	const double TAXRATE_CONST = 0.175;

	double subtotal;
	double tax;
	double grandtotal;
	double taxrate;


	taxrate = 0.175;
	subtotal = 200;
	taxrate = 0.2;					// redefine a variable
	tax = subtotal * taxrate;
	grandtotal = subtotal + tax;

	printf("(taxrate is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\n", taxrate, subtotal, tax, grandtotal);

	subtotal = 200;
#define TAXRATE_DEFINED 0.2			// redefine a #define 'constant' - this should produce a warning message
	tax = subtotal * TAXRATE_DEFINED;
	grandtotal = subtotal + tax;

	printf("(TAXRATE_DEFINED is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\n", TAXRATE_DEFINED, subtotal, tax, grandtotal);


	subtotal = 200;
	// TAXRATE_CONST = 0.2;			// cannot redefine a true constant!
	tax = subtotal * TAXRATE_CONST;
	grandtotal = subtotal + tax;

	printf("(TAXRATE_CONST is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\n", TAXRATE_CONST, subtotal, tax, grandtotal);

	return 0;
}