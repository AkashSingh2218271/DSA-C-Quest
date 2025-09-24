#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};

struct stack* push(struct stack *top, int x) {
    struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = x;
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    return top;
}

int pop(struct stack **top) {
    if (top == NULL || *top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int val = (*top)->data;
    struct stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return val;
}

int peek(struct stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(struct stack *top) {
    struct stack *temp = top;
    printf("Stack is ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct stack *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top);
    printf("Popped element: %d\n", pop(&top));
    printf("Top element: %d\n", peek(top));
    display(top);
    return 0;
}