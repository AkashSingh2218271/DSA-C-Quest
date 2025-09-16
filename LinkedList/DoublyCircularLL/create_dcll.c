#include <stdio.h>
#include <stdlib.h>

struct dcll
{
    int data;
    struct dcll *next, *prev;
};

struct dcll *create()
{
    struct dcll *temp, *newnode, *head = NULL;
    int ch = 1;
    while (ch)
    {
        newnode = (struct dcll *)malloc(sizeof(struct dcll));
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
    newnode->next = head;
    head->prev = temp;

    return head;
}

void printll(struct dcll *head)
{
    struct dcll *temp = head;
    printf("Doubly circular ll is ");

    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL\n", temp->data);
}

int main()
{
    struct dcll *head = create();
    printll(head);

    return 0;
}