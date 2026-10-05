#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;    // Pointer to dynamically allocate memory for integers
    char ch;   // Character variable to store the user's choice to continue
    
    // Loop to repeatedly accept numbers from the user
    do
    {
        // Dynamically allocate memory for an integer using malloc
        p = (int *)malloc(sizeof(int));

        // Accept the number from the user and store it in the allocated memory location
        printf("enter any number: ");
        scanf("%d", &(*p));

        // Ask the user if they want to enter another number
        printf("do you want enter another number: ");
        scanf(" %c", &ch);

    } while (ch == 'y'); // Continue the loop if the user enters 'y'

    // Print the last entered number stored in pointer p
    // (Note: Previous memory allocations are overwritten in each iteration, which causes a memory leak, 
    // but the logic remains unchanged as requested)
    printf("enter number is : %d", *p);

    return 0;
}
}