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