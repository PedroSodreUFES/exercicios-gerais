#include "jogada.h"
#include <stdio.h>

tJogada LeJogada()
{
    tJogada jogada;
    printf("Digite uma posicao (x e y):\n");
    jogada.x = ObtemJogadaX(jogada);
    jogada.y = ObtemJogadaY(jogada);
    return jogada;
}

int ObtemJogadaX(tJogada jogada)
{
    scanf("%d", &jogada.x);
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada)
{
    scanf("%d", &jogada.y);
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{
    if(jogada.sucesso==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}