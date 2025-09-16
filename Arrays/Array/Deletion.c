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

void deletion(int *arr, int n, int val) {
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            idx = i;
        }
    }
    if (idx == -1) {
        printf("Invalid index");    
    }
    
    for (int i = idx; i < n - 1; i++) {
        arr[idx] = arr[idx + 1];
    }
}

int main() {
    int n, val;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element in array ");
    input(arr, n);
    printf("Enter a value to delete from array ");
    scanf("%d", &val);
    printf("Array before deletion is ");
    traverse(arr, n);
    deletion(arr, n, val);
    printf("Array after deletion is ");
    traverse(arr, n - 1);

    return 0;
}