#include <stdio.h>

#define T 10

typedef struct {
    int inicio;
    int fim;
    int elem[T];
} Fila;

void iniciar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

void inserir(Fila *f, int num) {
    if (f->fim >= T-1) {
        printf("Fila cheia\n");
        return;
    }

    f->fim++;
    f->elem[f->fim] = num;
}

int retirar(Fila *f) {
    if (f->fim < f->inicio) {
        printf("Fila vazia!\n");
        return -1;
    }

    int num = f->elem[f->inicio];
    f->inicio++;
    return num;
}

void mostrar(Fila f) {
    if (f.fim < f.inicio) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Valores pares:");
    for (int i = f.inicio; i <= f.fim; i++) {
        printf(" %d", f.elem[i]);
    }
    printf("\n");
}

int main() {
    Fila f, pares;
    iniciar(&f);
    iniciar(&pares);
    int op = 1;

    do {
        printf(" 1 - Inserir valor:\n");
        printf(" 0 - Sair\n");
        printf("--> ");
        scanf(" %d", &op);

        if (op == 1) {
            printf("Inserir valor: ");
            int num;
            scanf(" %d", &num);
            inserir(&f, num);
        }
    } while (op != 0);

    for (int i = f.inicio; i <= f.fim; i++) {
        if (f.elem[i] % 2 == 0) {
            inserir(&pares, f.elem[i]);
        }
    }

    mostrar(pares);

    return 0;
}