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

Imagem *LerImagem(const char *caminho)
{
    FILE *f = fopen(caminho, "rb");
    if(f==NULL)
    {
        printf("file nao abriu\n");
        exit(1);
    }
    int linhas, colunas, tipo, i, valori;
    float valorl;
    fread(&linhas, sizeof(int), 1, f);
    fread(&colunas, sizeof(int), 1, f);
    fread(&tipo, sizeof(int), 1, f);
    Imagem *img = malloc(sizeof(Imagem));
    img->lint = NULL;
    img->lfloat = NULL;
    img->linhas = linhas;
    img->colunas=colunas;
    img->tipodeimagem = tipo;
    if(tipo==FLOAT)
    {
        img->lfloat = malloc(linhas*colunas*sizeof(float));
    }
    else
    {
        img->lint = malloc(linhas*colunas*sizeof(int));
    }
    for(i=0 ; i<linhas*colunas ; i++)
    {
        if(tipo==FLOAT)
        {
            fread(&valorl, sizeof(float), 1, f);
            img->lfloat[i] = valorl;
        }
        else
        {
            fread(&valori, sizeof(int), 1, f);
            img->lint[i] = valori;
        }
    }
    fclose(f);
    return img;
}

int ObterAlturaImagem(Imagem *img)
{
    return img->linhas;
}

int ObterLarguraImagem(Imagem *img)
{
    return img->colunas;
}

Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipodeimagem;
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

void *ObterDadosImagem(Imagem *img)
{
    if(img->tipodeimagem==FLOAT)
    {
        return img->lfloat;
    }
    return img->lint;
}
