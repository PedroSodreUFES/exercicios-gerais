#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int *CriaVetor(int tamanho)
{
    int *v = (int *) malloc(tamanho * sizeof(int));
    return v;
}

void LeVetor(int *vetor, int tamanho)
{
    int i=0;
    for(i=0 ; i<tamanho ; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho)
{
    int i=0;
    float soma=0;
    for(i=0 ; i<tamanho ; i++)
    {
        soma+=vetor[i];
    }
    return soma/tamanho;
}

void LiberaVetor(int *vetor)
{
    free(vetor);
}