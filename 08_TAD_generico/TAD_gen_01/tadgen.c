#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct generic{
    int tamanho;
    void *vet;
    Type tipo;
};

tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric *vetor = (tGeneric*)malloc(sizeof(tGeneric));
    vetor->tamanho=numElem;
    vetor->tipo=type;
    vetor->vet=NULL;
}

void DestroiGenerico(tGeneric* gen)
{
    if(gen->vet!=NULL)
    {
        free(gen->vet);
    }
    if(gen!=NULL)
    {
        free(gen);
    }
}

void LeGenerico(tGeneric* gen)
{
    if(gen->tipo==FLOAT)
    {
        gen->vet = (void*)malloc(gen->tamanho * sizeof(void));
        int i;
        float v;
        for(i=0 ; i<gen->tamanho ; i++)
        {
            scanf("%f", &v);
            gen->vet[i]=(void)v;
        }
    }
    else if(gen->tipo==INT)
    {
        gen->vet = (void*)malloc(gen->tamanho * sizeof(void));
        int i, v;
        for(i=0 ; i<gen->tamanho ; i++)
        {
            scanf("%d", &v);
            gen->vet[i]=v;
        }
    }
}

void ImprimeGenerico(tGeneric* gen)
{
    int i;
    for(i=0 ; i<gen->tamanho ; i++)
    {
        printf("");
        if(i!=gen->tamanho - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}