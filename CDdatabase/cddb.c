#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"
#include "cddb.h"

// create a default CD collection in memory
// EXERCISE: Instead of using this default data, load the data from the file on disk
//			 if the file exists. If it doesn't exist, create it when the user starts 
//			 to enter data (i.e. to add the 1st CD record).
void create_cdcollection() {
	cd_collection = malloc(sizeof(CD) * 4);
	cdarraylen = 4;
	strcpy(cd_collection[0].name, "Great Hits");
	strcpy(cd_collection[0].artist, "Polly Darton");
	cd_collection[0].trackcount = 20;
	cd_collection[0].rating = 10;

	strcpy(cd_collection[1].name, "Mega Songs");
	strcpy(cd_collection[1].artist, "Lady Googoo");
	cd_collection[1].trackcount = 18;
	cd_collection[1].rating = 7;

	strcpy(cd_collection[2].name, "The Best Ones");
	strcpy(cd_collection[2].artist, "The Warthogs");
	cd_collection[2].trackcount = 24;
	cd_collection[2].rating = 4;

	strcpy(cd_collection[3].name, "Songs From The Shows");
	strcpy(cd_collection[3].artist, "The Singing Swingers");
	cd_collection[3].trackcount = 22;
	cd_collection[3].rating = 9;
}

// return number of records in cd db file
int number_of_records_in_db(char *filename) {
	FILE *f;
	int endpos;
	int numrecs = 0;

	f = fopen(filename, "rb");
	if (f == 0) {
		printf("Cannot open file: %s\n", filename);
	} else {
		fseek(f, 0, SEEK_END);					// seek to end of file
		endpos = ftell(f);							// get the current position (now at the end of the file)
		numrecs = endpos / sizeof(CD);				// calculate number of records in file
		fclose(f);
	}
	return numrecs;
}

// set all fields of global cd record to "" or 0
static void init_tempcd() {
	// EXERCISE: How else might I assign an 'empty' string?
	// Hint: Look at 04_ReturnStrings in Step 07
	strcpy(tempcd.name, "");
	strcpy(tempcd.artist, "");
	tempcd.trackcount = 0;
	tempcd.rating = 0;
}

// test that string ascore can be converted to an int between 1 and 5. Return 0 (false) otherwise
static int getrating(char *ascore) {
	int intscore = atoi(ascore);			// This will be 0 if ascore cannot be converted to int
	int returnval;

	if ((intscore < 1) || (intscore > 5)) {
		returnval = 0;
	} else {
		returnval = intscore;
	}
	return returnval;
}

// prompt user to enter data for a cd record
static void readcd_data() {
	char cdname[MAXSTRLEN];
	char cdartist[MAXSTRLEN];
	char cdtracks[MAXSTRLEN];
	char cdrating[MAXSTRLEN];
	int tracknum;
	int ratingnum;
	int slen = 0;

	init_tempcd();
	// keep prompting until some data is entered (don't allow just a carriage-return)
	// EXERCISE: 	Try rewriting using do..while loops. Think if you need to init slen to 0 
	//				before each loop (as I have done below) if you use do..while?
	while (slen == 0) {
		printf("Enter CD Name\n> ");
		slen = readln(cdname);
	};
	slen = 0;
	while (slen == 0) {
		printf("Enter Artist\n> ");
		slen = readln(cdartist);
	};
	slen = 0;
	while (slen == 0) {
		printf("Enter Number of tracks\n> ");
		slen = readln(cdtracks);
	};
	slen = 0;
	while (slen == 0) {
		printf("Enter Rating\n> ");
		slen = readln(cdrating);
	};
	// check that strings can be converted to valid trackingnum and ratingnum
	tracknum = atoi(cdtracks);
	ratingnum = getrating(cdrating);
	if (tracknum == 0) {
		printf("'%s' is Invalid number for cd tracks. 0 will be used\n", cdtracks);
	};
	if (ratingnum == 0) {
		printf("'%s' is Invalid number for cd tracks. 1 will be used\n", cdrating);
		ratingnum = 1;
	};
	// finally init tempcd
	strcpy(tempcd.name, cdname);
	strcpy(tempcd.artist, cdartist);
	tempcd.trackcount = tracknum;
	tempcd.rating = ratingnum;
}

// modify data of record #cdnum in database
static void change_cd(char *filename, int cdnum) {
	// EXERCISE: Consider using return values, r, for error checking purposes
	FILE *f;
	CD* cdptr;
	size_t r;

	f = fopen(filename, "rb+");								// Open for read/write
	if (f == 0) {
		printf("Cannot open file: %s\n", filename);
	} else {
		cdptr = malloc(sizeof(CD));							// alloc some memory
		r = fseek(f, cdnum * sizeof(CD), SEEK_SET);			// seek to cdnum record (0 offset is first)
		r = fread(cdptr, sizeof(CD), 1, f);					// read cdnum record into memory
		readcd_data();										// get some data for this record
		strcpy(cdptr->name, tempcd.name);					// modify cd data before writing back to disk
		strcpy(cdptr->artist, tempcd.artist);
		cdptr->trackcount = tempcd.trackcount;
		cdptr->rating = tempcd.rating;
		r = fseek(f, cdnum * sizeof(CD), SEEK_SET);			// seek again to cdnum record
		r = fwrite(cdptr, sizeof(CD), 1, f);				// write the modified record out
		fclose(f);
	}
}

// prompt user for # of cd record - check it exists. If so, allow data fields to be changed
void modify_cd(char *filename) {
	// EXERCISE: 	Show each existing field on screen. If the user presses Carriage Return
	// 				(but does not enter a string) simply leave the existing data unmodified
	//				for that field. Change the fields for which the user does enter new data
	char input[MAXSTRLEN];
	int cdnum;
	int slen;
	int error = 0;

	printf("Enter CD Number to modify:\n> ");
	slen = readln(input);
	if (slen > 0) {
		if (input[0] == '0') {		// allow 0 as a valid index
			cdnum = 0;
		} else {
			cdnum = atoi(input);	// otherwise atoi returns 0 on conversion error
			if (cdnum == 0) {
				error = 1;
			}
		}

	} else {
		error = 1;
	};
	if (error) {
		printf("Error: invalid number!\n");
	} else if ((cdnum < 0) || (cdnum > (number_of_records_in_db(filename) - 1))) {
		printf("Error: Cannot find cd number %d\n", cdnum);
	} else {
		change_cd(filename, cdnum);
	}
}

// append new cd record to end of file
void add_cd(char *filename) {
	FILE *f;

	readcd_data();
	f = fopen(filename, "ab");								// open file in append mode
	if (f == 0) {
		printf("Cannot write to file: %s\n", filename);
	} else {
		fwrite(&tempcd, sizeof(CD), 1, f);					// write data saved in tempcd at end of file
		fclose(f);
	}
}

// save in-memory data (cd_collection) to file on disk
void save_cdcollection(char *filename) {
	// note cdarraylen was initialized when data was last loaded from disk
	// it saves the number of records loaded into memory
	// EXERCISE: 	Test if the file already exists on disk and prompt user 
	//  			to ask whether it should be overwritten
	FILE *f;
	int count;

	f = fopen(filename, "wb");										// open file for binary write
	if (f == 0) {
		printf("Cannot write to file: %s\n", filename);
	} else {
		count = fwrite(cd_collection, sizeof(CD), cdarraylen, f);	// write it out
		if (count != cdarraylen) {
			printf("initialization failed\n");
		} else {
			printf("saved\n");
		}
		fclose(f);
	}
}

// load cd db into cd_collection array in memory
static int load_cdcollection(char *filename) {
	FILE *f;
	int numrecs;
	int numrecsread = 0;

	numrecs = number_of_records_in_db(filename);
	f = fopen(filename, "rb");
	if (f == 0) {
		printf("Cannot read file: %s\n", filename);
	} else {
		cd_collection = realloc(cd_collection, sizeof(CD) * numrecs);		// alloc some memory
		numrecsread = fread(cd_collection, sizeof(CD), numrecs, f);			// read all recs into memory
		if (numrecsread != numrecs) {
			printf("Error: %d records in file but %d were read into memory", numrecs, numrecsread);
		}
		fclose(f);
	}
	cdarraylen = numrecsread; // used when saving: I need to know the number of records to be saved
	return numrecsread;
}

// load and show CD collection on screen
void display_cdcollection(char *filename) {
	int i;
	int numrecs;
	CD thiscd;

	numrecs = load_cdcollection(filename);
	for (i = 0; i < numrecs; i++) {
		thiscd = cd_collection[i];
		printf("%d CD #%d: '%s' by %s has %d tracks. My rating = %d\n", sizeof(CD), i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
}