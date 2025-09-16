#include <stdio.h>

int main() {
    int *q;
    int a[] = {1, 3, 4, 5}; // array name itself act as pointer
    printf("%p\n", a); // base address of pointer will be printed
    q = a;
    printf("%p\n", q); // same as above
    // q++; is allowed q++ == (q + 1)
    // a = &a , q != &q
    /* a[i] = *(a + i)*/
    int i = 1;
    printf("a[i] = %d == *(a + i) = %d == *(q + i) = %d == *(i + q) = %d == i[q] = %d\n", a[i], *(a + i), *(q + i), *(i + q), i[q]);

    return 0;
}