#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node *next;
};

int main()
{
    struct node *first,*nn,*temp;
    first = NULL; // Initially, the linked list is empty
    char ch;
    int num;

        // Loop to dynamically accept elements and build the linked list

    do
    {
        // Allocate memory for the new node

        nn = (struct node *)malloc(sizeof(struct node));

        printf("enter element: ");
        scanf("%d",&nn->ele);

        nn->next = NULL;

         // Check if the linked list is empty

        if(first == NULL)
        {
            first = nn; // First node becomes the head
        }
        else
        {
            temp = first;

            // Traverse to the last node of the list
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }

            temp->next = nn; // Attach the new node at the end
        }

         // Ask the user if they want to continue entering numbers
        printf("do you want enter another element: ");
        scanf(" %c",&ch);


    } while (ch == 'y' || ch == 'Y');

    printf("enter number for find: ");
    scanf("%d",&num);

    temp = first;

    while(temp!=NULL)
    {
        if(temp->ele == num) // CHECK NUMBER IS FOUND OR NOT 
        {
            printf("NUMBER WAS FIND: %d",temp->ele); // IF FOUND PRINT NUMBER 
        }
        else
        {
            printf("NUMBER IS NOT FOUND"); // IF NUMBER IS NOT FOUND 
        }

        temp=temp->next;
    }



}

