#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nintervalos;
    char nome[300];
    scanf("%s", nome);
    Imagem *i = LerImagem(nome);
    scanf("%d", &nintervalos);
    Histograma *h = CalcularHistograma(i, nintervalos);
    MostrarHistograma(h);
    DestruirImagem(i);
    DestruirHistograma(h);
    return 0;
}