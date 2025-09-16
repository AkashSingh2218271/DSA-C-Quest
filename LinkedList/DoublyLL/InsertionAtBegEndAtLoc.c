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

struct dll *insertAtBeg(struct dll *head)
{
    struct dll *newnode, *temp = head;
    newnode = (struct dll *)malloc(sizeof(struct dll));
    printf("Enter a value to insert at beginning ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    if (head == NULL)
    {
        temp = head = newnode;
        newnode->next = NULL;
    }
    else
    {
        temp->prev = newnode;
        newnode->next = temp;
        head = newnode;
    }

    return head;
}

void insertAtEnd(struct dll *head)
{
    struct dll *newnode, *temp = head;
    newnode = (struct dll *)malloc(sizeof(struct dll));
    printf("Enter a value to insert at end ");
    scanf("%d", &newnode->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    newnode->next = NULL;
}

int lengthOfll(struct dll *head)
{
    struct dll *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

struct dll *insertAtloc(struct dll *head, int loc)
{
    struct dll *newnode, *temp = head;
    if (loc <= 0 || loc > lengthOfll(head) + 1)
    {
        printf("Invalid postion\n");
        return head;
    }
    else
    {
        if (loc == 1) {
            head = insertAtBeg(head);
            return head;
        }

        if (loc == lengthOfll(head) + 1) {
            insertAtEnd(head);
            return head;
        }

        newnode = (struct dll *)malloc(sizeof(struct dll));
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
        temp->next = newnode;
    }

    return head;
}

int main()
{
    int loc;
    struct dll *head = create();
    printll(head);
    // insert at beginning 
    head = insertAtBeg(head);
    printll(head);
    // insert at end
    insertAtEnd(head);
    printll(head);
    // insert at any specific position
    printf("Enter a location to insert the node ");
    scanf("%d", &loc);
    head = insertAtloc(head, loc);
    printll(head);

    return 0;
}