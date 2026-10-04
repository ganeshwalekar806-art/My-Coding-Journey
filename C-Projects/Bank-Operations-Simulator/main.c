#include<stdio.h>
#include<stdlib.h>

struct bankaccount 
{
    long accnum;
    char acctype;
    double accbalance;
    int pin;
   // char last_trans[30];
};

struct bankaccount ac[5];
long accnum;
int i,pin;
int ind;
int ch;

int ver_account(struct bankaccount temp[])
{
    printf(" enter bank account number: ");
    scanf("%ld",&accnum);

    for(i=0;i<=4;i++)
    {
        if(accnum == temp[i].accnum)
        {
            return i;

        }
    }

}

int main()
{
    printf("\n\n = = = = = = = ACCEPECTING DETAILS OF ACCOUNT HOLDER = = = = = = =  \n\n");

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
            case 1:

            ind = ver_account(ac);

            printf("enter pin number: ");
            scanf("%d",&pin);

            if( pin == ac[ind].pin)
            {
                printf("\nyour bank balance : %lf\n",ac[ind].accbalance);

            }

            break;


            case 2:

            double amount;

            ind = ver_account(ac);

            printf(" enter pin number: ");
            scanf("%d",&pin);

            if( pin == ac[ind].pin)
            {
                printf(" enter amount you can withdrawl: ");
                scanf("%lf",&amount);

                if( amount <= ac[ind].accbalance)
                {
                    ac[ind].accbalance = ac[ind].accbalance - amount ;

                    printf(" after withdrwal your bank balance was : %lf\n",ac[ind].accbalance);
                }

            }

            break;

            case 3:

            double depo;

            ind = ver_account(ac);

            printf(" enter amount you can deposite: ");
            scanf("%lf",&depo);

            ac[ind].accbalance = ac[ind].accbalance + depo ;

            printf(" after deposit your bank balance: %lf\n",ac[ind].accbalance);

            break;


            case 4: 

            ind = ver_account(ac);

            printf(" enter pin number: ");
            scanf("%d",&pin);

            if( pin == ac[ind].pin )
            {
                printf(" enter pin you can change: ");
                scanf("%d",&ac[ind].pin);

            }

            break;

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
            

            case 6:exit(0);


        } // end of switch case

    }while(ch!=6);

    return 0;

}
