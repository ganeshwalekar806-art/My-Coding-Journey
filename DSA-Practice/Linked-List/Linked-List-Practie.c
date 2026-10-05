#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node *next;

};

int main()
{
    char ch;

    struct node *first;
    struct node *nn,*temp;

    first = NULL;

    do
    {
        nn = (struct node *)malloc(sizeof(struct node));

        printf("enter any number: ");
        scanf("%d",&nn->ele);

        nn->next;

        if(first == NULL)
        {
            first = nn;
        }

        else
        {
            temp = first;

            while(temp->next != NULL)
            {
                    temp = temp->next;
            }
            temp->next = nn;
        }

        printf("do you want to enter another number: ");
        scanf(" %c",&ch);


    } while(ch == 'y' || ch == 'Y');

    return 0;

}