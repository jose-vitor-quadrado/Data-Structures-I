#include <stdio.h>
#include <string.h>

#define LIM 30
#define PeI 2
#define PeS 3
#define PeT 1

typedef struct {
    char nome[50];
    float intermediaria;
    float semestral;
    float trabalho;
    float media;
    char status;
} Boletim;

void Cadastrar(Boletim *bol, int *total);
void PesquisarMedia(Boletim *bol, int total);
void MostrarAprovadosEReprovados(Boletim *bol, int total);
int VerificaNome(Boletim *bol, int total, char nome[50]);

int main() {
    int op = 0, total = 0;
    Boletim b[LIM];

    do {
        printf(" 1 - Cadastrar alunos:\n");
        printf(" 2 - Pesquisar media de determinado aluno:\n");
        printf(" 3 - Visualizar aprovados e reprovados:\n");
        printf(" 4 - Sair:\n");
        printf("--> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                Cadastrar(b, &total);
            break;
            case 2:
                PesquisarMedia(b, total);
            break;
            case 3:
                MostrarAprovadosEReprovados(b, total);
            break;
            case 4:
                printf("Saindo...\n");
            break;
            default:
                printf("Numero invalido!\n");
                op = 0;
            break;
        }
    } while (op != 4);

    return 0;
}

void Cadastrar(Boletim *bol, int *total) {
    if (*total >= LIM) {
        printf("Limite de alunos atingido...\n");
        return;
    }

    Boletim *boletim = bol + (*total);

    printf("Digite o nome do Aluno: ");
    scanf(" %[^\n]", boletim->nome);
    printf("Digite a nota da prova intermediaria: ");
    scanf("%f", &boletim->intermediaria);
    printf("Digite a nota da prova semestral: ");
    scanf("%f", &boletim->semestral);
    printf("Digite a nota de trabalho: ");
    scanf("%f", &boletim->trabalho);

    boletim->media = (
            (boletim->intermediaria * PeI) + 
            (boletim->semestral * PeS) + 
            (boletim->trabalho * PeT) 
        ) / (PeI + PeS + PeT);

    boletim->status = (boletim->media >= 7.0) ? 'A' : 'R';

    (*total)++;
}

int VerificaNome(Boletim *bol, int total, char nome[50]) {
    for (int i = 0; i < total; i++) {
        if (strcmp((bol + i)->nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void PesquisarMedia(Boletim *bol, int total) {
    char nome[50];
    printf("Escreva o nome do aluno: ");
    scanf(" %[^\n]", nome);

    int i = VerificaNome(bol, total, nome);

    if (i == -1) {
        printf("Nao existe aluno com este nome!\n");
        return;
    }

    printf("Media de %s: %.2f\n", (bol + i)->nome, (bol + i)->media);
}

void MostrarAprovadosEReprovados(Boletim *bol, int total) {
    printf("Aprovados:\n");
    for (int i = 0; i < total; i++) {
        if ((bol + i)->status == 'A') {
            printf(" %s\n", (bol + i)->nome);
        }
    }

    printf("Reprovados:\n");
    for (int i = 0; i < total; i++) {
        if ((bol + i)->status != 'A') {
            printf(" %s\n", (bol + i)->nome);
        }
    }
}