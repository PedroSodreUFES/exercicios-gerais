#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam)
{
    int i=0;
    for(i=0 ; i<tam ; i++)
    {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam)
{
    int i=0;
    for(i=0 ; i<tam ; i++)
    {
        printf("%d", n[i]);
        printf(" ");
    }
    printf("\n");
}

void OrdeneCrescente(int * vet, int tam)
{
    int i=0, j=0;
    for(i=0 ; i<tam ; i++)
    {
        TrocaSeAcharMenor(vet, tam, vet+i);    
    }    
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar)
{
    int *i;
    for(i=vet ; i < vet + tam ; i++)
    {
        if(*paraTrocar < *i)
        {
            int aux = *i;
            *i = *paraTrocar;
            *paraTrocar = aux;
        }
    }
}