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
        printf("Enter a value to insert ");
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

struct sll *deletionAtBeg(struct sll *head)
{
    if (head == NULL)
        return head;
    struct sll *temp = head;
    head = temp->next;

    return head;
}

struct sll *deletionAtEnd(struct sll *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    struct sll *prev, *temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next; // 1-2
    }

    prev->next = NULL;

    return head;
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

struct sll *deletionAtloc(struct sll *head, int loc) {
    if (loc <= 0 || loc > lengthOfll(head)) {
        printf("Invalid position\n");
        return head;
    }
    if (loc == 1){
        head = deletionAtBeg(head);
        return head;
    }
    if (loc == lengthOfll(head)) {
        head = deletionAtEnd(head);
        return head;
    }

    int i = 1;
    struct sll *prev, *temp = head;

    while (i < loc) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;

    return head;
}

int main()
{
    int loc;
    struct sll *head = create();
    printll(head);
    // deletion at beginning
    head = deletionAtBeg(head);
    printll(head);
    // deletion at end
    head = deletionAtEnd(head);
    printll(head);
    // deletion at sepcific location
    printf("Enter a position to delete a element ");
    scanf("%d", &loc);
    head = deletionAtloc(head, loc);
    printll(head);

    return 0;
}