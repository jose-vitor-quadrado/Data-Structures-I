#include <stdio.h>

#define T 10

typedef struct {
    int topo;
    int elementos[T];
} Pilha;

void iniciar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int n) {
    if (p->topo >= T) {
        printf("Pilha cheia!\n");
        return;
    }
    p->elementos[++p->topo] = n;
}

int pop(Pilha *p) {
    if (p->elementos[p->topo] == -1) {
        printf("\nPilha vazia!\n");
        return;
    }

    return p->elementos[p->topo--];
}

void topo(Pilha *p) {
    if (p->elementos[p->topo] == -1) {
        printf("\nPilha vazia!\n");
        return;
    }
    printf("\nValor do topo: %d\n", p->elementos[p->topo]);
}

int main() {
    Pilha p;
    iniciar(&p);
    int op = 0;

    do {
        printf("\n 1 - Add:\n");
        printf(" 2 - Tira:\n");
        printf(" 3 - Topo:\n");
        printf(" 0 - Sair:\n");
        printf("--> ");
        scanf(" %d", &op);

        switch (op) {
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                int n;
                scanf(" %d", &n);
                push(&p, n);
                break;
            case 2:
                printf("\nRetirou: %d\n", pop(&p));
                break;
            case 3:
                topo(&p);
                break;
            default:
                printf("\nSaindo...\n");
                op = 4;
                break;
        }
    } while (op != 4);

    return 0;
}