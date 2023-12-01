#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    DataType *vet;
    int tamanho;
};

Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(Vector));
    v->vet=NULL;
    v->tamanho=0;
    return v;
}

void VectorPushBack(Vector *v, DataType val)
{
    v->tamanho++;
    v->vet = (DataType*)realloc(v->vet, v->tamanho * sizeof(DataType));
    v->vet[v->tamanho-1]=val;
}

DataType VectorGet(Vector *v, int i)
{
    return v->vet[i];
}

int VectorSize(Vector *v)
{
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    int i;
    for(i=0 ; i<VectorSize(v) ; i++)
    {
        destroy(v->vet[i]);
    }
    free(v->vet);
    free(v);
}