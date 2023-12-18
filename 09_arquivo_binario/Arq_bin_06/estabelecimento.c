#include "estabelecimento.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estabelecimento
{
    Vector *v;
};

tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento *e = malloc(sizeof(tEstabelecimento));
    e->v = VectorConstruct();
    return e;
}

void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    int i;
    tProduto *p;
    VectorDestroy(estabelecimento->v, DestroiProduto);
    if(estabelecimento!=NULL)
    {
        free(estabelecimento);
    }
}

void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    VectorPushBack(estabelecimento->v, (void*)produto);
}

float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{
    int i;
    float total=0;
    tProduto *p;
    for(i=0 ; i<VectorSize(estabelecimento->v) ; i++)
    {
        p = (tProduto*)VectorGet(estabelecimento->v , i);
        total += GetPrecoProduto(p)*GetQuantidadeVendidaProduto(p);
    }
    return total;
}

void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{
    float a;
    a = GetValorTotalVendidoEstabelecimento(estabelecimento);
    printf("Valor total vendido: R$ %.2f\n", a);
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    int i;
    tProduto *p;
    for(i=0 ; i<VectorSize(estabelecimento->v) ; i++)
    {
        p = (tProduto*)VectorGet(estabelecimento->v , i);
        ImprimeProduto(p);
        printf(";%.2f%%\n", (GetPrecoProduto(p)*GetQuantidadeVendidaProduto(p)/a)*100);
    }
}

void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    int d, i;
    FILE *f;
    tProduto *p;
    char path[200];
    scanf("%s", path);
    f = fopen(path , "rb");
    if(f==NULL)
    {
        printf("DEU RUIM\n");
        exit(1);
    }

    fread(&d, sizeof(int) , 1, f);
    for(i=0 ; i<d ; i++)
    {
        p = LeProduto(f);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }
    fclose(f);
}