#include "missil.h"
#include "cidade.h"
#include "defesa.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct missil{
    char *nome;
    float x, y, poder;
};

tMissil LeMissil()
{
    float x, y, z;
    scanf("%f %f %f%*c", &x, &y, &z);
    tMissil missil = malloc(sizeof(tMissil));
    if(missil==NULL)
    {
        printf("nao alocou o missil\n");
        exit(1);
    }
    missil->x=x;
    missil->y=y;
    missil->poder=z;
    return missil;
}

void ImprimeMissil(tMissil missil)
{
    int n, i;
    n =strlen(missil->nome);
    printf("%c-", missil->nome[0]);
    for(i=1 ; i<n ; i++)
    {
        printf("%c", missil->nome[i]);
    }
    printf(" %.2f\n", missil->poder);
}

void LiberaMissil(tMissil missil)
{
    if(missil!=NULL)
    {
        free(missil);
    }
}

float GetMissilY(tMissil missil)
{
    return missil->y;
}

float GetMissilX(tMissil missil)
{
    return missil->x;
}

float GetMissilPoder(tMissil missil)
{
    return missil->poder;
}

void ReduzPoder(tMissil missil, float valor)
{
    missil->poder = GetMissilPoder(missil)-valor;
}