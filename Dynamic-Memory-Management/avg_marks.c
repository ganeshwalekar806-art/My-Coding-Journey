#include<stdio.h>
#include<stdlib.h>

int main()
{
    float *p1;

    p1=(float *)malloc(sizeof(float));

    printf(" enter avarage marks of student:");
    scanf("%f",&(*p1));

    printf(" avarage marks of student is %f\n",*p1);

    return 0;
    
}