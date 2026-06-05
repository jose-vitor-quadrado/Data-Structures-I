#include <stdio.h>

#define T 10

typedef struct {
    int inicio;
    int fim;
    char elem[T];
} Fila;

void inicia(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

void inserir(Fila *f) {
    if (f->fim == T-1) {
        printf("\nFila cheia\n");
        return;
    }

    printf("Digite o valor a ser inserido: ");
    char c;
    scanf(" %c", &c);

    f->fim++;
    f->elem[f->fim] = c;
}

char retirar(Fila *f) {
    char c;
    c = f->elem[f->inicio];
    f->inicio++;
    return c;
}

void mostrarFila(Fila f) {
    for (int i = f.inicio; i <= f.fim; i++) {
        printf(" %c", f.elem[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    int op = 10;
    inicia(&f);

    do {
        printf("\n 1 - Add:\n");
        printf(" 2 - Remover:\n");
        printf(" 3 - Mostrar:\n");
        printf("--> ");
        scanf(" %d", &op);

        switch (op) {
            case 1:            
                inserir(&f);
                break;
            case 2:
                printf("Retirou: %c\n", retirar(&f));
                break;
            case 3:
                mostrarFila(f);
                break;
            default:
                printf("Saindo...\n");
                op = 0;
                break;
        }
    } while (op != 0);

    return 0;
}