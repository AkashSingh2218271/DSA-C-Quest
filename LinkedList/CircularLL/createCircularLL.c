#include <stdio.h>
#include <stdlib.h>

struct cll {
    int data;
    struct cll *next;
};

struct cll * create() {
    int x = 1;
    struct cll *temp, *newnode, *head = 0;
    while (x)
    {
        newnode = (struct cll *)malloc(sizeof(struct cll));
        printf("Enter a vaule to insert in circular linked list ");
        scanf("%d", &newnode->data);
        if (head == 0) {
            temp = head = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 for continue and 0 for exit ");
        scanf("%d", &x);
    }
    temp->next = head;
    return head;
}

void display(struct cll *head) {
    if (head == 0) {
        printf("Empty");
        return;
    } else {
        struct cll *temp = head;
        while (temp->next != head) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d->NULL\n", temp->data);
    }
}

int main() {
    struct cll * head = create();
    display(head);

    return 0;
}