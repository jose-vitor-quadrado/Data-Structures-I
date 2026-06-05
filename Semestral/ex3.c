#include <stdio.h>

#define T 64

typedef struct {
    int topo;
    int elem[T];
} Pilha;

void inicia(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int n) {
    if (p->topo >= T - 1) {
        printf("Pilha cheia\n");
        return;
    }
    p->elem[++p->topo] = n;
}

int pop(Pilha *p) {
    return p->elem[p->topo--];
}

int main() {
    Pilha p;
    inicia(&p);
    int num;

    printf("Entrada: ");
    scanf(" %d", &num);

    while (num > 0) {
        int resto = num % 2;
        push(&p, resto);
        num /= 2;
    }

    while (p.topo > -1) {
        printf("%d", pop(&p));
    }
    printf("\n");

    return 0;
}