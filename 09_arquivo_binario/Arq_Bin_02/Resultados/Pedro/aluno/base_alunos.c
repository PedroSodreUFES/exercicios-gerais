#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"

struct BaseAlunos
{
    void **lista;
    int nalunos;
};

tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *base = malloc(sizeof(tBaseAlunos));
    base->lista = NULL;
    base->nalunos=0;
}

void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    int i;
    for(i=0 ; i<baseAlunos->nalunos ; i++)
    {
        DestruirAluno(baseAlunos->lista[i]);
    }
    if(baseAlunos->lista!=NULL)
    {
        free(baseAlunos->lista);
    }
    if(baseAlunos!=NULL)
    {
        free(baseAlunos);
    }
}

void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    FILE *f;
    tAluno *a;
    f = fopen(nomeArquivo, "rb");
    if(f==NULL)
    {
        printf("file nao abriu\n");
        exit(1);
    }
    int n, i;
    fread(&n, sizeof(int), 1, f);
    baseAlunos->nalunos = n;
    baseAlunos->lista = realloc(baseAlunos->lista, n*sizeof(void*));
    for(i=0 ; i<n ; i++)
    {
        a = LeAluno(f);
        baseAlunos->lista[i] = (void*)a;
    }
    fclose(f);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    int i;
    tAluno *a;
    float media =0;
    for(i=0 ; i<baseAlunos->nalunos ; i++)
    {
        a = (tAluno*)baseAlunos->lista[i];
        media += GetCoeficienteRendimentoAluno(a);
    }
    return media/baseAlunos->nalunos;
}