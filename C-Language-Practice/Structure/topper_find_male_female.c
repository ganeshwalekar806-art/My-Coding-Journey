#include <stdio.h>

struct student
{
    int sroll;
    char sname[50];
    char sgen;
    float savg;
};

int main()
{
    struct student s[10];
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("\nEnter roll number: ");
        scanf("%d", &s[i].sroll);

        printf("Enter name: ");
        scanf("%s", s[i].sname);

        printf("Enter gender (m/f): ");
        scanf(" %c", &s[i].sgen);

        printf("Enter average marks: ");
        scanf("%f", &s[i].savg);
    }

    int top = 0;
    int ftop;
    int mtop;

    // Overall topper
    for(i = 1; i < 10; i++)
    {
        if(s[i].savg > s[top].savg)
        {
            top = i;
        }
    }

    // First female student find
    for(i = 0; i < 10; i++)
    {
        if(s[i].sgen == 'f')
        {
            ftop = i;
            break;
        }
    }

    // Female topper
    for(i = ftop + 1; i < 10; i++)
    {
        if(s[i].sgen == 'f')
        {
            if(s[i].savg > s[ftop].savg)
            {
                ftop = i;
            }
        }
    }

    // First male student find
    for(i = 0; i < 10; i++)
    {
        if(s[i].sgen == 'm')
        {
            mtop = i;
            break;
        }
    }

    // Male topper
    for(i = mtop + 1; i < 10; i++)
    {
        if(s[i].sgen == 'm')
        {
            if(s[i].savg > s[mtop].savg)
            {
                mtop = i;
            }
        }
    }

    printf("\nOverall topper : %s %.2f",
           s[top].sname, s[top].savg);

    printf("\nFemale topper  : %s %.2f",
           s[ftop].sname, s[ftop].savg);

    printf("\nMale topper    : %s %.2f",
           s[mtop].sname, s[mtop].savg);

    return 0;
}
