#include "vetor.h"
#include <stdio.h>
void LeVetor(Vetor *vetor)
{
    scanf("%d", &vetor->tamanhoUtilizado);
    int i=0;
    for(i=0; i<vetor->tamanhoUtilizado ; i++)
    {
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op)
{
    int resultado=vetor->elementos[0], i=0;
    for(i=1; i<vetor->tamanhoUtilizado ; i++)
    {
        resultado=op(resultado, vetor->elementos[i]);
    }
    return resultado;
}