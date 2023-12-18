#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

struct Produto
{
    int codigo, qntdvendida;
    char nome[50];
    float preco;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida)
{
    tProduto *p = malloc(sizeof(tProduto));
    strcpy(p->nome, nome);
    p->codigo = codigo;
    p->preco = preco;
    p->qntdvendida = quantidadeVendida;
    return p;
}

void DestroiProduto(tProduto *produto)
{
    if(produto!=NULL)
    {
        free(produto);
    }
}

tProduto *LeProduto(FILE *arquivo)
{
    int codigo, quantidadevendida;
    char nome[50];
    float preco;
    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), 50, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&quantidadevendida, sizeof(int), 1, arquivo);
    tProduto *p = CriaProduto(codigo, nome, preco, quantidadevendida);
    return p;
}

void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->qntdvendida);
}

int GetQuantidadeVendidaProduto(tProduto *produto)
{
    return produto->qntdvendida;
}

float GetPrecoProduto(tProduto *produto)
{
    return produto->preco;
}