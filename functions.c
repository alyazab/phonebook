#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

extern int size;
extern int flag;

int valid_lastname,valid_firstname,valid_phonenumber;

void clrscr()
{
    system("@cls||clear");
}


void PrintSorted(Contact *Conts)
{

    printf("\n**************************************\n\n");
    Contact S;
    int i,j;


    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)

            if(strcasecmp(Conts[i].LastName,Conts[j].LastName) == 1)
            {
                S = Conts[i];
                Conts[i] = Conts[j];
                Conts[j] = S;


            }

    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)


            if(strcasecmp(Conts[i].LastName, Conts[j].LastName) == 0)
            {

                if(strcasecmp(Conts[i].FirstName,Conts[j].FirstName) == 1)
                {
                    S = Conts[i];
                    Conts[i] = Conts[j];
                    Conts[j] = S;
                }
            }

    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)


            if(strcasecmp(Conts[i].LastName, Conts[j].LastName) == 0)
            {

                if(strcasecmp(Conts[i].FirstName, Conts[j].FirstName) == 0)
                {


                    if(strcmp(Conts[i].PhoneNumber,Conts[j].PhoneNumber)==1)
                    {
                        S = Conts[i];
                        Conts[i] = Conts[j];
                        Conts[j] = S;
                    }


                }

            }
    for (i=0; i<size; i++)
    {

        printf("LastName: %s\n",Conts[i].LastName);
        printf("FirstName: %s\n",Conts[i].FirstName);
        printf("Date: %d-%d-%d\n",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
        printf("Address: %s\n",Conts[i].Address);
        printf("Email: %s\n",Conts[i].email);
        printf("PhoneNumber: %s\n",Conts[i].PhoneNumber);
        printf("\n**************************************\n\n");
    }
    flag=0;
}



void loadfiles(Contact *Conts)
{
    int i=size;
    FILE *fl;

    char *filename = (char*) malloc(20);
    printf("Please enter the Filename: ");
    scanf("%s",filename);
    printf("\n");
    strcat(filename, ".txt");
    fl=fopen(filename,"r");
    if(fl==NULL)
    {
        clrscr();
        free(filename);
        printf("\n**************************************\n\n");
        printf("File does not exist!\n");
        printf("\n**************************************\n\n");

    }
    else
    {
        while (!feof(fl))
        {
            fscanf(fl," %[^,],",Conts[i].FirstName);
            fscanf(fl," %[^,],",Conts[i].LastName);
            fscanf(fl," %d-%d-%d,",&Conts[i].D.day,&Conts[i].D.month,&Conts[i].D.year);
            fscanf(fl," %[^,],",Conts[i].Address);
            fscanf(fl," %[^,],",Conts[i].email);
            fscanf(fl," %[^\n]",Conts[i].PhoneNumber);
            size++;
            i++;
        }
        fclose(fl);
        free(filename);
        clrscr();
        size--; // save adds new line while saving on a file so size should be decremented by 1
        printf("\n**************************************\n\n");
        printf("Loaded Successfully!\n");
        printf("\n**************************************\n\n");

    }
}

int valid_mail(char x[])
{
    int count=0;
    int countp=0;
    int i,j;
    int t,t2;
    int k=0;
    for(i=0 ; i<strlen(x) ; i++)
    {
        if(x[i]=='@')
        {
            count++;
            t=i;
        }
    }
    if(count==1)
    {
        for(j=0; j<t ; j++)
        {
            if(!(x[j]=='_' || x[j]=='.' || isalpha(x[j]) || isdigit(x[j])))
            {
                k=-1;
                printf("Invalid e-mail\n");
                printf("Enter a VALID email: ");
                break;
            }
        }
        if(k==0)
        {
            for(i=strlen(x); i>t ; i--)
            {
                if(x[i]=='.')
                {
                    t2=i;
                    countp++;
                }
            }
            if(countp==1)
            {
                for(i=0; i<t2 && i>t2; i++)
                {
                    if(!(isalpha(x[i])))
                    {
                        k=-1;
                        printf("Invalid e-mail\n");
                        printf("Enter a VALID email: ");
                        break;
                    }
                    else
                    {
                        k=1;
                    }
                }
                if(k==1)
                {
                    if(x[t2+3]!='\0')
                    {
                        k=-1;
                        printf("Invalid e-mail\n");
                        printf("Enter a VALID email: ");
                    }

                }
            }
            else
            {
                k=-1;
                printf("Invalid e-mail\n");
                printf("Enter a VALID email: ");
            }
        }
    }
    else
    {
        k=-1;
        printf("Invalid e-mail\n");
        printf("Enter a VALID email: ");
    }
    return k;
}
int numbers_only(char s[])
{
    int count=0;
    int i;
    for(i=0; i<strlen(s); i++)
    {
        if (isdigit(s[i]))
            count++;
    }
    if(count)
        return 0;
    else
        return 1;

}
int check_number (char N[])
{
    int count=0;
    int i;
    for(i=0; i<strlen(N); i++)
    {
        if(isalpha(N[i]))
            count++;
    }
    if(count)
        return 0;
    else
        return 1;
}
void add(Contact A[])
{

    printf("Firstname: ");
    scanf(" %s",A[size].FirstName);
    valid_firstname=numbers_only(A[size].FirstName);
    while(valid_firstname==0)
    {
        printf("INVALID!!\n");
        printf("Enter a VALID Name: ");
        scanf(" %s",A[size].FirstName);
        valid_firstname=numbers_only(A[size].FirstName);
    }
    printf("LastName: ");
    scanf(" %s",A[size].LastName);
    valid_lastname=numbers_only(A[size].LastName);
    while(valid_lastname==0)
    {
        printf("INVALID!!\n");
        printf("Enter a VALID Name: ");
        scanf(" %s",A[size].LastName);
        valid_lastname=numbers_only(A[size].LastName);
    }
    printf("Day of Birth: ");
    int day;
    char *D=(char*)malloc(256*sizeof(char));
    while(1)
    {
        char term;
        while(scanf("%d%c", &day, &term) != 2 || term != '\n')
        {
            gets(D);
            printf("Please enter correct data :\n");
        }


        if(day>31||day<1)
            printf("please enter correct data :\n");
        else
        {
            free(D);
            break;
        }
    }
    A[size].D.day=day;
    printf("Month of Birth: ");
    int months;
    char *M=(char*)malloc(256*sizeof(char));
    while(1)
    {
        char term;
        while(scanf("%d%c", &months, &term) != 2 || term != '\n')
        {
            gets(M);
            printf("Please enter correct data :\n");
        }


        if(months>12||months<1)
            printf("please enter correct data :\n");
        else
        {
            free(M);
            break;
        }
    }
    A[size].D.month=months;
    printf("Year of Birth: ");
    int years;
    char *Y=(char*)malloc(256*sizeof(char));
    while(1)
    {
        char term;
        while(scanf("%d%c", &years, &term) != 2 || term != '\n')
        {
            gets(Y);
            printf("Please enter correct data :\n");
        }


        if(years>2013||years<1928)
            printf("please enter correct data :\n");
        else
        {
            free(Y);
            break;
        }
    }
    A[size].D.year=years;
    printf("Address: ");
    scanf(" %[^\n]s",A[size].Address);

    printf("Email: ");
    do
    {
        scanf("%s",A[size].email);
    }
    while(valid_mail(A[size].email)==-1);
    printf("Phone Number: ");
    scanf("%s",A[size].PhoneNumber);
    valid_phonenumber=check_number(A[size].PhoneNumber);
    while(valid_phonenumber==0)
    {
        printf("INVALID!!\n");
        printf("Enter a valid PhoneNumber: ");
        scanf(" %s",A[size].PhoneNumber);
        valid_phonenumber=check_number(A[size].PhoneNumber);
    }
    size++;
    clrscr();
    printf("\n**************************************\n");
    printf("\nAdded Successfully!\n");
    printf("\n**************************************\n\n");
    flag=0;
}

void search (Contact Conts[])
{ char *z = (char*) malloc(20);
char *o = (char*) malloc(20);
    char p[4][50] ;
    int i,flag1=0,j;
    char c[][20]={"LastName","FirstName","PhoneNumber","Email"};
    char x[][10]= {"Day","Month","year"};
    int n[3];
    do {
    for (j=0;j<4;j++)
    { do {
    printf("if you want search by %s Y or N : ",c[j]);
    getchar();
    scanf("%s",o);
            if(((o[0]=='Y')||(o[0]=='y'))&&(strlen(o)==1))
                {printf("Enter the %s : ",c[j]);
                //getchar();
                    scanf("%s",p[j]);
                    }
            else if(((o[0]=='N')||(o[0]=='n'))&&(strlen(o)==1))
            strcpy(p[j]," ");
            else
                printf("\nWrong Entry!\n");
                 }
        while((o[0]!='Y' && o[0]!='N' && o[0]!='y' && o[0]!='n')||(strlen(o)!=1));
    } do{
    printf("if you want search by Address Y or N : ");
    getchar();
    scanf("%s",o);

            if(((o[0]=='Y')||(o[0]=='y'))&&(strlen(o)==1))
                {printf("Enter the Address : ");
                getchar();
                    scanf(" %[^\n]s",z);
                    }
            else if(((o[0]=='N')||(o[0]=='n'))&&(strlen(o)==1))
            strcpy(z," ");
            else
                printf("\nWrong Entry!\n");
                 }
        while((o[0]!='Y' && o[0]!='N' && o[0]!='y' && o[0]!='n')||(strlen(o)!=1));
        for (j=0;j<3;j++)
   {
do {
    printf("if you want search by %s Y or N : ",x[j]);
    getchar();
    scanf("%s",o);
        if(((o[0]=='Y')||(o[0]=='y'))&&(strlen(o)==1))
                {printf("Enter the %s  : ",x[j]);
                getchar();
                    scanf(" %d,",&n[j]);
                    }
            else if (((o[0]=='N')||(o[0]=='n'))&&(strlen(o)==1))
           {

           n[j]=0;}

            else
                printf("\nWrong Entry!\n");
                 }
        while((o[0]!='Y' && o[0]!='N' && o[0]!='y' && o[0]!='n')||(strlen(o)!=1));}
        clrscr();
        if((strcmp(" ",p[0])==0)
           &&((strcmp(" ",p[1])==0))
           &&((strcmp(" ",z)==0))
           &&(strcmp(" ",p[2])==0)
           &&(strcmp(" ",p[3])==0)
           &&((n[0]==0))&&(n[1]==0)&&(n[2]==0))
           {
               printf("\nEnter any thing to search with it\n");
           }
           }
           while((strcmp(" ",p[0])==0)
           &&((strcmp(" ",p[1])==0))
           &&((strcmp(" ",z)==0))
           &&(strcmp(" ",p[2])==0)
           &&(strcmp(" ",p[3])==0)
           &&((n[0]==0))&&(n[1]==0)&&(n[2]==0));
    for (i=0; i<size; i++)
    {
        if(((strcasecmp(Conts[i].LastName,p[0])==0)||(strcmp(" ",p[0])==0))
           &&((strcasecmp(Conts[i].FirstName,p[1])==0)||(strcmp(" ",p[1])==0))
           &&((strcasecmp(Conts[i].Address,z)==0)||(strcmp(" ",z)==0))
           &&(strcasecmp(Conts[i].PhoneNumber,p[2])==0||(strcmp(" ",p[2])==0))
           &&((strcasecmp(Conts[i].email,p[3])==0)||(strcmp(" ",p[3])==0))
           &&((Conts[i].D.day==n[0])||(n[0]==0))&&((Conts[i].D.month==n[1])||(n[1]==0))&&((Conts[i].D.year==n[2])||(n[2]==0)))
        {
            printf("LastName: %s\n",Conts[i].LastName);
            printf("FirstName: %s\n",Conts[i].FirstName);
            printf("Date: %d-%d-%d\n",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
            printf("Address: %s\n",Conts[i].Address);
            printf("PhoneNumber: %s\n",Conts[i].PhoneNumber);
            printf("Email: %s\n",Conts[i].email);
            printf("\n**************************************\n\n");
            flag1=1;
        }
    }
    if (flag1==0)
        printf( "Not Found! \n\n**************************************\n\n");
        free(z);
        free(o);
}

void save(Contact Conts[])
{


    if(size==0)
    {
        printf("\n**************************************\n");
        printf("\nThere Is No Data To Save!\n");
        printf("\n**************************************\n\n");

    }
    else
    {
        int i;
        FILE *f;
        char *filename = (char*) malloc(20);
        printf("Please enter the FileName: ");
        scanf("%s",filename);
        printf("\n");
        strcat(filename, ".txt");

        f = fopen(filename, "w");
        for(i=0 ; i<size ; i++)
        {

            fprintf(f,"%s,",Conts[i].FirstName);
            fprintf(f,"%s,",Conts[i].LastName);
            fprintf(f,"%d-%d-%d,",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
            fprintf(f,"%s,",Conts[i].Address);
            fprintf(f,"%s,",Conts[i].email);
            fprintf(f,"%s\n",Conts[i].PhoneNumber);

        }
        fclose(f);
        clrscr();
        printf("\n**************************************\n");
        printf("\nSaved Successfully!\n");
        printf("\n**************************************\n\n");

        free(filename);
    }
    flag =1;
}

void quit(Contact Conts[])
{
    char *o = (char*) malloc(20);
    if(!flag)
    {
        clrscr();

        printf("Data will be discarded. Do you want to save before exit?\n");
        printf("Y: YES, Save\n");
        printf("N: NO, Exit without saving\n");
        do
        {
            printf("Please enter Y or N: ");
            scanf(" %s",o);
            if(((o[0]=='Y')||(o[0]=='y'))&&(strlen(o)==1))
                save(Conts);
            else if(((o[0]=='N')||(o[0]=='n'))&&(strlen(o)==1))
                exit(0);
            else
                printf("\nWrong Entry!\n");
        }
        while((o[0]!='Y' && o[0]!='N' && o[0]!='y' && o[0]!='n')||(strlen(o)!=1));
    }
    free(o);
}

void modify(Contact Conts[])
{


    char *p = (char*) malloc(20);
    // char newfirstname[15];
    //char newlastname[15];
    printf("Enter the LastName that you want to modify :  ");
    scanf("%s",p);
    printf("\n**************************************\n\n");

    int i,flag1=0;
    for (i=0; i<size; i++)
    {
        if(strcasecmp(Conts[i].LastName,p)==0)
        {
            printf("Contact Number: (%d)\n",i+1);
            printf("LastName: %s\n",Conts[i].LastName);
            printf("FirstName: %s\n",Conts[i].FirstName);
            printf("Date: %d-%d-%d\n",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
            printf("Address: %s\n",Conts[i].Address);
            printf("Email: %s\n",Conts[i].email);
            printf("PhoneNumber: %s\n",Conts[i].PhoneNumber);
            printf("\n**************************************\n\n");

            //printf("%d-Contact : %s, %s,%d-%d-%d, %s, %s, %s, %s\n",i+1,Conts[i].FirstName,Conts[i].LastName,Conts[i].D.day,Conts[i].D.month,Conts[i].D.year,Conts[i].Address,Conts[i].email,Conts[i].PhoneNumber);
            flag1=1;
        }
    }
    if (flag1==0)
    {

        clrscr();
        printf( "\n**************************************\n\n");
        printf("LastName Not Found \n\n**************************************\n\n");
    }
    else
    {

        char *newfirstname = (char *) malloc(15);
        char *newlastname = (char *) malloc(15);
        int *selection = (int *) malloc(4);
        int *newday = (int *) malloc(4);
        int *newmonth= (int *) malloc(4);
        int *newyear = (int *) malloc(4);
        char *newphonenumber = (char *) malloc(20);
        char *newaddress = (char *) malloc(30);
        char *newemail = (char *) malloc(30);

        printf("Enter the number of Contact you want to modify: ");
        scanf("%d",selection);
        printf("\n");
        for (i=0; i<size; i++)
        {
            if (*selection==i+1)
            {
                printf("Enter new Firstname: ");
                scanf("%s",newfirstname);
                valid_firstname=numbers_only(newfirstname);
                while(valid_firstname==0)
                {
                    printf("INVALID!!\n");
                    printf("Enter a VALID Name: ");
                    scanf(" %s",newfirstname);
                    valid_firstname=numbers_only(newfirstname);
                }
                strcpy(Conts[i].FirstName,newfirstname);
                printf("Enter new Lastname: ");
                scanf("%s",newlastname);
                valid_lastname=numbers_only(newlastname);
                while(valid_lastname==0)
                {
                    printf("INVALID!!\n");
                    printf("Enter a VALID Name: ");
                    scanf(" %s",newlastname);
                    valid_lastname=numbers_only(newlastname);
                }
                strcpy(Conts[i].LastName,newlastname);
                printf("Enter new Birth-day: ");
                int day;
                char *DA=(char*)malloc(256*sizeof(char));
                while(1)
                   {
                     char term;
                     while(scanf("%d%c", &day, &term) != 2 || term != '\n')
                        {
                            gets(DA);
                            printf("Please enter correct data :\n");
                        }


                if(day>31||day<1)
                printf("please enter correct data :\n");
                else
                    {
                        free(DA);
                        break;
                    }
                 }
                *newday=day;
                Conts[i].D.day=*newday;
                printf("Enter new Birth-month: ");
                int months;
                char *MA=(char*)malloc(256*sizeof(char));
                while(1)
                    {
                        char term;
                        while(scanf("%d%c", &months, &term) != 2 || term != '\n')
                            {
                                gets(MA);
                                printf("Please enter correct data :\n");
                            }


                        if(months>12||months<1)
                        printf("please enter correct data :\n");
                        else
                            {
                                free(MA);
                                break;
                            }
                    }
                *newmonth=months;
                Conts[i].D.month=*newmonth;
                printf("Enter new Birth-year: ");
                int years;
                char *YA=(char*)malloc(256*sizeof(char));
                while(1)
                    {
                        char term;
                        while(scanf("%d%c", &years, &term) != 2 || term != '\n')
                            {
                                gets(YA);
                                printf("Please enter correct data :\n");
                            }


                        if(years>2013||years<1928)
                        printf("please enter correct data :\n");
                        else
                            {
                                free(YA);
                                break;
                            }
                    }
                *newyear=years;
                Conts[i].D.year=*newyear;
                printf("Enter new Address: ");
                scanf(" %[^\n]s",newaddress);
                strcpy(Conts[i].Address,newaddress);
                printf("Enter new Email: ");
                do
                {
                    scanf("%s",newemail);
                }
                while(valid_mail(newemail)==-1);
                strcpy(Conts[i].email,newemail);
                printf("Enter new Phonenumber: ");
                scanf("%s",newphonenumber);
                valid_phonenumber=check_number(newphonenumber);
                while(valid_phonenumber==0)
                {
                    printf("INVALID!!\n");
                    printf("Enter a valid Phonenumber: ");
                    scanf(" %s",newphonenumber);
                    valid_phonenumber=check_number(newphonenumber);
                }
                strcpy(Conts[i].PhoneNumber,newphonenumber);
                clrscr();
                printf("\n**************************************\n");
                printf("\nModified Successfully !!\n");
                printf("\n**************************************\n\n");
                flag=0;
                free(newaddress);
                free(newfirstname);
                free(newlastname);
                free(newday);
                free(newmonth);
                free(newyear);
                free(newphonenumber);
                free(selection);
            }
        }
    }
    free(p);
}





void PrintSortedBD(Contact *Conts)
{
    flag=0;
    printf("\n**************************************\n\n");
    Contact S;
    int i,j;


    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)

            if(Conts[i].D.year - Conts[j].D.year >0)
            {

                S = Conts[i];
                Conts[i] = Conts[j];
                Conts[j] = S;


            }


    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)


            if(Conts[i].D.year - Conts[j].D.year == 0)
            {

                if(Conts[i].D.month - Conts[j].D.month >0)
                {
                    S = Conts[i];
                    Conts[i] = Conts[j];
                    Conts[j] = S;
                }
            }


    for(i=0 ; i < size-1 ; i++)
        for(j=i+1; j<size ; j++)


            if(Conts[i].D.year - Conts[j].D.year == 0)
            {

                if(Conts[i].D.month - Conts[j].D.month == 0)
                {


                    if(Conts[i].D.day - Conts[j].D.day >0)
                    {
                        S = Conts[i];
                        Conts[i] = Conts[j];
                        Conts[j] = S;
                    }


                }

            }

    for (i=0; i<size; i++)
    {

        printf("LastName: %s\n",Conts[i].LastName);
        printf("FirstName: %s\n",Conts[i].FirstName);
        printf("Date: %d-%d-%d\n",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
        printf("Address: %s\n",Conts[i].Address);
        printf("Email: %s\n",Conts[i].email);
        printf("PhoneNumber: %s\n",Conts[i].PhoneNumber);
        printf("\n**************************************\n\n");
    }
}





void del(Contact Conts[])
{
    int selection;
    char newfirstname[15],newlastname[15];
    printf("Enter the Firstname of the contact you want to delete:  ");
    scanf("%s",newfirstname);
    printf("Enter the Lastname of the contact you want to delete:  ");
    scanf("%s",newlastname);
    clrscr();
    printf("\n**************************************\n\n");

    int i,flag1=0;
    for (i=0; i<size; i++)
    {
        if(strcmp(Conts[i].LastName,newlastname)==0&&strcmp(Conts[i].FirstName,newfirstname)==0)
        {
            printf("Contact Number: (%d)\n",i+1);
            printf("LastName: %s\n",Conts[i].LastName);
            printf("FirstName: %s\n",Conts[i].FirstName);
            printf("Date: %d-%d-%d\n",Conts[i].D.day,Conts[i].D.month,Conts[i].D.year);
            printf("Address: %s\n",Conts[i].Address);
            printf("Email: %s\n",Conts[i].email);
            printf("PhoneNumber: %s\n",Conts[i].PhoneNumber);
            printf("\n**************************************\n\n");
            flag1=1;
        }
    }
    if (flag1==0)
    {
        printf( "LastName Not Found !!\n\n**************************************\n\n");
    }
    else
    {
        printf("Enter the number of contact you want to delete: ");
        scanf("%d",&selection);
        selection=selection-1;
        for (i=selection; i<size; i++)
        {
            strcpy(Conts[i].FirstName,Conts[i+1].FirstName);
            strcpy(Conts[i].LastName,Conts[i+1].LastName);
            strcpy(Conts[i].Address,Conts[i+1].Address);
            strcpy(Conts[i].email,Conts[i+1].email);
            strcpy(Conts[i].PhoneNumber,Conts[i+1].PhoneNumber);
            Conts[i].D=Conts[i+1].D;

        }
        size--;
        clrscr();
        printf("\n**************************************\n");
        printf("\nDeleted Successfully !!\n");
        printf("\n**************************************\n\n");
        flag=0;

    }
}

void noData()
{

    printf("\n**************************************\n");
    printf("\nThere is no Data.\n");
    printf("\n**************************************\n\n");
}

