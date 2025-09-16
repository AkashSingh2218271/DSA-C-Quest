#include <stdio.h>
#include <stdlib.h>

struct cll {
    int data;
    struct cll *next;
};

// Function to create a circular linked list
struct cll * create() {
    int x = 1;
    struct cll *temp, *newnode, *head = NULL;
    while (x) {
        newnode = (struct cll *)malloc(sizeof(struct cll));
        printf("Enter a value to insert in circular linked list: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d", &x);
    }
    temp->next = head;  // make it circular
    return head;
}

// Function to display a circular linked list
void display(struct cll *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct cll *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
}

// Function to reverse a circular linked list (iterative approach)
struct cll * reverse(struct cll *head) {
    if (head == NULL || head->next == head)  // empty or single node
        return head;

    struct cll *prev = NULL, *curr = head, *next = NULL, *tail = head;

    // find last node (tail) to fix circularity later
    while (tail->next != head)
        tail = tail->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    // Fix last link
    head->next = prev;
    head = prev;

    return head;
}

int main() {
    struct cll *head = create();
    printf("Original circular linked list:\n");
    display(head);

    printf("Circular linked list after reversing:\n");
    head = reverse(head);
    display(head);

    return 0;
}
