#include <stdio.h>

#define T 10

typedef struct {
    int inicio;
    int fim;
    int documentos[T];
} Fila;

void iniciar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

void adicionar(Fila *f) {
    if (f->fim >= T-1) {
        printf("Fila cheia\n");
    }

    int documento;
    printf("Codigo do documento a ser enviado: ");
    scanf(" %d", &documento);

    f->fim++;
    f->documentos[f->fim] = documento;

    printf("Documento %d enviado.\n", documento);
}

int retirar(Fila *f) {
    if (f->fim < f->inicio) {
        printf("Fila vazia.\n");
        return -1;
    }

    int doc = f->documentos[f->inicio];
    f->inicio++;
    return doc;
}

void mostrar(Fila f) {
    printf("Fila de impressao:");
    for (int i = f.inicio; i <= f.fim; i++) {
        printf(" %d", f.documentos[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    int op = 0;

    iniciar(&f);

    do {
        printf("\n======== Gerenciar documentos ========\n");
        printf(" 1 - Enviar documento:\n");
        printf(" 2 - Imprimir documento:\n");
        printf(" 3 - Fila de impressao:\n");
        printf(" 0 - Sair:\n");
        printf("--> ");
        scanf(" %d", &op);

        switch (op) {
            case 1:
                adicionar(&f);
            break;
            case 2:
                printf("Imprimindo documento %d.\n", retirar(&f));
            break;
            case 3:
                mostrar(f);
            break;
            default:
                printf("Saindo...\n");
                op = 9;
            break;
        }
    } while (op != 9);

    return 0;
}