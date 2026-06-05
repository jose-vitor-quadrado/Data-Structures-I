#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa p1;
    Pessoa *ptrP;

    strcpy(p1.nome, "Carlos");
    
    p1.idade = 30;
    p1.altura = 1.75;

    ptrP = &p1;

    ptrP->idade++;

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p1.nome, p1.idade, p1.altura);

    return 0;
}