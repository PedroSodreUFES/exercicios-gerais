#include "vetor.h"
#include <stdio.h>

int Soma(int num1, int num2)
{
    return num1+num2;
}

int Produto(int num1, int num2)
{
    return num1*num2;
}


int main()
{
    Vetor vet;
    Operation op;
    LeVetor(&vet);
    int resultado;
    op = Soma;
    resultado = AplicarOperacaoVetor(&vet, op);
    printf("Soma: %d\n", resultado);
    op = Produto;
    resultado = AplicarOperacaoVetor(&vet, op);
    printf("Produto: %d\n", resultado);
}