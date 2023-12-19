#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tHistograma
{
    int nintervalos, tamanhointervalo, *numerosporintervalo;
};

void DestruirHistograma(Histograma *histograma)
{
    if(histograma->numerosporintervalo!=NULL)
    {
        free(histograma->numerosporintervalo);
    }
    if(histograma!=NULL)
    {
        free(histograma);
    }
}

void MostrarHistograma(Histograma *histograma)
{
    int i;
    int soma=0;
    for(i=0 ; i<histograma->nintervalos ; i++)
    {
        printf("[%d, %d): %d\n", soma , soma+histograma->tamanhointervalo , histograma->numerosporintervalo[i]);
        soma+= histograma->tamanhointervalo;
    }
}

Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma *h = malloc(sizeof(Histograma));
    h->numerosporintervalo=NULL;
    int tamanhointervalo, i, j=0, z=0, soma=0;
    float f;
    int k;
    tamanhointervalo = 256/nIntervalos;
    if(256%nIntervalos!=0)
    {
        tamanhointervalo++;
    }
    h->nintervalos=nIntervalos;
    h->tamanhointervalo=tamanhointervalo;
    h->numerosporintervalo = malloc(nIntervalos *sizeof(int));

    /*
    ....................
    FEZ DE MANEIRA BURRA
    ....................
    */
    int min=0, max=tamanhointervalo;
    if(ObterTipoImagem(img)==FLOAT)
    {
        float *vetf = (float*)ObterDadosImagem(img);
        for(i=0 ; i<nIntervalos ; i++)
        {
            soma=0;
            for(j =0 ; j<ObterLarguraImagem(img)*ObterAlturaImagem(img) ; j++)
            {
                f = vetf[j]*255;
                k = (int)f;
                if(k>=min && k<max)
                {
                    soma++;
                }
            }
            h->numerosporintervalo[i]=soma;
            min+=tamanhointervalo;
            max+=tamanhointervalo;
        }
    }
    else
    {
        int *veti = (int*)ObterDadosImagem(img);
        for(i=0 ; i<nIntervalos ; i++)
        {
            soma=0;
            for(j =0 ; j<ObterLarguraImagem(img)*ObterAlturaImagem(img) ; j++)
            {
                if(veti[j]>=min && veti[j]<max)
                {
                    soma++;
                }
            }
            h->numerosporintervalo[i]=soma;
            min+=tamanhointervalo;
            max+=tamanhointervalo;
        }
    }
    return h;
}