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

struct cll * del_at_beg(struct cll *head) {
    if (head == 0) {
        printf("Empty\n");
        return head;
    } else {
        int len = length(head);
        if (len == 1) {
            head = NULL;
            return head;
        }
        struct cll *tail, *temp;
        temp = tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        free(temp);
    }
    return head;
}

struct cll * del_at_end(struct cll *head) {
    if (head == 0) {
        printf("Empty\n");
        return head;
    } else {
        int len = length(head);
        if (len == 1) {
            head = NULL;
            return head;
        }
        struct cll *prev, *temp;
        temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;
}


struct cll * at_pos(struct cll *head) {
    int pos;
    printf("Enter the postion you want delete from ");
    scanf("%d", &pos);
    int len = length(head);
    if (pos > len || pos < 1) {
        printf("Invalid position\n");
        return head;
    } else if (pos == 1) {
        head = del_at_beg(head);
    } else if (pos == len) {
        head = del_at_end(head);
    } else {
        struct cll *prev, *temp = head;
        int i = 1;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp); 
    }
    return head;
}

int main() {
    struct cll * head = create();
    display(head);
    printf("circular linked list after deletion at begin\n");
    head = del_at_beg(head);
    display(head);
    printf("Circular linked list after deletion at end\n");
    head = del_at_end(head);
    display(head);
    printf("circular linked list after deletion at position\n");
    head = at_pos(head);
    display(head);

    return 0;
}