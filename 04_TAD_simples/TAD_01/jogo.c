#include "jogo.h"
#include "jogador.h"
#include <stdio.h>

int ContinuaJogo()
{
    char letra;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]%c", &letra);
    if(letra=='s')
    {
        return 1;
    } 
    else if(letra =='n')
    {
        return 0;
    }
}

tJogo CriaJogo()
{
    tJogo jogo;
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    int venceu=0;
    while(1)
    {
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro))
        {
            venceu=1;
            break;
        }
        if(AcabouJogo(jogo))
        {
            break;
        }
        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        {
            venceu=2;
            break;
        }
    }
    if(venceu == 0)
    {
        printf("Sem vencedor!\n");
    }
    else if(venceu == 1)
    {
        printf("JOGADOR 1 Venceu!\n");
    }
    else
    {
        printf("JOGADOR 2 Venceu!\n");
    }
}

int AcabouJogo(tJogo jogo)
{
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}