#include<stdio.h>
#include<stdlib.h>

// Structure defining a node of the linked list
struct node
{
    int ele;           // Data element stored in the node
    struct node *next; // Pointer to the next node in the list
};

// Global head pointer pointing to the first node of the linked list
struct node *first;

// Function to handle various node insertion operations
void insert_node()
{
    struct node *temp, *nn;
    int ch, sel, num;

    // Dynamically allocate memory for the new node
    nn = (struct node *)malloc(sizeof(struct node));

    printf("enter element : ");
    scanf("%d", &nn->ele);

    nn->next = NULL;

    // Check if the linked list is currently empty
    if(first == NULL)
    {
        first = nn;
        printf("LIST CREATED\n");
    }
    else
    {
        // Menu for insertion choices if the list is not empty
        printf("\n1 => INSERT AT FIRST POSITION\n");
        printf("2 => INSERT AT LAST POSITION\n");
        printf("3 => INSERT AT SPECIFIED POSITION\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: // INSERT AT FIRST POSITION
            
            nn->next = first;
            first = nn;

            printf("NEW NODE IS INSERTED AT FIRST POSITION\n");

            break;

            case 2: // INSERT AT LAST POSITION

            temp = first;

            // Traverse to the last node
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            // Attach new node at the end
            temp->next = nn;

            printf("NEW NODE IS INSERTED AT LAST POSITION\n");

            break;

            case 3: // SPECIFIED POSITION
            
            printf("1 => INSERT AT ELEMENT NUMBER BASED\n");
            printf("2 => INSERT AT NODE NUMBER BASED\n");
            printf("ENTER YOUR PREFERENCE: ");
            scanf("%d", &ch);

            switch(ch)
            {  
                case 1: // INSERT AT ELEMENT NUMBER BASED 

                    printf("ENTER ELEMENT OF THAT NODE , AFTER WHICH YOU WANT TO PLACE THIS NEW NODE: ");
                    scanf("%d", &sel);

                    temp = first;

                    // Traverse until the matching element node or end of list is found
                    while(temp->ele != sel && temp != NULL)
                    {
                        temp = temp->next;
                    }

                    if(temp == NULL)
                    {
                        printf("NO SUCH NODE IS FOUND\n");
                    }
                    else
                    {
                        // Insert the new node after the matched node
                        nn->next = temp->next;
                        temp->next = nn;

                        printf("NEW NODE IS INSERTED AT SPECIFIED POSITION\n");
                    }

                    break;

                case 2: // INSERT AT NODE NUMBER BASED 
                
                printf("ENTER NODE NUMBER TO REMOVE: ");
                scanf("%d", &num);

                int count = 0;
                temp = first;

                // Traverse up to the specified node index count
                while(count < num && temp != NULL)
                {
                    temp = temp->next;
                    count++;
                }

                if(temp == NULL)
                {
                    printf("NO SUCH NODE IS FOUND\n");
                }
                else
                {
                    // Insert new node after the counted position node
                    nn->next = temp->next;
                    temp->next = nn;

                    printf("NEW NODE IS INSERTED AT SPECIFIED POSITION\n");
                }

                break;

            } // end of inner switch case       
            
         }// end of switch case

    }// end of else statement 

}// end of insert_node function


// Function to handle various node removal/deletion operations
void remove_node()
{
    struct node *nn, *temp, *temp2;
    int ch, sel, num, count;

    // Check if the list is empty
    if(first == NULL)
    {
        printf("LIST IS NOTE YET CREATED \n");
    }
    // Check if the list contains only a single node
    else if(first->next == NULL)
    {
        temp = first;
        first = NULL;
        free(temp);

        printf("LIST HAS ONLY ONE NODE AND IT IS REMOVED\n");
    }
    else
    {
        // Menu for removal options when multiple nodes exist
        printf("1 => REMOVE FIRST NODE\n");
        printf("2 => REMOVE LAST NODE\n");
        printf("3 => REMOVE SPECIFIED NODE\n");
        printf("WHICH NODE YOU WANT TO REMOVE :  ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: // REMOVE FIRST NODE 

            temp = first;
            first = first->next;
            free(temp);

            printf("FIRST NODE IS REMOVED\n");

            break;

            case 2: // REMOVE LAST NODE

            temp = first;

            // Traverse to the last node
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp2 = first;

            // Traverse to the second-to-last node
            while(temp2->next != temp)
            {
                temp2 = temp2->next;
            }

            temp2->next = NULL;
            free(temp);

            printf("LAST NODE IS REMOVED\n");

            break;

            case 3: // REMOVE SPECIFIED NODE

            printf("1 => REMOVE NODE SASED ON ELEMENT VALUE\n");
            printf("2 => REMOVE NODE BASED ON NODE NUMBER\n");
            printf("ENTER YOU WANT TO REMOVE : ");
            scanf("%d", &ch);

            switch(ch)
            {
                case 1: // REMOVE NODE BASED ON ELEMENT VALUE 

                printf("ENTER ELEMENT VALUE YOU WANT TO REMOVE NODE : ");
                scanf("%d", &sel);

                temp = first;

                // Traverse until the node with the target element value is found
                while(temp->ele != sel && temp != NULL)
                {
                    temp = temp->next;
                }

                if(temp == NULL)
                {
                    printf("NO SUCH NODE IS FOUND\n");
                }
                else
                {
                    temp2 = first;

                    // Traverse to the end of the list
                    while(temp2->next != NULL)
                    {
                        temp2 = temp2->next;
                    }

                    temp2->next = temp->next;
                    free(temp);

                    printf("REMOVED SPECIFIEC NODE\n");
                }

                break;


                case 2: // REMOVE NODE BASED ON NODE NUMBER 

                printf("ENTER NODE NUMBER YOU WANT TO REMOVED: ");
                scanf("%d", &num);

                temp = first;
                count = 1;

                // Traverse up to the target node position count
                while(count < num && temp != NULL)
                {
                    count++;
                    temp = temp->next;
                }

                if(temp == NULL)
                {
                    printf("NO SUCH ELEMENT IS FOUND\n");
                }
                else
                {
                    temp2 = first;

                    // Traverse to connect pointers appropriately for removal
                    while(temp2->next != NULL)
                    {
                        temp2 = temp->next; // (Preserving original logic)
                    }

                    temp2->next = temp->next;
                    free(temp);
                }

                break;

            } // end of inner switch case

        } // end of switch case 

    }// end of else statement

}// end of remove_node function


// Function to display all elements of the linked list
void display_list()
{
    struct node *temp;

    // Check if the list is empty
    if(first == NULL)
    {
        printf("LIST IS NOT CREATED\n");
    }
    else
    {
        temp = first;

        // Traverse through the entire list and print each element
        while(temp != NULL)
        {
            printf("%d\t", temp->ele);
            temp = temp->next;
        }

        printf("\n\n");

    } // end of else

}// end of display_list function

int main()
{
    int ch;
    first = NULL; // Initialize head pointer to NULL

    // Infinite loop to continuously present the menu options until exit
    while(1)
    {
        printf("\n1 => INSERT NODE OPRATION\n");
        printf("2 => REMOVE NODE OPRATION\n");
        printf("3 => DISPLAY LIST OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOUR OPRATION: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: // INSERT OPRATION
                 insert_node();
                 break;

            case 2: // REMOVE NODE OPRATION     
                 remove_node();
                 break;

            case 3: // DISPLAY LIST OPRATION
                display_list();
                break;

            case 4: // EXIT OPRATION 
                 exit(0);
                 break;

        } // END OF SWITCH CASE 

    }// END OF WHILE LOOP

    return 0;
}