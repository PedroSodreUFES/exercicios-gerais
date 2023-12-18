#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    DataType *vetor;
    int n;
};

Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(Vector));
    v->vetor=NULL;
    v->n=0;
    return v;
}

void VectorPushBack(Vector *v, DataType val)
{
    v->n++;
    v->vetor = realloc(v->vetor, VectorSize(v) * sizeof(DataType));
    v->vetor[VectorSize(v)-1] = val;
}

DataType VectorGet(Vector *v, int i)
{
    return v->vetor[i];
}

int VectorSize(Vector *v)
{
    return v->n;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    int i;
    for(i=0 ; i<VectorSize(v) ; i++)
    {
        destroy(v->vetor[i]);
    }
    if(v->vetor!=NULL)
    {
        free(v->vetor);
    }
    if(v!=NULL)
    {
        free(v);
    }
}

