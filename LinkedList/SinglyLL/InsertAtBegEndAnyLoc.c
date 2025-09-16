#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int data;
    struct sll *next;
};

struct sll *create()
{
    struct sll *temp, *newnode, *head = NULL;
    int ch = 1;
    while (ch)
    {
        newnode = (struct sll *)malloc(sizeof(struct sll));
        printf("Enter a value to insert in singly linked list ");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 to continue and 0 to exit ");
        scanf("%d", &ch);
    }
    newnode->next = NULL;
    
    return head;
}

void printll(struct sll *head)
{
    struct sll *temp = head;
    printf("Singly ll is ");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct sll *insertAtBeg(struct sll *head)
{
    struct sll *newnode, *temp = head;
    newnode = (struct sll *)malloc(sizeof(struct sll));
    printf("Enter a value to insert at beginning ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        temp = head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = temp;
        head = newnode;
    }

    return head;
}

void insertAtEnd(struct sll *head)
{
    struct sll *newnode, *temp = head;
    newnode = (struct sll *)malloc(sizeof(struct sll));
    printf("Enter a value to insert at end ");
    scanf("%d", &newnode->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

int lengthOfll(struct sll *head)
{
    struct sll *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

struct sll *insertAtloc(struct sll *head, int loc)
{
    struct sll *newnode, *temp = head;
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

        newnode = (struct sll *)malloc(sizeof(struct sll));
        printf("Enter a value to insert at %d location ", loc);
        scanf("%d", &newnode->data);
        int i = 1;

        while (i < loc - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
}

int main()
{
    int loc;
    struct sll *head = create();
    // print singly ll
    printll(head);
    // insert at beginning
    head = insertAtBeg(head);
    printll(head);
    // insert at end
    insertAtEnd(head);
    printll(head);
    // insert at specific location
    printf("Enter a loc to insert at ");
    scanf("%d", &loc);
    head = insertAtloc(head, loc);
    printll(head);

    return 0;
}