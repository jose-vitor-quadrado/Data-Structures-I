#include <stdio.h>
#include <string.h>

#define SIZE 20

typedef struct {
    char elements[SIZE];
    int top;
} Stack;

void start(Stack *s) {
    s->top = -1;
}

int empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top >= SIZE) {
        printf("\n Pilha cheia! \n\n");
        return;
    }
    s->elements[++s->top] = c;
}

char pop(Stack *s) {
    return s->elements[s->top--];
}

char top(Stack *s) {
    return s->elements[s->top];
}

int main() {
    Stack s;
    int op = 0;
    start(&s);

    system("cls");

    do {
        printf("\n====== PILHA ======\n");
        printf(" 1 - Adicionar elemento:\n");
        printf(" 2 - Tirar elemento da pilha:\n");
        printf(" 3 - Mostrar elemento do topo:\n");
        printf(" 4 - Sair:\n");
        printf("--> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nDigite o valor a ser adicionado a pilha: ");
                char c;
                scanf(" %c", &c);
                push(&s, c);
            break;
            case 2:
                if (empty(&s)) {
                    printf("\n Pilha vazia! \n\n");
                    continue;
                }
                pop(&s);
            break;
            case 3:
                if (empty(&s)) {
                     printf("\n Pilha vazia! \n\n");
                     continue;
                }
                printf(" %c \n", top(&s));
            break;
            case 4:
                printf("\nSaindo...\n");
            break;
            default:
                printf("\nOpcao invalida!\n");
            break;
        }

        system("cls");
    } while (op != 4);

    return 0;
}