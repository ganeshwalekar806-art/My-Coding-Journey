#include<stdio.h>
#include<string.h>

char* convert(int val)
{
    switch(val)
    {
        case 1000: return "M";

        case 900: return "CM";

        case 500: return "D";

        case 400: return "CD";

        case 100: return "C";

        case 90: return "XC";

        case 50: return "L";

        case 40: return "XL";

        case 10: return "X";

        case 9: return "IX";

        case 5: return "V";

        case 4: return "IV";

        case 1: return "I";

    }

}

int main()
{
    int num;
    int arr[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *str;
    int i=0;
    char *roman;

    printf("ENTER ANY NUMBER TO CONVERT TO ROMAN INTERGER : ");
    scanf("%d",&num);

    while(num != 0)
    {
        if(num >= arr[i])
        {

           num = num - arr[i];

           str = convert(arr[i]);

           strcat(roman,str);

           i = 0;
        }
        else
        {
            i++;
        }
    }

    printf("%s\n",roman);

    return 0;

}