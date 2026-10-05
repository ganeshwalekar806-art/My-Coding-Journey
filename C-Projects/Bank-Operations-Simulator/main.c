#include<stdio.h>
#include<stdlib.h>

// Structure to store bank account details
struct bankaccount 
{
    long accnum;     // Account number
    char acctype;    // Account type (e.g., 'S' for Savings, 'C' for Current)
    double accbalance; // Account balance
    int pin;         // Security PIN
   // char last_trans[30];
};

// Global variables
struct bankaccount ac[5]; // Array to store details of 5 bank accounts
long accnum;
int i,pin;
int ind;
int ch;

// Function to verify and search for the bank account number
int ver_account(struct bankaccount temp[])
{
    printf(" enter bank account number: ");
    scanf("%ld",&accnum);

    // Loop to match the entered account number with array records
    for(i=0;i<=4;i++)
    {
        if(accnum == temp[i].accnum)
        {
            return i; // Return index if account is found

        }
    }

}

int main()
{
    printf("\n\n = = = = = = = ACCEPECTING DETAILS OF ACCOUNT HOLDER = = = = = = =  \n\n");

    // Input loop to collect details for 5 account holders
    for(i=0;i<=4;i++)
    {
        printf("enter bank account number:  ");
        scanf("%ld",&ac[i].accnum);

        printf("enter account type:  ");
        scanf(" %c",&ac[i].acctype);

        printf("enter account balance: ");
        scanf("%lf",&ac[i].accbalance);

        printf("enter account pin: ");
        scanf("%d",&ac[i].pin);


        printf("\n\n enter account details of another holder \n \n");

       // printf("enter last transication date: \n\n");
       //  scanf("%s",&ac[i].last_trans);

    }

    // Menu-driven loop for performing banking operations
    do
    {
        printf(" \n-- -- -- -- --  ENTER YOUR OPERATION  -- -- -- -- -- \n\n");
        printf("1 --> BALANCE ENQUIRY\n");
        printf("2 --> CASH WITHDRAWAL\n");
        printf("3 --> DEPOSITE\n");
        printf("4 --> PIN CHANGE  ");
        printf("5 --> CHANGE ACCOUNT TYPE \n");
        printf("6 --> EXIT\n\n");
        
        printf("enter your operation: ");
        scanf("%d",&ch);

        switch(ch)
        {
            // Case 1: Check account balance
            case 1:

            ind = ver_account(ac);

            printf("enter pin number: ");
            scanf("%d",&pin);

            // Display balance if PIN matches
            if( pin == ac[ind].pin)
            {
                printf("\nyour bank balance : %lf\n",ac[ind].accbalance);

            }

            break;


            // Case 2: Withdraw money
            case 2:

            double amount;

            ind = ver_account(ac);

            printf(" enter pin number: ");
            scanf("%d",&pin);

            if( pin == ac[ind].pin)
            {
                printf(" enter amount you can withdrawl: ");
                scanf("%lf",&amount);

                // Check for sufficient balance before withdrawal
                if( amount <= ac[ind].accbalance)
                {
                    ac[ind].accbalance = ac[ind].accbalance - amount ;

                    printf(" after withdrwal your bank balance was : %lf\n",ac[ind].accbalance);
                }

            }

            break;

            // Case 3: Deposit money
            case 3:

            double depo;

            ind = ver_account(ac);

            printf(" enter amount you can deposite: ");
            scanf("%lf",&depo);

            // Add deposit amount to the current balance
            ac[ind].accbalance = ac[ind].accbalance + depo ;

            printf(" after deposit your bank balance: %lf\n",ac[ind].accbalance);

            break;


            // Case 4: Change security PIN
            case 4: 

            ind = ver_account(ac);

            printf(" enter pin number: ");
            scanf("%d",&pin);

            // Update PIN if current PIN is correct
            if( pin == ac[ind].pin )
            {
                printf(" enter pin you can change: ");
                scanf("%d",&ac[ind].pin);

            }

            break;

            // Case 5: Change account type
            case 5:

            ind = ver_account(ac);

            printf(" enter pin number: ");
            scanf("%d",&pin);

            if( pin == ac[ind].pin)
            {
                printf(" enter account type you can change : ");
                scanf(" %c",ac[ind].acctype);

                printf(" after change account type: %c \n",ac[ind].acctype);

            }

            break;
            

            // Case 6: Exit the program
            case 6:exit(0);


        } // End of switch statement

    }while(ch!=6); // Continue loop until user selects exit option (6)

    return 0;

}
