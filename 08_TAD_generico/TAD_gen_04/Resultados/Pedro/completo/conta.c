#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

struct Conta{
    char nome[100];
    int id;
    float saldo;
};

float GetSaldoConta(tConta *conta)
{
    return conta->saldo;
}

void LeConta(tConta *conta)
{
    char nome[100];
    int id;
    float saldo;
    scanf("%d;%[^;];%f", &id, nome, &saldo);
    nome[strlen(nome)]='\0';
    strcpy(conta->nome, nome);
    conta->id=id;
    conta->saldo=saldo;
}

tConta *CriaConta()
{
    tConta *c = malloc(sizeof(tConta));
    if(c==NULL)
    {
        exit(1);
    }
    c->id=-1;
    c->nome[0]='\0';
    c->saldo=0;
    return c;
}

void DestroiConta(DataType conta)
{
    tConta *c = (tConta*)conta;
    if(c!=NULL)
    {
        free(conta);
    }
}