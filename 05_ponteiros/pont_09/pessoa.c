#include "pessoa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tPessoa CriaPessoa()
{   
    tPessoa pessoa;
    strcpy(pessoa.nome, "\0");
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    scanf("%[^\n]%*c", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if(pessoa->pai==NULL && pessoa->mae==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
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
    printf("\n");
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int mae, pai, filho;
    scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);
    if(pai>=0)
    {
        pessoas[filho].pai=pessoas+pai;
    }
    if(mae>=0)
    {
        pessoas[filho].mae=pessoas+mae;
    }
    if(VerificaSeTemPaisPessoa(&pessoas[filho]))
    {
        ImprimePessoa(&pessoas[filho]);
    }
}