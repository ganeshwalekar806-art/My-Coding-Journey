#include<stdio.h>
#include<stdlib.h>

// Structure defining a node of the linked list
struct node
{
    int ele;          // To store the integer value
    struct node *next;// Pointer to store the address of the next node
};

int main()
{
    // Pointer declarations: nn (new node), first (head pointer), temp (traversal pointer)
    struct node *nn, *first, *temp;
    first = NULL; // Initially, the linked list is empty
    char ch;

    // Loop to dynamically accept elements and build the linked list
    do
    {
        // Allocate memory for the new node
        nn = (struct node *)malloc(sizeof(struct node));

        // Read element from the user
        printf("enter any element: ");
        scanf("%d", &nn->ele);

        nn->next = NULL;

        // Check if the linked list is empty
        if(first == NULL)
        {
            first = nn; // First node becomes the head
        }
        else
        {
            // Traverse to the last node of the list
            temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            // Attach the new node at the end
            temp->next = nn;
        }

        // Ask the user if they want to continue entering numbers
        printf("do you want enter another number: ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    // Count the total number of elements in the linked list
    temp = first;
    int count = 0;
    int mid;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Calculate the middle index position
    mid = count / 2;

    // Traverse the list up to the middle node position
    temp = first;
    while(temp != NULL && mid != 0)
    {
        temp = temp->next;
        mid--;
    }

    // Print the middle element
    printf("\n\nmiddle element is: %d", temp->ele);

    return 0;
}