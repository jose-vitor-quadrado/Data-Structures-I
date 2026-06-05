#include <stdio.h>

#define T 10

typedef struct {
    int topo;
    char elem[T];
} Pilha;

void inicia(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p) {
    if (p->topo >= T - 1) {
        printf("Pilha cheia\n");
        return;
    }

    printf("Digite o valor a ser inserido: ");
    char c;
    scanf(" %c", &c);

    p->elem[++p->topo] = c;
}

char pop(Pilha *p, Pilha *b) {
    if (p->topo == -1) {
        printf("Pilha vazia\n");
        return 0;
    }
    (*b) = (*p);
    return p->elem[p->topo--];
}

void desfazer(Pilha *p, Pilha *b) {
    (*p) = (*b);
}

void mostrar(Pilha p) {
    if (p.topo == -1) {
        printf("Pilha vazia\n");
        return;
    }
    printf("\nTexto atual:");
    for (int i = 0; i <= p.topo; i++) {
        printf("%c", p.elem[i]);
    }
    printf("\n");
}

int main() {
    Pilha p, backup;
    inicia(&p);
    inicia(&backup);
    int op = 0;

    do {
        printf("\n======= Editor de texto =======\n");
        printf(" 1 - Inserir elemento:\n");
        printf(" 2 - Remover ultimo caractere:\n");
        printf(" 3 - Desfazer:\n");
        printf(" 4 - Mostrar texto:\n");
        printf(" 0 - Sair:\n");
        printf("--> ");
        scanf(" %d", &op);

        switch (op) {
            case 1:
                push(&p);
            break;
            case 2:
                pop(&p, &backup);
            break;
            case 3:
                desfazer(&p, &backup);
            break;
            case 4:
                mostrar(p);
            break;
            default:
                printf("Saindo...\n");
                op = 9;
            break;
        }
    } while (op != 9);

    return 0;
}