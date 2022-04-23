enum score {
	Terrible = 1, Bad = 2, Average = 3, Good = 4, Excellent = 5
};

typedef char Str50[50];

typedef struct cd {
	Str50 name;
	Str50 artist;
	int trackcount;
	int rating;
} CD;

CD *cd_collection;
CD tempcd;

void create_cdcollection();
void display_cdcollection();
int number_of_records_in_db(char*);
void save_cdcollection(char*);
int cdarraylen;
void add_cd(char*);
void modify_cd(char*);
