#include <stdio.h>

void input(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void traverse(int *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element in array ");
    input(arr, n);
    printf("Array is ");
    traverse(arr, n);

    return 0;
}