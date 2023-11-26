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
    int size;
    if(type == INT)
    {
        size = sizeof(int);
        vetor->vet = malloc(numElem * size);
    }
    else if(type == FLOAT)
    {
        size = sizeof(float);
        vetor->vet = malloc(numElem * size);
    }
    return vetor;
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
    printf("\nDigite o vetor:\n");
    if(gen->tipo==FLOAT)
    {
        int i;
        float numero;
        for(i=0 ; i<gen->tamanho ; i++)
        {
            scanf("%f", &numero);
            memcpy(gen->vet+ (i*sizeof(float)), &numero , sizeof(float));
        }
    }
    else if(gen->tipo==INT)
    {
        int i, v;
        for(i=0 ; i<gen->tamanho ; i++)
        {
            scanf("%d", &v);
            memcpy(gen->vet + (i*sizeof(int)), &v , sizeof(int));
        }
    }
}

void ImprimeGenerico(tGeneric* gen)
{
    int i;
    for(i=0 ; i<gen->tamanho ; i++)
    {
        if(gen->tipo==FLOAT)
        {
            float numero;
            memcpy(&numero, gen->vet+(i*sizeof(float)) , sizeof(float));
            printf("%.2f", numero);
        }
        else if(gen->tipo==INT)
        {
            int numero;
            memcpy(&numero, gen->vet+(i*sizeof(int)) , sizeof(int));
            printf("%d", numero);
        }
        if(i != gen->tamanho-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
