#ifndef HEADER_FLAG
#define HEADER_FLAG

typedef struct
{
    int day;
    int month;
    int year;

} BirthDate;

typedef struct
{
    char LastName[15];
    char FirstName[15];
    BirthDate D;
    char Address[50];
    char email[50];
    char PhoneNumber[15];

} Contact;

void clrscr();
void PrintSorted(Contact *Conts);
void loadfiles(Contact *Conts);
int valid_mail(char x[]);
int numbers_only(char s[]);
int check_number (char N[]);
void add(Contact A[]);
void search(Contact Conts[]);
void save(Contact Conts[]);
void quit(Contact Conts[]);
void modify(Contact Conts[]);
void PrintSortedBD(Contact *Conts);
void del(Contact Conts[]);
void noData();





#endif    // HEADER_FLAG


