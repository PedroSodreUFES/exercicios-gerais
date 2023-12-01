#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    data_type *vet;
    int tamanho;
};

Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(Vector));
    v->vet=NULL;
    v->tamanho=0;
    return v;
}

void VectorPushBack(Vector *v, data_type val)
{
    v->tamanho++;
    v->vet = (data_type*)realloc(v->vet, v->tamanho * sizeof(data_type));
    v->vet[v->tamanho-1]=val;
}

data_type VectorGet(Vector *v, int i)
{
    return v->vet[i];
}

int VectorSize(Vector *v)
{
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    int i;
    for(i=0 ; i<VectorSize(v) ; i++)
    {
        destroy(v->vet[i]);
    }
    free(v->vet);
    free(v);
}