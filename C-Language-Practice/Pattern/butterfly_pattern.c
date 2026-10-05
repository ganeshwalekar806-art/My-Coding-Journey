#include <stdio.h>

int main()
{
    int i, j, n = 4;

    // Upper part
    for(i = 1; i <= n; i++)
    {
        // Left stars
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }

        // Spaces
        for(j = 1; j <= 2 * (n - i); j++)
        {
            printf(" ");
        }

        // Right stars
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    // Lower part
    for(i = n; i >= 1; i--)
    {
        // Left stars
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }

        // Spaces
        for(j = 1; j <= 2 * (n - i); j++)
        {
            printf(" ");
        }

        // Right stars
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
