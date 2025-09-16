#include <stdio.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int *arr, int n, int idx, int *newArr, int val)
{
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }

    for (int i = 2 * n - 1; i > idx; i--)
    {
        newArr[i] = newArr[i - 1];
    }
    newArr[idx] = val;
}

int main()
{
    int n, idx, val;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n], newArr[2 * n];
    printf("Enter element in array ");
    input(arr, n);
    printf("Enter a index to insert at ");
    scanf("%d", &idx);
    printf("Enter a value to insert ");
    scanf("%d", &val);
    if (idx < 2 * n)
    {
        insert(arr, n, idx, newArr, val);
        printf("Previous array is ");
        traverse(arr, n);
        printf("New array is ");
        traverse(newArr, n + 1);
    }
    else
    {
        printf("Invalid index");
    }

    return 0;
}