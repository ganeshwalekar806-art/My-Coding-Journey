#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shop
{
    int pro_id;
    char pro_name[50];
    double pro_price;
    int pro_quantity;
};

/* ---------- ADD PRODUCT ---------- */

void add_product(struct shop **p, int *count, int *capacity)
{
    /* If array is full, increase capacity */
    if (*count == *capacity)
    {
        *capacity = *capacity * 2;

        *p = realloc(*p, (*capacity) * sizeof(struct shop));

        if (*p == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("\nEnter product id: ");
    scanf("%d", &(*p)[*count].pro_id);

    printf("Enter product name: ");
    scanf(" %49[^\n]", (*p)[*count].pro_name);

    printf("Enter product price: ");
    scanf("%lf", &(*p)[*count].pro_price);

    printf("Enter product quantity: ");
    scanf("%d", &(*p)[*count].pro_quantity);

    (*count)++;

    printf("\nProduct added successfully!\n");
}

/* ---------- DISPLAY PRODUCTS ---------- */

void display_products(struct shop *p, int count)
{
    if (count == 0)
    {
        printf("\nNo products available.\n");
        return;
    }

    printf("\n---------- ALL PRODUCTS ----------\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nProduct %d\n", i + 1);
        printf("ID       : %d\n", p[i].pro_id);
        printf("Name     : %s\n", p[i].pro_name);
        printf("Price    : %.2lf\n", p[i].pro_price);
        printf("Quantity : %d\n", p[i].pro_quantity);
    }
}

/* ---------- SEARCH PRODUCT ---------- */

void search_product(struct shop *p, int count)
{
    int id;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (p[i].pro_id == id)
        {
            printf("\nProduct found!\n");
            printf("ID       : %d\n", p[i].pro_id);
            printf("Name     : %s\n", p[i].pro_name);
            printf("Price    : %.2lf\n", p[i].pro_price);
            printf("Quantity : %d\n", p[i].pro_quantity);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct not found!\n");
    }
}

/* ---------- UPDATE PRODUCT ---------- */

void update_product(struct shop *p, int count)
{
    int id;
    int choice;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (p[i].pro_id == id)
        {
            found = 1;

            while (1)
            {
                printf("\n----- UPDATE MENU -----\n");
                printf("1. Update ID\n");
                printf("2. Update Name\n");
                printf("3. Update Price\n");
                printf("4. Update Quantity\n");
                printf("5. Exit\n");

                printf("Enter choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        printf("Enter new id: ");
                        scanf("%d", &p[i].pro_id);
                        break;

                    case 2:
                        printf("Enter new name: ");
                        scanf(" %49[^\n]", p[i].pro_name);
                        break;

                    case 3:
                        printf("Enter new price: ");
                        scanf("%lf", &p[i].pro_price);
                        break;

                    case 4:
                        printf("Enter new quantity: ");
                        scanf("%d", &p[i].pro_quantity);
                        break;

                    case 5:
                        return;

                    default:
                        printf("Invalid choice!\n");
                }
            }
        }
    }

    if (!found)
    {
        printf("\nProduct not found!\n");
    }
}

/* ---------- SELL PRODUCT ---------- */

void sell_product(struct shop *p, int count)
{
    int id;
    int quantity;

    printf("\nEnter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (p[i].pro_id == id)
        {
            printf("Available quantity: %d\n", p[i].pro_quantity);

            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                return;
            }

            if (quantity > p[i].pro_quantity)
            {
                printf("Not enough stock!\n");
                return;
            }

            p[i].pro_quantity -= quantity;

            printf("\nProduct sold successfully!\n");
            printf("Remaining quantity: %d\n", p[i].pro_quantity);

            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* ---------- ADD STOCK ---------- */

void add_stock(struct shop *p, int count)
{
    int id;
    int quantity;

    printf("\nEnter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (p[i].pro_id == id)
        {
            printf("Current quantity: %d\n", p[i].pro_quantity);

            printf("Enter quantity to add: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                return;
            }

            p[i].pro_quantity += quantity;

            printf("\nStock added successfully!\n");
            printf("New quantity: %d\n", p[i].pro_quantity);

            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* ---------- DELETE PRODUCT ---------- */

void delete_product(struct shop *p, int *count)
{
    int id;

    printf("\nEnter product id to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (p[i].pro_id == id)
        {
            /* Shift all next elements one position left */

            for (int j = i; j < *count - 1; j++)
            {
                p[j] = p[j + 1];
            }

            (*count)--;

            printf("\nProduct deleted successfully!\n");
            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* ---------- LOW STOCK ---------- */

void low_stock(struct shop *p, int count)
{
    int found = 0;

    printf("\n---------- LOW STOCK PRODUCTS ----------\n");

    for (int i = 0; i < count; i++)
    {
        if (p[i].pro_quantity <= 5)
        {
            printf("\nID       : %d\n", p[i].pro_id);
            printf("Name     : %s\n", p[i].pro_name);
            printf("Quantity : %d\n", p[i].pro_quantity);

            found = 1;
        }
    }

    if (!found)
    {
        printf("No low-stock products.\n");
    }
}

/* ---------- HIGHEST PRICE ---------- */

void highest_price(struct shop *p, int count)
{
    if (count == 0)
    {
        printf("\nNo products available.\n");
        return;
    }

    int index = 0;

    for (int i = 1; i < count; i++)
    {
        if (p[i].pro_price > p[index].pro_price)
        {
            index = i;
        }
    }

    printf("\n---------- HIGHEST PRICE PRODUCT ----------\n");
    printf("ID       : %d\n", p[index].pro_id);
    printf("Name     : %s\n", p[index].pro_name);
    printf("Price    : %.2lf\n", p[index].pro_price);
    printf("Quantity : %d\n", p[index].pro_quantity);
}

/* ---------- TOTAL INVENTORY VALUE ---------- */

void total_inventory_value(struct shop *p, int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total += p[i].pro_price * p[i].pro_quantity;
    }

    printf("\nTotal Inventory Value = %.2lf\n", total);
}

/* ---------- SORT BY PRICE ---------- */

void sort_by_price(struct shop *p, int count)
{
    struct shop temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (p[j].pro_price > p[j + 1].pro_price)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nProducts sorted by price successfully!\n");
}

/* ---------- MAIN ---------- */

int main()
{
    struct shop *shop1;

    int count = 0;
    int capacity = 5;
    int choice;

    /* Initial dynamic memory */
    shop1 = malloc(capacity * sizeof(struct shop));

    if (shop1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1)
    {
        printf("\n\n====================================\n");
        printf("       STOCK MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1.  Add Product\n");
        printf("2.  Display All Products\n");
        printf("3.  Search Product\n");
        printf("4.  Update Product\n");
        printf("5.  Sell Product\n");
        printf("6.  Add Stock\n");
        printf("7.  Delete Product\n");
        printf("8.  Low Stock Products\n");
        printf("9.  Highest Price Product\n");
        printf("10. Total Inventory Value\n");
        printf("11. Sort Products by Price\n");
        printf("12. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_product(&shop1, &count, &capacity);
                break;

            case 2:
                display_products(shop1, count);
                break;

            case 3:
                search_product(shop1, count);
                break;

            case 4:
                update_product(shop1, count);
                break;

            case 5:
                sell_product(shop1, count);
                break;

            case 6:
                add_stock(shop1, count);
                break;

            case 7:
                delete_product(shop1, &count);
                break;

            case 8:
                low_stock(shop1, count);
                break;

            case 9:
                highest_price(shop1, count);
                break;

            case 10:
                total_inventory_value(shop1, count);
                break;

            case 11:
                sort_by_price(shop1, count);
                break;

            case 12:
                free(shop1);
                printf("\nProgram exited successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
