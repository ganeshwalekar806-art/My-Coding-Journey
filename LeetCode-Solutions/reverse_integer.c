#include<stdio.h>

int main()
{
    int num,rev = 0,digit = 0,i;

    printf("enter any number : ");
    scanf("%d",&num);

    while(num != 0)
    {
        digit = num % 10;

        // these 2 if and else if condition are main logic of program 
        if(rev > 214748364)
        {
            return 0;
        }
        else if(rev == 214748364 && digit > 7)
        {
            return 0;  
        }
        else if(rev < -214748364)
        {
            return 0;
        }
        else if(rev == -214748364 && digit < -8)
        {
            return 0;
        }


        rev = rev * 10 + digit;
        num = num / 10;
    }

    printf("%d",rev);

    return 0;
}