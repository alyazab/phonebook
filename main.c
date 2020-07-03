#include "functions.h"

int size = 0;
int flag =1;

int main()
{

    int Option;
    Contact *Conts = (Contact *) malloc(100 * sizeof(Contact));


    do
    {
        printf("Please Select An Option :\n");
        printf("--------------------------\n");
        printf(" 1) Load From A File\n");
        printf(" 2) Add\n");
        printf(" 3) Modify\n");
        printf(" 4) Delete\n");
        printf(" 5) Search\n");
        printf(" 6) Print All ( SORTED )\n");
        printf(" 7) Print All ( SORTED BY BIRTHDATE )\n");
        printf(" 8) Save\n");
        printf(" 9) Quit\n\n");
        printf("Choose an Option: ");
        scanf("%d",&Option);
        printf("\n");

        switch(Option)
        {
        case 1 :
            //if(l>0) break;
            //l++;
            // lines = linesCounter();
            loadfiles(Conts);
            break;
        case 2 :
            add(Conts);
            break;
        case 3 :
            clrscr();
            if(size==0) noData();
            else modify(Conts);
            break;
        case 4 :
            clrscr();
            if(size==0) noData();
            else del(Conts);
            break;
        case 5 :
            clrscr();
            if(size==0) noData();
            else search(Conts);
            break;
        case 6 :
            clrscr();
            if(size==0) noData();
            else PrintSorted(Conts);
            break;
        case 7 :
            clrscr();
            if(size==0) noData();
            else PrintSortedBD(Conts);
            break;
        case 8 :
            clrscr();
            save(Conts);
            break;
        case 9 :
            quit(Conts);
            break;
        default:
            clrscr();
            printf("\nWrong Entry!\n");
        }
        printf("\n");

    }
    while(Option!=9);

    free(Conts);
    return 0;
}





