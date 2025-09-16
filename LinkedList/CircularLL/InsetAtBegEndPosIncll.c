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
        printf("Empty\n");
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

struct cll * insert_at_beg(struct cll *head) {
    struct cll *newnode, *temp = 0;
    newnode = (struct cll *)malloc(sizeof(struct cll));
    printf("Enter the value you want to insert at begin ");
    scanf("%d", &newnode->data);
    if (head == 0) {    
        temp = head = newnode;
        temp->next = head;
    } else {
        temp = head;
        newnode->next = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        head = newnode;
    }
    return head;
}

struct cll * insert_at_end(struct cll *head) {
    struct cll *newnode, *temp = 0;
    newnode = (struct cll *)malloc(sizeof(struct cll));
    printf("Enter a value to insert at end of cll \n");
    scanf("%d", &newnode->data);
    if (head == 0) {
        temp = head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
    }
    return head;
}

int length(struct cll *head) {
    int cnt = 0;
    if (head == 0) {
        return cnt;
    } else {
        struct cll *temp = head;
        while (temp->next != head) {
            temp = temp->next;
            cnt++;
        }
        cnt++;
    }
    return cnt;
}

struct cll * at_pos(struct cll *head) {
    struct cll *newnode, *temp = 0;
    int pos; 
    printf("Enter the position you want to insert at ");
    scanf("%d", &pos);
    int len = length(head);
    if (pos < 1 || pos > (len + 2)) {
        printf("Invalid position\n");
    } else if (pos == 1) {
        head = insert_at_beg(head);
    } else if (pos == (len + 1)) {
        head = insert_at_end(head);
    } else {
        newnode = (struct cll *)malloc(sizeof(struct cll));
        printf("Enter the value you want to insert at %d ", pos);
        scanf("%d", &newnode->data);
        temp = head;
        int i = 1;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

int main() {
    struct cll * head = create();
    display(head);
    printf("circular linked list after insert at begin\n");
    head = insert_at_beg(head);
    display(head);
    printf("Circular linked list after insert at end\n");
    head = insert_at_end(head);
    display(head);
    printf("Circular linked list after insert at position\n");
    head = at_pos(head);
    display(head);
    
    return 0;
}