#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

struct record
{
    long ph;
    char name[20],add[20],email[30];
    float cgpa;
} list;

void pass()
{
    int p;
    printf("\t\t\t=========  Enter Your Password  =========\n\n");
    while (1)
    {
        scanf("%d", &p);
        if (p==2018)
        {
            printf("Correct Password\n\n\n");
            printf("Press Enter To Continue..........");
            getch();
            break;
        }
        else printf("\t\t\t=========  Incorrect Password ,Please Try Again  =========\n\n");
    }

}

char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
    pass();
    system("cls");
main:
    system("cls");    /* ************Main menu ***********************  */
    printf("\n\t **** Welcome to Student Record Manager ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t===================================\n\n\t\t[1] Add a new record\n\t\t[2] List of all student\n\t\t[3] Search for record\n\t\t[4] Edit a record\n\t\t[5] Delete a record\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 0:
        printf("\n\n\t\tAre you sure u want to exit?");
        break;
    /* *********************add new records************  */
    case 1:

        system("cls");
        fp=fopen("record.txt","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\n Student Name:");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone : ");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("CGPA avg : ");
            scanf("%f", &list.cgpa);
            fflush(stdin);
            printf("Address : ");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("E-mail address : ");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;

    /* *********************list of records*************************  */
    case 2:
        system("cls");
        printf("\n\t\t================================\n\t\t\tLIST OF STUDENTS\n\t\t================================\n\nName\t\tPhone No\t  CGPA\t   Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)
        {

            fp=fopen("record.txt","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nCGPA\t: %.2f\nAddress\t: %s\nEmail\t: %s\n",list.name,
                           list.ph,list.cgpa,list.add,list.email);
                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);

        }

        break;



    /* *******************search records**********************  */
    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\n\t..::Search record \n\t===========================\n\t..::Name of record to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("record.txt","r");

            system("cls");
            printf("\n\n..::Search result for '%s' \n===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t:%s\n",list.name,list.ph,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("..::Press any key to continue...");
                        getch();
                    }
                }
            }

            if(found==0)
                printf("\n..::No match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;


    /* *********************edit records************************/
    case 4:
        system("cls");
        fp=fopen("record.txt","r");
        ft=fopen("temp.txt","w");
        fflush(stdin);
        printf("..::Edit record\n===============================\n\n\t..::Enter the name of record to edit:");
        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::CGPA avg:");
        scanf("%f", list.cgpa);
        fflush(stdin);
        printf("..::address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("record.txt");
        rename("temp.txt","record.txt");
        break;


    /* ********************delete records**********************/
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::Delete A record\n\t==========================\n\t..::Enter the name of record to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("record.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("record.dll");
        rename("temp.dat","record.dll");
        break;

    default:
        printf("Invalid choice");
        break;
    }


    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;


    case 0:
        break;

    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}
