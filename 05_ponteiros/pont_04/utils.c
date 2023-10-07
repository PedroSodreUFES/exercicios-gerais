#include "utils.h"

void LeNumeros(int *array, int tamanho)
{
    int i=0;
    for(i=0; i<tamanho; i++)scanf("%d", &array[i]);
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    int i=0;
    float soma;
    for(i=0 ; i<tamanho ; i++)
    {
        if(*(array+i) < *menor || i==0)
        {
            *menor = *(array+i);
        } 
        if(*(array+i) > *maior || i==0)
        {
            *maior = *(array+i);
        }
        soma+= *(array+i);
    }
    *media = soma/tamanho;
}