#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p1;
    float *p2;
    char *p3;

    p1=(int *)malloc(sizeof(int));
    p2=(float *)malloc(sizeof(float));
    p3=(char *)malloc(sizeof(char));

    printf( "enter  age of student: ");
    scanf("%d",&(*p1));

    printf(" enter avarage marks of student: ");
    scanf("%f",&(*p2));

    printf( "enter gender letter of student: ");
    scanf(" %c",&(*p3));
    printf("\n \n");
    printf(" age of student is %d\n",*p1);
    printf(" avarage marks of student is %f\n",*p2);
    printf(" gender letter of student is %c\n",*p3);

    return 0;
    
}