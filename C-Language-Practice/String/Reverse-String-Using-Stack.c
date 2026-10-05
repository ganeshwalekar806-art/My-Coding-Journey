#include<stdio.h>
#include<stdlib.h>

#define max 10

int main()
{
    char str[max];
    int i, top=-1, ch;

    while(1)
    {
        printf("\n1 => Enter the string\n");
        printf("2 => Display reverse string\n");
        printf("3 => Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);
        getchar();   // remove '\n' left by scanf()
  
        switch(ch)
        {
            case 1:

                if(top == max-1)
                {
                    printf("Stack is already full. Cannot perform push operation.\n");
                }
                else
                {
                    printf("Enter the string: ");

                    fgets(str, max, stdin);

                    i=0;

                    while(str[i]!='\0')
                    {
                        if(str[i] == '\n')
                        {
                            str[i] = '\0';
                            break;
                        }

                        top++;
                        i++;
                    }
                }

                break;


            case 2:

                if(top == -1)
                {
                    printf("String is already empty.\n");
                }
                else
                {
                    printf("Reverse string: ");

                    for(i=top; i>=0; i--)
                    {
                        printf("%c",str[i]);
                    }

                    printf("\n");
                }

                break;


            case 3:

                exit(0);


            default:

                printf("Invalid choice!\n");
        }
    }

    return 0;
}