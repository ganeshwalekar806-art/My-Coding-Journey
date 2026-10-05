#include<stdio.h>
#include<stdlib.h>

struct even_odd
{
    int num;
    struct even_odd *next;
};

int main()
{
    struct even_odd *first,*nn,*temp;
    first = NULL;
    
    char ch;

  do
  {
      // ALLOCATE MEMORY FOR NEW NODE 
    nn =(struct even_odd *)malloc(sizeof(struct even_odd));
  
    printf("enter any number: ");
    scanf("%d",&nn->num);

    nn->next = NULL;

     // CHECK LINKED LIST IS EMPTY
    if(first == NULL)
    {
        first = nn;
    }
    else
    {
        temp = first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next = nn;  // ATTACH NEW NODE AT END 

    }

    printf("do you want enter another number: ");
    scanf(" %c",&ch);

   }while(ch == 'y' || ch == 'Y');

   temp = first ;
   while(temp!=NULL)
   {
      if(temp->num %2 == 0) // CHECK NUMBER IS EVEN OR NOT 
      {
        printf("EVEN: %d\n",temp->num); // PRINT EVEN NUMBER OF LINKED LIST
      }
      else
      {
        printf("ODD: %d\n",temp->num); // PRINT ODD NUMBER OF LINKED LIST 
      }

      temp = temp->next; // INCREMENT 

   }

   return 0;
    
}