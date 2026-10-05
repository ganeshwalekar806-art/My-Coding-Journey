#include <stdlib.h>
#include <stdio.h>

struct student
{
    char name[50];
    int age;
    char gen;
    float avg;
};

struct student info()
{
    struct student temp;

    printf("Enter name of student: \n");
    scanf("%s", temp.name);

    printf("Enter age of student: \n");
    scanf("%d", &temp.age);

    printf("Enter gender letter of student: \n");
    scanf(" %c", &temp.gen);

    printf("Enter avg marks of student: \n");
    scanf("%f", &temp.avg);

    return temp;
}

int main()
{
    struct student s1, s2, s3;

    printf("\nAccepting details of first student\n");
    s1 = info();

    printf("\nAccepting details of second student\n");
    s2 = info();

    printf("\nAccepting details of third student\n");
    s3 = info();

    printf("\n========== DETAILS OF FIRST STUDENT ==========\n");

    printf("Name   : %s\n", s1.name);
    printf("Age    : %d\n", s1.age);
    printf("Gender : %c\n", s1.gen);
    printf("Average: %.2f\n", s1.avg);

    printf("\n========== DETAILS OF SECOND STUDENT ==========\n");

    printf("Name   : %s\n", s2.name);
    printf("Age    : %d\n", s2.age);
    printf("Gender : %c\n", s2.gen);
    printf("Average: %.2f\n", s2.avg);

    printf("\n========== DETAILS OF THIRD STUDENT ==========\n");

    printf("Name   : %s\n", s3.name);
    printf("Age    : %d\n", s3.age);
    printf("Gender : %c\n", s3.gen);
    printf("Average: %.2f\n", s3.avg);

    return 0;
}