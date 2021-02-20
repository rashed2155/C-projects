#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    char id[10];
    char name[30];
    char disease[50];
    char phon_no[15];
    char bed_no[30];
    struct patient *link;
};
typedef struct patient node;
node *header = NULL;
int main()
{
    system("COlOR B1");
    textmain();
    for (;;)
    {
        start();
    }
    return 0;
}
void start()
{
    int choice;
    printf("\n\n\n\nChoose :\n\t1 - ADD NEW PATIENT\n\t2 - SEARCH PATIENT BY ID\n\t3 - RELEASE PATIENT\n\t4 - DISPLAY PATIENT RECORD\n\t0 - FOR EXIT !\n\n\n\n");
    printf("Enter Choice option : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        insert();
        break;
    case 2:
        system("cls");
        search();
        break;
    case 3:
        system("cls");
        del();
        break;
    case 4:
        system("cls");
        display();
        break;
    default:
        system("cls");
        exit(0);
        break;
    }
}
void insert()
{
    textmain();
    char id[20];
    char phon_no[16];
    char name[40];
    char disease_name[50];
    char bed_no[35];
    node *p;
    printf("\n\t\tEnter ID: ");
    scanf("%s", &id);
    printf("\t\tEnter Name: ");
    scanf("%s", &name);
    printf("\t\tEnter Disease Name: ");
    scanf("%s", &disease_name);
    printf("\t\tPhone No: ");
    scanf("%s", &phon_no);
    printf("\t\tEnter Bed No: ");
    scanf("%s", &bed_no);
    printf("\t\t\t\t ****NEW PATIENT ADD SUCCESSFUL****\n");
    p = (node *)malloc(sizeof(node));
    strcpy(p->id, id);
    strcpy(p->phon_no, phon_no);
    strcpy(p->name, name);
    strcpy(p->disease, disease_name);
    strcpy(p->bed_no, bed_no);
    p->link = NULL;
    if (header == NULL)
        header = p;
    else
    {
        node *temp = header;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
}
void search()
{
    textmain();
    char id_number[15];
    node *temp;

    printf("\t\tEnter the ID number to be searched : ");
    scanf("%s", &id_number);
    printf("%s\n", id_number);
    int f = 0;

    for (temp = header; temp != NULL; temp = temp->link)
    {
        if (strcmp(id_number, temp->id) == 0)
        {
            f = 1;
            printf("PATIENT ID : %s\nPATIENT NAME : %s\nPHONE NUMBER : %s\nDISEASE : %s\nPATIENT BED NO : %s\n\n\n", temp->id, temp->name, temp->phon_no, temp->disease, temp->bed_no);
        }
    }
    if (f == 0)
        printf("Patient Record Not Found !!!\n");
}

void del()
{
    textmain();
    node *temp;
    if (header == NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        temp = header;
        header = header->link;
        printf("PATIENT ID : %s\nPATIENT NAME : %s\nPHONE NUMBER : %s\nDISEASE : %s\nPATIENT BED NO : %s\n\n\n", temp->id, temp->name, temp->phon_no, temp->disease, temp->bed_no);
        printf("\n\n\n\n\n\n***PATIENT RELEASE SUCCESSFUL***");
        free(temp);
    }
}

void display()
{
    textmain();
    node *temp;
    for (temp = header; temp != NULL; temp = temp->link)
        printf("PATIENT ID : %s\nPATIENT NAME : %s\nPHONE NUMBER : %s\nDISEASE : %s\nPATIENT BED NO : %s\n\n\n", temp->id, temp->name, temp->phon_no, temp->disease, temp->bed_no);
}

void textmain()

{
    printf("\t\t\t\t#############################################\n");
    printf("\t\t\t\t# #\n");
    printf("\t\t\t\t# PATIENT DATABASE SYSTEM #\n");
    printf("\t\t\t\t# #\n");
    printf("\t\t\t\t#############################################\n");
}