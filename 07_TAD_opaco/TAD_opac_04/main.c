#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nalunos, i, j;
    scanf("%d%*c", &nalunos);
    tAluno **lista = (tAluno**)malloc(nalunos * sizeof(tAluno*));
    if(lista==NULL)
    {
        printf("NAO ALOCOU NADA\n");
        exit(1);
    }
    for(i=0 ; i<nalunos ; i++)
    {
        lista[i]=CriaAluno();
        LeAluno(lista[i]);
    }
    for(i=0 ; i<nalunos ; i++)
    {
        for(j=0 ; j<nalunos ; j++)
        {
            if(j==i)
            {
                continue;
            }
            if(ComparaMatricula(lista[i], lista[j])==-1)
            {
                tAluno *salvavalor;
                salvavalor = lista[i];
                lista[i] = lista[j];
                lista[j] = salvavalor;
            }
        }
    }
    for(i=0 ; i<nalunos ; i++)
    {
        if(VerificaAprovacao(lista[i]))
        {
            ImprimeAluno(lista[i]);
        }
    }
    for(i=0 ; i<nalunos ; i++)
    {
        ApagaAluno(lista[i]);
    }
    if(lista!=NULL)
    {
        free(lista);
    }
    return 0;
}