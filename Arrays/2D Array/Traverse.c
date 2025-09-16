#include <stdio.h>

void input(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void traverse(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter size of array ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter element of array ");
    input(n, arr);
    printf("Array is \n");
    traverse(n, arr);

    return 0;
}