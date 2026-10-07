#include<stdio.h>
#include<stdlib.h>

// TO DECALRE A STRUCTURE 

struct node
{
    struct node *prev; // 
    int ele;
    struct node *next;
};

struct node *first;
struct node *prev; 

// FUNCTION FOR INSERT NEW NODE 
void insert_node()
{
    struct node *nn,*temp,*temp2,*temp3;
    int sel,ch;

   // DYNAMICALLY ALLOCATE MEMORY FOR NEW NODE 

    nn = (struct node *)malloc(sizeof(struct node));

    // ACCEPECT DETALIS OF ELEMENT 
    printf("\nENTER ELEMENT : ");
    scanf("%d",&nn->ele);

    nn->next = NULL; // DECLEARE NN->NEXT POINTER VALUE IS NULL AT THE NEW NODE CREATE 
    nn->prev = NULL; // DECLEARE NN->PREV POINTER VALUE IS NULL AT THE NEW NODE CREATE 

    // CHECK IF LINKED LIST IS EP
    if(first == NULL)
    {
        first = nn;
    }
    else
    {        
        // MENU FOR INSERTION CHOICES IF THE ;IST IS NOT EMPTY        
        printf("\n\n1 => INSERT NEW NODE AT FIRST POSITION\n");
        printf("2 => INSERT NEW NODE AT LAST POSITION\n");
        printf("3 => INSERT NEW NODE AT SPECIFIC POSITION\n\n");
        printf("ENTER YOU WANT TO INSERT NEW NODE AT POSITION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // INSERT NEW NODE AT FIRST POSITINO

                  nn->next = first;
                  first->prev = nn;
                  first = nn;

                  printf("NEW NODE IS INSERTED AT FIRST POSITION\n");

                  break;

            case 2: // INSERT NEW NODE LAST POSITION
            
                   temp = first;
                   
                   // TRAVERSE AT LAST NODE 
                   while( temp->next != NULL)
                   {
                    temp = temp->next;
                   }
                   
                   // Attach new node at the end

                   temp->next = nn;
                   nn->prev = temp;
                   nn->next = NULL;

                   printf("NEW NODE IS INSERTED AT LAST POSITION\n");

                   break;

            case 3: // INSERT NEW NODE AT SPECIFIC POSITION 
            
                printf("\nENTER ELEMENT OD THAT NODE AFTER YOU INSERT NEW NODE : ");
                scanf("%d",&sel);

                temp = first;

                // TRAVERSE UNTIL THE MATCHING ELEMENT NODE OR END OF LIST IS SOUND 

                while(temp->ele!=sel && temp!=NULL)
                {
                    temp = temp->next;
                }

                if( temp == NULL)
                {
                    printf("/nNO SUCH NODE IS FOUND\n");
                }
                else
                {
                    // INSERT THE NEW NODE AFTER THE MATCHED NODE 
                    temp2 = temp->next;
                    nn->next = temp->next;
                    temp->next = nn;
                    nn->prev = temp;
                    temp2->prev = nn;

                    printf("\nNEW NODE IS INSERTED AT SPECIFIC POSITION\n");

                }

                break;

        } // END OF SWITCH CASE OF insert_node FUNCTION

    }// END OF ELSE STATEMENT OF insert_node FUNCTION
 
} // END OF insert_node FUNCTION 

// FUNCTION FOR REMOVE NODE 
void remove_node()
{
    struct node *nn,*temp,*temp2,*temp3;
    int ch,sel;

    // CHECK LEST IS EMPTY OR NOT 
    if(first == NULL)
    {
        printf("\nLIST IS NOT CREATED\n");
    }
    else
    {
        // MENU FOR REMOVING NODE 
        printf("\n\n1 => REMOVE FIRST NODE\n");
        printf("2 => REMOVE LAST NODE\n");
        printf("3 => REMOVE SPECIFIC NODE\n\n");
        printf("ENTER YOU WANT TO REMOVE WHICH NODE: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // REMOVE FIRST NODE 

                  temp = first;
                  first = first->next;
                  first->prev = NULL;
                  free(temp);

                  printf("\nFIRST NODE IS REMOVED\n");

                  break;

            case 2: // REMOVE LAST NODE
            
                  temp = first;

                  while(temp->next != NULL)
                  {
                    temp = temp->next;
                  }

                  temp2 = temp->prev;
                  temp2->next = NULL;
                  free(temp);

                  printf("\nLAST NODE IS REMOVED\n");

                  break;

            case 3: // REMOVE SPECIFIC NODE 

                 printf("\nENTER ELEMENT NODE YOU REMOVE THIS NODE: ");
                 scanf("%d",&sel);

                 temp = first;

                 while(temp->ele != sel && temp != NULL)
                 {
                    temp = temp->next;
                 }

                 if( temp == NULL)
                 {
                    printf("\n NO SUCH NODE IS FOUND\n");
                 }
                 else if(temp->ele == sel && temp == first)
                 {
                    // LOGIC OF REMOVE FIRST NODE 

                    temp = first;
                    first = first->next;
                    first->prev=NULL;
                    free(temp);

                    printf("\nLIST HAS ONLY ONE NODE AND IT IS REMOVED\n");
                 }
                 else if( temp == NULL )
                 {
                    // LOGIC FOR REMOVE LAST NODE 
                    temp = first;

                    while(temp->next!=NULL)
                    {
                        temp = temp->next; 
                    }

                    temp2 = temp->prev;
                    temp2->next = NULL;
                    free(temp);

                    printf("\nYOUR SPECIFIC NODE IS LAST NODE AND LAST NODE REMOVED\n");
                    
                 }
                 else
                 {
                    // LOGIC FOR REMOVE SPECIFIC NODE 
                    temp2 = first;

                    while(temp2->next != temp)
                    {
                        temp2 = temp->next;
                    }

                    temp2->next = temp->next;
                    temp3 = temp->next;
                    temp3->prev = temp2;
                    free(temp);

                    printf("\nSPECIFIC NODE IS REMOVED\n");

                 }

                 break;

        } // END OF SWITCH CASE OF remove_node function

    } // END OF ELSE STATEMENT ON remove_node FUNCTION

} // END OF remove_node FUNCTION 

// FUNCTION FOR DISPLAY LIST 
void display_list()
{
    struct node *temp,*temp2;
    int ch;

    if( first == NULL)
    {
        printf("\nLIST IS NOT CREATED \n");
    }
    else
    {
        printf("\n\n1 => DISPLAY IN REGULAR FORM \n");
        printf("2 => DISPLAY IN REVERSE ORDER \n");
        printf("ENTER YOU WANT TO DISPLAY: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // DISPLAY IN  FRONT ORDER  

            temp = first;

             while(temp!=NULL)
            {
                printf("%d\t",temp->ele);
                temp = temp->next;
            }

            printf("\n\n");

            break;

            case 2: // DISPLAY IN REVERSE ORDER 

                  temp = first;

                  while(temp->next!=NULL)
                  {
                    temp = temp->next;
                  } //  AT THE END TEMP POINTS TO LAST NODE 

                  temp2 = temp;

                  while(temp2!=NULL)
                  {
                    printf("%d\t",temp2->ele);
                    temp2 = temp2->prev;
                  }

                  printf("\n\n");

                  break;


        }
        

    } 
} // END OF display_list FUNCTION 

int main()
{
    int ch;
    first = NULL;
    prev = NULL;

    while(1)
    {
        printf("\n\n1 => INSERT NODE OPRATION\n");
        printf("2 => REMOVE NODE OPRATION\n");
        printf("3 => DISPLAY LIST OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOU WANT TO PERFORM : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // INSERT NODE OPRATION

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

    } // END OF WHILE LOOP

    return 0;

} // END OF FUNCTION 