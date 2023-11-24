#include "array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Array{
    int *vet;
    int tamanho;
};

Array *CriarArray()
{
    Array *a = (Array*)malloc(sizeof(Array));
    a->tamanho=0;
    a->vet=NULL;
}

void DestruirArray(Array *array)
{
    if(array->vet!=NULL)
    {
        free(array->vet);
    }
    if(array!=NULL)
    {
        free(array);
    }
}

void LerArray(Array *array)
{
    char letra;
    int n, tamanho=0;
    while(scanf("%d%c", &n, &letra)==2)
    {
        tamanho++;
        array->tamanho=tamanho;
        array->vet = (int*)realloc(array->vet, tamanho*sizeof(int));
        array->vet[tamanho-1] = n;
        if(letra=='.')
        {
            break;
        }
    }
}

void OrdenarArray(Array *array)
{
    int i=0 , j=0;
    for(i=0 ; i<array->tamanho ; i++)
    {
        for(j=0 ; j<array->tamanho ; j++)
        {
            if(j==i)
            {
                continue;
            }
            if(array->vet[i]<array->vet[j])
            {
                int salvavalor = array->vet[i];
                array->vet[i] = array->vet[j];
                array->vet[j] = salvavalor;
            }
        }
    }
}

int BuscaBinariaArray(Array *array, int elementoBuscado)
{
    if(array->vet[array->tamanho/2]==elementoBuscado)
    {
        return array->tamanho/2;
    }
    int i;
    if(array->vet[array->tamanho/2]<elementoBuscado)
    {
        for(i=(array->tamanho/2)+1 ; i<array->tamanho ; i++)
        {
            if(array->vet[i]==elementoBuscado)
            {
                return i;
            }
        }
    }
    else
    {
        for(i=0 ; i<array->tamanho/2 ; i++)
        {
            if(array->vet[i]==elementoBuscado)
            {
                return i;
            }
        }
    }
    return -1;
}