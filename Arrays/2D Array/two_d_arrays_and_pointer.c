#include <stdio.h>


int main() {
    int a[2][2] = {1, 2, 3, 4};
    int *p;
    p = &a[0][0];
    // or p = &a[0]
    printf("%p\n", p);
    printf("%d\n", *(*(a + 1) + 1)); //4
    printf("a[1][1] = %d\n", a[1][1]);

    printf("a[1] + 1 = %p\n", (a[1] + 1));
    printf("&a[1] + 1 = %p\n", (&a[1] + 1));
    return 0;
}