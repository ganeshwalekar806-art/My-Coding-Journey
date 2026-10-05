#include<stdio.h>
#include<stdlib.h>

struct employee
{
    float salary;
    char name[25];
    int age;
    int id;

};

int main()
{
    struct employee *p;

    p = (struct employee *)malloc(sizeof(struct employee));

    printf("enter salary:  ");
    scanf("%f",&p->salary);

    printf("enter name: ");
    scanf("%s",&p->name);

    printf("enter age: ");
    scanf("%d",&p->age);

    printf("enter id: ");
    scanf("%d",&p->id);

    printf("salary:%f\n",p->salary);
    printf("name:%s\n",p->name);
    printf("age:%d\n",p->age);
    printf("id:%d\n",p->id);

    free(p);

    return 0;

}