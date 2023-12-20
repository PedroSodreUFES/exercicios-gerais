#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int d;
    scanf("%d", &d);
    Imagem *i = LerImagem();
    Histograma *h = CalcularHistograma(i, d);
    MostrarHistograma(h);
    DestruirImagem(i);
    DestruirHistograma(h);
    return 0;
}