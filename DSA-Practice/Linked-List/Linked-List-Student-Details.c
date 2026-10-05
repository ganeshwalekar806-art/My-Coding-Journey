#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll_no;
    char gen;
    char name[50];
    struct student *next;

};

int main()
{
    struct student *nn,*first,*temp;
    char ch;
    int fcount=0;
    int mcount=0;
    int tcount=0;

    first = NULL;

    do
    {
        // ALOCATE MEMORY FOR NEW NODE 

        nn = (struct student *)malloc(sizeof(struct student));

       // ACCEPT STUDENT DETALIS 

        printf("enter student roll number: ");
        scanf("%d",&nn->roll_no);

        fflush(stdin);

        printf("enter student gender: ");
        scanf(" %c",&nn->gen);

        fflush(stdin);

        printf("enter student name: ");
        scanf("%s",&nn->name);

        nn->next = NULL;

        // CHECK LINKED LIST IS EMPTY
        if(first == NULL)
        {
            first = nn;
        }
        else
        {
            temp = first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nn;  // ATTACH NEW NODE AT END 
        }

        printf("DO YOU WANT ENTER ANOTHER STUDENT INFORMATION: ");
        scanf(" %c",&ch);

    }while(ch == 'y' || ch == 'Y');

    temp = first;
    while(temp!=NULL)
    {
        tcount++;

        // COUNT TOTAL MALE STUDENTS 
        if(temp->gen == 'M' || temp->gen == 'm')
        {
            mcount++;
        }
        else 
        {
            fcount++; //COUNT TOTAL FEMALE STUDENTS 
        }

        temp = temp->next;
    }

    // PRINT TOTAL COUNT OF STUDENTS AND TOTAL COUNT OF FEMALE AND MALE 

    printf("TOTAL FEMALE STUDENT: %d\n",fcount);
    printf("TOTAL MELE STUDENT: %d\n",mcount);
    printf("TOTAL COUNT FEMALE AND MELE: %d",tcount);

return 0;

}