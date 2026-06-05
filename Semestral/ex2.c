#include <stdio.h>

#define T 20

typedef struct {
    int topo;
    int elementos[T];
} Pilha;

void inicia(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p) {
    if (p->topo >= T - 1) {
        printf("Pilha cheia\n");
        return;
    }

    int n;
    printf("Digite o valor a ser inserido: ");
    scanf(" %d", &n);
    p->elementos[++p->topo] = n;
}

void criarPilha(Pilha *p) {
    char op = 's';
    do {
        if (op != 's' && op != 'n') {  
            printf("Valor invalido!\n");
            continue;
        }
        push(p);
        printf("Deseja adicionar mais valores?(s/n) ");
        scanf(" %c", &op);
    } while (op != 'n');
}

void compara(Pilha p1, Pilha p2) {
    if (p1.topo == p2.topo) printf("Sao do mesmo tamanho!\n");
    else if (p1.topo > p2.topo) printf("A pilha 1 eh maior que a pilha 2!\n");
    else printf("A pilha 2 eh maior que a pilha 1!\n");
}

int main() {
    Pilha p1, p2;
    inicia(&p1);
    inicia(&p2);

    printf("\nPILHA 1:\n");
    criarPilha(&p1);

    printf("Indo para a proxima pilha...\n");
    
    printf("\nPILHA 2:\n");
    criarPilha(&p2);
    
    compara(p1, p2);

    return 0;
}