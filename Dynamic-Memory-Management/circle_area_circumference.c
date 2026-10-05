#include<stdio.h>
#include<stdlib.h>

int main()
{
    float *p1, *p2, *p3;

    p1=(float *)malloc(sizeof(float));
    p2=(float *)malloc(sizeof(float));
    p3=(float *)malloc(sizeof(float));

    printf("enter radius of circle:");
    scanf("%f",&(*p1));

    *p2=3.14*(*p1)*(*p1);
    *p3=2*3.14*(*p1);

    printf("area of cicle is %f\n",(*p2));
    printf("circumference of circle is %f\n",(*p3));

    return 0;

}