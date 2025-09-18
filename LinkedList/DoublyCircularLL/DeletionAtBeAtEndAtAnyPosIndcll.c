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

struct dcll * del_at_beg(struct dcll *head) {
    if (head == 0)
    {
        printf("Empty\n");
        return head;
    } else if (head->next == head) { 
        return 0;
    } else {
        struct dcll *temp = head, *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = head->next;
        head->next->prev = tail;
        head = head->next;
        free(temp);
    }
    return head;
}

struct dcll * del_at_end(struct dcll *head) {
    if (head == 0) {
        printf("Empty.\n");
        return head;
    } else if (head->next == head) { 
        return 0;
    } else {
        struct dcll *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
    }
    return head;
}

int length(struct dcll *head) {
    int cnt = 0;
    struct dcll *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        cnt++;
    }
    cnt++;
    return cnt;
}

struct dcll * at_pos(struct dcll *head) {
    int pos = 0;
    printf("Enter the position you want to delete node from ");
    scanf("%d", &pos);
    if (pos < 1 && pos > (length(head) + 1))
    {
        printf("Invaild position\n");
        return head;
    } else if (pos == 1) {
        head = del_at_beg(head);
    } else if (pos == length(head)) {
        head = del_at_end(head);
    } else {
        int i = 1;
        struct dcll *temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return head;
}

int main()
{
    struct dcll *head = create();
    printll(head);
    printf("dcll after deletion at begin\n");
    head = del_at_beg(head);
    printll(head);
    printf("dcll after del at end\n");
    head = del_at_end(head);
    printll(head);
    printf("dcll after del at pos\n");
    head = at_pos(head);
    printll(head);

    return 0;
}