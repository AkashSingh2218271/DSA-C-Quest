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


struct dll * del_at_beg(struct dll *head) {
    if (head == 0)
    {
        printf("Empty\n");
        return head;
    } else if (head->next == 0) { 
        return 0;
    } else {
        struct dll *temp = head;
        head->next->prev = 0;
        head = head->next;
        free(temp);

    }
    return head;
}

struct dll * del_at_end(struct dll *head) {
    if (head == 0) {
        printf("Empty.\n");
        return head;
    } else if (head->next == 0) { 
        return 0;
    } else {
        struct dll *temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->prev->next = 0;
        free(temp);
    }
    return head;
}

int length(struct dll *head) {
    int cnt = 0;
    struct dll *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

struct dll * at_pos(struct dll *head) {
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
        struct dll *temp = head;
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
    struct dll *head = create();
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
