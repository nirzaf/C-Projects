#include <stdio.h>

int main(int argc, char **argv) {
	int age;
	int number_of_children;
	double salary;

	age = 25;
	number_of_children = 1;
	salary = 20000.00;

	if ((age <= 30) && (salary >= 30000)) {
		printf("You are a rich young person\n");
	} else {
		printf("You are not a rich young person\n");
	}

	if ((age <= 30) || (salary >= 30000)) {
		printf("You are either rich or young or both\n");
	} else {
		printf("You are neither rich nor young\n");
	}

	if ((age <= 30) && (salary >= 30000) && (number_of_children != 0)) {
		printf("You are a rich young parent\n");
	} else {
		printf("You are not a rich young parent\n");
	}

	return 0;
}