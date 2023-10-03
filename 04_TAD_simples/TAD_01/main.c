#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

int main()
{
    tJogo jogo;
    while(1)
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);
        if(!ContinuaJogo())
        {
            break;
        }
    }
    return 0;
}