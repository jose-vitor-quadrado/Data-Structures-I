#include <stdio.h>

void triple(int *x) {
    (*x) *= 3;
}

int main() {
    int a = 3;

    printf("%d * 3 = ", a);
    triple(&a);
    printf("%d\n", a);

    return 0;
}