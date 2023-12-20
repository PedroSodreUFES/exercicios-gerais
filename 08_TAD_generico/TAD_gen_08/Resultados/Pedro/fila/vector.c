#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    DataType *p;
    int size;
};



Vector *VectorConstruct()
{
    Vector *v = (Vector*)malloc(sizeof(Vector));
    v->p = NULL;
    v->size=0;
    return v;
}

void VectorPushBack(Vector *v, DataType val)
{
    v->size++;
    v->p = realloc(v->p, v->size*sizeof(DataType));
    v->p[v->size-1] = val;
}

DataType VectorPopFront(Vector *v)
{
    DataType d = v->p[0];
    int i;
    for(i=0 ; i<VectorSize(v)-1 ; i++)
    {
        v->p[i] = v->p[i+1];
    }
    v->size--;
    return d; 
}

DataType VectorGet(Vector *v, int i)
{
    return v->p[i];
}

int VectorSize(Vector *v)
{
    return v->size;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    int i;
    for(i=0 ; i<VectorSize(v) ; i++)
    {
        destroy(v->p[i]);
    }
    if(v->p!=NULL)
    {
        free(v->p);
    }
    if(v!=NULL)
    {
        free(v);
    }
}