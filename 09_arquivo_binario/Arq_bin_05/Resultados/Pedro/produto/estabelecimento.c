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

void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");
    int i, a=0;
    tProduto *p;
    for(i=0 ; i<VectorSize(estabelecimento->v) ; i++)
    {
        p = (tProduto*)VectorGet(estabelecimento->v , i);
        if(!TemEstoqueProduto(p))
        {
            a=1;
            ImprimeProduto(p);
        }
    }
    if(a==0)
    {
        printf("Nao ha produtos em falta!\n");
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