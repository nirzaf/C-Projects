#include <stdio.h>
#include "mystring.h"
#include "cddb.h"

#define CDFILENAME "cd_database.bin"
#define CDBACKUPFILENAME "cd_database.bak"

char getcommand() {
	char command[MAXSTRLEN];
	int commandlen;
	char c;

	commandlen = readln(command);
	if (commandlen != 1) {
		c = 'x';
	} else {
		c = command[0];
	}
	return c;
}

int main(int argc, char **argv) {
	int keepgoing = 1;

	create_cdcollection();
	while (keepgoing) {
		printf("\nEnter a command or 'q' to quit.");
		printf("\nCommands: 'a'=add record, 'd'=display records, 'm'=modify record");
		printf("\n          'n'=number of records, 's'=save backup (from memory)\n> ");
		switch (getcommand()) {
		case 'a':
			printf("Add record\n");
			add_cd(CDFILENAME);
			break;
		case 'd':
			printf("Display records\n");
			display_cdcollection(CDFILENAME);
			break;
		case 'm':
			printf("Modify record\n");
			modify_cd(CDFILENAME);
			break;
		case 'n':
			printf("Number of records\n");
			printf("Database contains %d records\n", number_of_records_in_db(CDFILENAME));
			break;
		case 's':
			printf("Save backup\n");
			save_cdcollection(CDBACKUPFILENAME);
			break;
		case 'q':
			printf("Ending...\n");
			keepgoing = 0;
			break;
		default:
			printf("Invalid command.\n");
			break;
		}
	}
	return 0;
}