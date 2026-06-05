#include <stdio.h>
#include <string.h>

#define LIM 15

typedef struct {
    int numero;
    char nome[50];
    float saldo;
} conta;

int verificarNumero (conta *acc, int total, int numero) {
    int i;
    for (i = 0; i < total; i++) {
        if ((acc + i)->numero == numero) {
            return i;
        }
    }
    return -1;
}

void cadastrar (conta *acc, int *total) {
    if (*total >= LIM) {
        printf("Limite de contas atingido...\n");
        return;
    }

    int num;
    printf("Numero da conta: ");
    scanf("%d", &num);
    if (verificarNumero(acc, *total, num) != -1) {
        printf("Conta ja existente!\n");
        return;
    }

    conta *c = acc + (*total);

    c->numero = num;

    printf("Nome do cliente: ");
    scanf(" %[^\n]", c->nome);

    printf("Saldo: ");
    scanf("%f", &c->saldo);

    (*total)++;
}

void buscarPorNome(conta *acc, int total) {
    int i;
    char nome[50];
    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);

    for (i = 0; i < total; i++) {
        if (strcmp((acc + i)->nome, nome) == 0) {
            printf("Conta: %d | Nome: %s | Saldo: %.2f\n",
                   (acc + i)->numero,
                   (acc + i)->nome,
                   (acc + i)->saldo);
            return;
        }
    }

    printf("Cliente nao encontrado!\n");
}

void saldoNegativo(conta *acc, int total) {
    int enc = 0, i;

    for (i = 0; i < total; i++) {
        if ((acc + i)->saldo < 0) {
            printf("Conta: %d | Nome: %s | Saldo: %.2f\n",
                   (acc + i)->numero,
                   (acc + i)->nome,
                   (acc + i)->saldo);
            enc = 1;
        }
    }

    if (!enc) {
        printf("Nenhuma conta com saldo negativo.\n");
    }
}

void maiorSaldo(conta *acc, int total) {
    if (total == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    
    int i;
    conta *maior = acc;

    for (i = 1; i < total ; i++) {
        if ((acc + i)->saldo > maior->saldo) { 
            maior = acc + i;
        }
    }

    printf("Conta: %d | Nome: %s | Saldo: %.2f\n",
                   maior->numero,
                   maior->nome,
                   maior->saldo);
}

int main() {
    int op = 0, total = 0;
    conta acc[LIM];

    do {
        printf(" 1 - Cadastrar contas:\n");
        printf(" 2 - Buscar cliente por nome:\n");
        printf(" 3 - Mostrar clientes com saldo negativo:\n");
        printf(" 4 - Mostrar conta com o maior saldo:\n");
        printf(" 5 - Sair:\n");
        printf(" ==> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrar(acc, &total);
            break;
            case 2:
                buscarPorNome(acc, total);
            break;
            case 3:
                saldoNegativo(acc, total);
            break;
            case 4:
                maiorSaldo(acc, total);
            break;
            case 5:
                printf("Saindo...\n");
            break;
            default:
                printf("Valor invalido!\n");
                op = 0;
            break;
        }
    } while (op != 5);

    return 0;
}