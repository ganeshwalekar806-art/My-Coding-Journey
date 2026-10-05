#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ele;
    struct node *next;
};

int main()
{
    struct node *first = NULL;
    struct node *nn, *temp;
    char ch;

    // नोड्स तयार करणे आणि लिंक लिस्ट बनवणे
    do
    {
        nn = (struct node *)malloc(sizeof(struct node));

        printf("Enter any number: ");
        scanf("%d", &nn->ele);

        nn->next = NULL;

        if (first == NULL)
        {
            first = nn;
        }
        else
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }

        printf("Do you want to enter another number (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    // ==========================================
    // ट्रॅव्हर्सिंग (Traversing / Displaying)
    // ==========================================
    printf("\nLinked List Elements: ");
    
    if (first == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = first; // १. पहिल्या नोडपासून सुरुवात
        while (temp != NULL) // २. शेवटचा नोड संपेपर्यंत फिरणे
        {
            printf("%d -> ", temp->ele); // ३. व्हॅल्यू प्रिंट करणे
            temp = temp->next;          // ४. पुढच्या नोडवर जाणे
        }
        printf("NULL\n");
    }

    return 0;
}