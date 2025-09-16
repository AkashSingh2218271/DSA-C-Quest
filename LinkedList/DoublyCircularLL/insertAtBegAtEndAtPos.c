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

struct dcll *insertAtBeg(struct dcll *head)
{
    struct dcll *newnode, *temp = head;
    newnode = (struct dcll *)malloc(sizeof(struct dcll));
    printf("Enter a value to insert at beginning ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    if (head == NULL)
    {
        temp = head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        temp = head;
        newnode->next = head;
        head->prev = newnode;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        head = newnode;
    }

    return head;
}

struct dcll * insertAtEnd(struct dcll *head)
{
    struct dcll *newnode, *temp = head;
    newnode = (struct dcll *)malloc(sizeof(struct dcll));
    printf("Enter a value to insert at end ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        temp = head = newnode;
        newnode->next = head;
        newnode->prev = head;
        return head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->prev = temp;
        temp->next = newnode;
        newnode->next = head;
        head->prev = newnode;
    }
    return head;
}

int lengthOfll(struct dcll *head)
{
    struct dcll *temp = head;
    int len = 0;

    while (temp->next != head)
    {
        len++;
        temp = temp->next;
    }
    len++;
    return len;
}

struct dcll *insertAtloc(struct dcll *head, int loc)
{
    struct dcll *newnode, *temp = head;
    if (loc <= 0 || loc > lengthOfll(head) + 1)
    {
        printf("Invalid postion\n");
        return head;
    }
    else
    {
        if (loc == 1)
        {
            head = insertAtBeg(head);
            return head;
        }

        if (loc == lengthOfll(head) + 1)
        {
            head = insertAtEnd(head);
            return head;
        }

        newnode = (struct dcll *)malloc(sizeof(struct dcll));
        printf("Enter a value to insert at %d location ", loc);
        scanf("%d", &newnode->data);
        int i = 1;

        while (i < loc - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    return head;
}

int main()
{
    int loc;
    struct dcll *head = create();
    printll(head);
    // insert at beginning
    head = insertAtBeg(head);
    printll(head);
    // insert at end
    head = insertAtEnd(head);
    printll(head);
    // insert at any specific position
    printf("Enter a location to insert the node ");
    scanf("%d", &loc);
    head = insertAtloc(head, loc);
    printll(head);

    return 0;
}