#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tImagem
{
    int linhas, colunas;
    Tipo tipodeimagem;
    int *lint;
    float *lfloat;
};

int ObterAltura(Imagem *img)
{
    return img->linhas;
}

int ObterLargura(Imagem *img)
{
    return img->colunas;
}

Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipodeimagem;
}

void *ObterDadosImagem(Imagem *img)
{
    if(img->tipodeimagem==FLOAT)
    {
        return img->lfloat;
    }
    return img->lint;
}

void DestruirImagem(Imagem *img)
{
    if(img->lint!=NULL)
    {
        free(img->lint);
    }
    if(img->lfloat!=NULL)
    {
        free(img->lfloat);
    }
    if(img!=NULL)
    {
        free(img);
    }
}

Imagem *LerImagem()
{
    int altura, largura, tipo, j;
    scanf("%d %d %d", &altura, &largura, &tipo);
    Imagem *i = CriarImagem(altura, largura, tipo);
    if(i->tipodeimagem == FLOAT)
    {
        float valorl;
        for(j=0 ; j<altura*largura ; j++)
        {
            scanf("%f", &valorl);
            i->lfloat[j] = valorl;
        }
    }
    else
    {
        int valori;
        for(j=0 ; j<altura*largura ; j++)
        {
            scanf("%d", &valori);
            i->lint[j] = valori;
        }
    }
    return i;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem *i = malloc(sizeof(Imagem));
    i->linhas = altura;
    i->colunas = largura;
    i->tipodeimagem = tipo;
    i->lfloat = NULL;
    i->lint = NULL;
    if(tipo==FLOAT)
    {
        i->lfloat = malloc(altura * largura * sizeof(float));
    }
    else
    {
        i->lint = malloc(altura * largura * sizeof(int));
    }
    return i;
}

void ImprimirImagem(Imagem *img)
{
    return;
}