#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    strcpy(pessoa.nome, "\0");
    pessoa.irmao=NULL;
    pessoa.mae=NULL;
    pessoa.pai=NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    scanf("%[^\n]%*c", pessoa->nome);
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int mae, pai, filho, i, j;
    scanf("%d%*c", &i);
    while(i)
    {
        scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);
        if(pai>=0)
        {
            pessoas[filho].pai=pessoas+pai;
        }
        if(mae>=0)
        {
            pessoas[filho].mae=pessoas+mae;
        }
        i--;
    }
    for(i=0; i<numPessoas ; i++)
    {
        for(j=0 ; j<numPessoas ; j++)
        {
            if(j==i)
            {
                continue;
            }
            if(VerificaIrmaoPessoa(pessoas+i, pessoas+j))
            {
                pessoas[i].irmao=&pessoas[j];
            }
        }
    }
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if(pessoa->pai==NULL && pessoa->mae==NULL)
    {
        return 0;
    }
    return 1;
}

void ImprimePessoa(tPessoa *pessoa)
{
    printf("NOME COMPLETO: %s\n", pessoa->nome);
    printf("PAI: ");
    if(pessoa->pai==NULL)
    {
        printf("NAO INFORMADO\n");
    }
    else
    {
        printf("%s\n", pessoa->pai->nome);
    }
    printf("MAE: ");
    if(pessoa->mae==NULL)
    {
        printf("NAO INFORMADO\n");
    }
    else
    {
        printf("%s\n", pessoa->mae->nome);
    }
    printf("IRMAO: ");
    if(pessoa->irmao==NULL)
    {
        printf("NAO INFORMADO\n");
    }
    else
    {
        printf("%s\n", pessoa->irmao->nome);
    }
    printf("\n");
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai)
    {
        return 1;
    }
    return 0;
}