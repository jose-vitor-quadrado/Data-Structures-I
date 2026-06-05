#include <stdio.h>

int main() {
    int i = 7, j = 5, c;
    int *p, **q;
    p = &i;
    q = &p;
    c = (**q) + (*p) * i;

    printf("i=%d, j=%d, c=%d\n", i, j, c);

    return 0;
}