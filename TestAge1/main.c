#include <stdio.h>
#include <stdlib.h>

char *gets(char*);		// no longer defined in C11 standard

int main(int argc, char **argv) {
	char agestring[10];
	int age;
	int bonus;

	printf("Enter your age : ");
	gets(agestring);
	age = atoi(agestring);
	if (age > 45) {
		bonus = 1000;
	} else {
		bonus = 500;
	}
	printf("Your age is %d, so your bonus is %d.\n", age, bonus);

	return(0);
}