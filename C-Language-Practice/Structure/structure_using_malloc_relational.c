#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[25];
    int roll_no;
    float marks;
    float avg;

};

int main()
{
    struct student *p1,*p2,*p3;

    p1 = (struct student *)malloc(sizeof(struct student));
    p2 = (struct student *)malloc(sizeof(struct student));
    p3 = (struct student *)malloc(sizeof(struct student));


    printf("accepecting details of first student\n");

    printf("enter name: ");
    scanf("%s",&p1->name);

    printf("enter roll_no: ");
    scanf("%d",&p1->roll_no);

    printf("enter marks: ");
    scanf("%f",&p1->marks);

    printf("accpecting details of second student\n");

    printf("enter name: ");
    scanf("%s",&p2->name);

    printf("enter roll_no: ");
    scanf("%d",&p2->roll_no);

    printf("enter marks: ");
    scanf("%f",&p2->marks);

    printf("accpecting deatils of third student\n");

    printf("enter name: ");
    scanf("%s",&p3->name);

    printf("enter roll_no: ");
    scanf("%d",&p3->roll_no);

    printf("enter marks: ");
    scanf("%f",&p3->marks);

    p1->avg = p1->marks/5;
    p2->avg = p2->marks/5;
    p3->avg = p3->marks/5;

    printf("details of first student\n\n");

    printf("name:%s\n",p1->name);
    printf("roll_no:%d\n",p1->roll_no);
    printf("marks: %f\n",p1->marks);
    printf("average marks:%f\n",p1->avg);

    printf("details of second student\n\n");

    printf("name:%s\n",p2->name);
    printf("roll_no:%d\n",p2->roll_no);
    printf("marks:%f\n",p2->marks);
    printf("average marks:%f\n",p2->avg);

    printf("details of third student\n\n");

    printf("name:%s\n",p3->name);
    printf("roll_no:%d\n",p3->roll_no);
    printf("marks:%f\n",p3->marks);
    printf("avarage marks:%f\n",p3->avg);


    if(p1->avg > p2->avg && p1->avg > p3->avg)
    {
        printf("first student has highest avagage marks first rank:%f ",p1->avg);
    }

    else if(p2->avg > p1->avg && p2->avg > p3->avg)
    {
        printf("second student has highest average marks first rank :%f ",p2->avg);

    }

    else 
    {
        printf("third student has highest marks average kfirst rank:%f ",p3->avg);

    }

    free(p1);
    free(p2);
    free(p3);

    return 0;

}


