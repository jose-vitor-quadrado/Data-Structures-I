#include <stdio.h>

#define LIM 50

typedef struct {
    int ano;
    char nome[50];
    float altura;
} pessoa;

void cadastrar(pessoa *p, int *total) {
    if (*total >= LIM) {
        printf("Limite atingido...\n");
        return;
    }

    pessoa *pes = p + (*total);

    printf("Ano de nascimento: ");
    scanf("%d", &pes->ano);
    printf("Digite o nome: ");
    scanf(" %[^\n]", pes->nome);
    printf("Digite a altura: ");
    scanf("%f", &pes->altura);

    (*total)++;
}

void listar(pessoa *p, int total) {
    int i;

    for (i = 0; i < total; i++) {
        printf("Nome: %s\nAltura: %.2f\n", (p + i)->nome, (p + i)->altura);
    }
}

void listarPosAno(pessoa *p, int total) {
    int i, ano;

    printf("Digitar ano: ");
    scanf("%d", &ano);

    for (i = 0; i < total; i++) {
        if ((p + i)->ano > ano) {
            printf("Nome: %s\n", (p + i)->nome);
        }
    }
}

int main() {
    int op = 0, total = 0;
    pessoa p[LIM];

    do {
        printf(" 1 - Registrar pessoa:\n");
        printf(" 2 - Listar nomes e alturas:\n");
        printf(" 3 - Listar nomes de quem nasceu apos ano escolhido:\n");
        printf(" 4 - Sair:\n");
        printf(" ==> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrar(p, &total);
            break;
            case 2:
                listar(p, total);
            break;
            case 3:
                listarPosAno(p, total);
            break;
            case 4:
                printf("Saindo...\n");
            break;
            default:
                printf("Valor invalido!\n");
                op = 0;
            break;
        }
    } while (op != 4);

    return 0;
}