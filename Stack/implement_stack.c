#include <stdio.h>
#include <stdbool.h>
#define M 5

int top = -1;
int st[M];

void push(int x)
{
    if (top == (M - 1))
    {
        printf("stack overflow\n");
        return;
    }
    st[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    return st[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return st[top];
}

bool isFull()
{
    return top == (M - 1);
}

bool isEmpty()
{
    return top == -1;
}

void display()
{
    printf("Stack is ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", st[i]);
    }
    printf("\n");
}

int main()
{
    int x = 1;
    do
    {
        int ch;
        printf("Enter you choice\n");
        printf("1 for push\n2 for pop\n3 for peek\n4 for isFull\n5 isEmpty\n6 display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int a;
            printf("Enter a element to push in stack\n");
            scanf("%d", &a);
            push(a);
        }
        break;
        case 2:
            // printf("If element if -1 then stack is underflow\n");
            printf("Poped element is %d\n", pop());
            break;
        case 3:
            printf("top most element in stack is %d\n", peek());
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 5:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 6:
            display();
            break;
        default:
            printf("Wrong choice try again ! ");
            scanf("%d", &ch);
            break;
        }
        printf("Do you want to continue press 1 and to exit press 0\n");
        scanf("%d", &x);
    } while (x != 0);

    return 0;
}