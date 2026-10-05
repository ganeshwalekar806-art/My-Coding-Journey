#include <stdio.h>

struct bank_account
{
    long acc_no;
    char acc_type[50];
    double acc_bal;
    char acc_hol_name[50];
    char acc_ifsc[50];
};

int main()
{
    struct bank_account acc[100];

    int num;
    int i;

    printf("Enter how many accounts in your bank: ");
    scanf("%d", &num);

    printf("\nEnter details of account holders:\n");

    for(i = 0; i < num; i++)
    {
        printf("\n--- Account %d ---\n", i + 1);

        printf("Enter account number: ");
        scanf("%ld", &acc[i].acc_no);

        printf("Enter account type: ");
        scanf("%49s", acc[i].acc_type);

        printf("Enter account balance: ");
        scanf("%lf", &acc[i].acc_bal);

        printf("Enter account holder name: ");
        scanf("%49s", acc[i].acc_hol_name);

        printf("Enter bank IFSC code: ");
        scanf("%49s", acc[i].acc_ifsc);
    }

    printf("\n\n===== ACCOUNT DETAILS =====\n");

    for(i = 0; i < num; i++)
    {
        printf("\n--- Account %d ---\n", i + 1);

        printf("Account Number     : %ld\n", acc[i].acc_no);
        printf("Account Type       : %s\n", acc[i].acc_type);
        printf("Account Balance    : %.2lf\n", acc[i].acc_bal);
        printf("Account Holder     : %s\n", acc[i].acc_hol_name);
        printf("IFSC Code          : %s\n", acc[i].acc_ifsc);
    }

    return 0;
}