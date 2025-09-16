#include <stdio.h>
#include <stdlib.h>

struct sll {
    int data;
    struct sll *next;
};

struct sll* create() {
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
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 to continue and 0 to exit ");
        scanf("%d", &ch);
    }
    newnode->next = NULL;
    
    return head;
}

void printll(struct sll *head) {
    struct sll *temp = head;
    printf("Singly ll is ");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct sll *head = create();
    printll(head);

    return 0;
}