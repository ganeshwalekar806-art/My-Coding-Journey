#include<stdio.h>
#include<stdlib.h>

struct student 
{
    int age;
    int class;
    char name[50];

};

struct student_std()
{
    struct student temp;

    printf("enter age: \n");
    scanf("%d",&temp.age);

    printf("enter class: \n");
    scanf("%d",&temp.class);

    printf("enter name: \n");
    scanf("%d",&temp.name);

    return temp;
}

void main()
{
    struct student s1,s2,s3;

    printf("enter accepting details of student first\n");
    s1 = struct student_std();
    s2 = struct student_std();
    s3 = struct student_std();

    return 0;
}