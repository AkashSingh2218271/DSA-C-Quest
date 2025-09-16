#include <stdio.h>
#include <stdlib.h>

struct dll
{
    int data;
    struct dll *next, *prev;
};

struct dll *create()
{
    struct dll *temp, *newnode, *head = NULL;
    int ch = 1;
    while (ch)
    {
        newnode = (struct dll *)malloc(sizeof(struct dll));
        printf("Enter a value to insert ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        if (head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 to continue and 0 to exit ");
        scanf("%d", &ch);
    }
    newnode->next = NULL;

    return head;
}

void printll(struct dll *head)
{
    struct dll *temp = head;
    printf("Doubly ll is ");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct dll *head = create();
    printll(head);

    return 0;
}