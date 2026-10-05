#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    char name[50];
    int class;

};

int main()
{
   struct student *p;
   char ch;

   do
   {
       p = (struct student *)malloc(sizeof(struct student));

       printf("enter roll number: ");
       scanf("%d",&(p->roll));

       printf("enter name: ");
       scanf("%s",&(p->name));

       printf("enter class: ");
       scanf("%d",&(p->class));

       printf("do you want enter another number: ");
       scanf(" %c",&ch);

   } while (ch == 'y');

   printf("roll number = %d\n",p->roll);
   printf("name = %s\n",p->name);
   printf("class = %d\n",p->class);
   

   return 0;
   
}