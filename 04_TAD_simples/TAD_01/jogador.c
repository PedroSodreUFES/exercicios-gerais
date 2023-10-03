#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int i=0, j=0, cont=0, peca;
    if(jogador.id==ID_JOGADOR_1)
    {
        peca='X';
    }
    else
    {
        peca='0';
    }
    for(i=0; i<TAM_TABULEIRO; i++)
    {
        for(j=0; j<TAM_TABULEIRO ; j++)
        {
            if(tabuleiro.posicoes[i][j]==peca)
            {
                cont++;
            }
        }
        if(cont==3)
        {
            return 1;
        }
        else
        {
            cont=0;
        }
    }
    for(i=0; i<TAM_TABULEIRO; i++)
    {
        for(j=0; j<TAM_TABULEIRO ; j++)
        {
            if(tabuleiro.posicoes[j][i]==peca)
            {
                cont++;
            }
        }
        if(cont==3)
        {
            return 1;
        }
        else
        {
            cont=0;
        }
    }
    for(i=0; i<TAM_TABULEIRO; i++)
    {
        if(tabuleiro.posicoes[i][i]==peca)
        {
                cont++;
        }
    }
    if(cont==3)
        {
            return 1;
        }
        else
        {
            cont=0;
        }
    for(i=0; i<TAM_TABULEIRO; i++)
    {
        if(tabuleiro.posicoes[i][2-i]==peca)
        {
            cont++;
        }
    }
    if(cont==3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;
    while(1)
    {
        if(jogador.id == ID_JOGADOR_1)
        {
            printf("Jogador 1\n");
        }
        else
        {
            printf("Jogador 2\n");
        }
        jogada = LeJogada();
        if(!EhPosicaoValidaTabuleiro(jogada.x, jogada.y))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada.x, jogada.y);
            continue;
        }
        if(!EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y))
        {
            if(jogador.id==ID_JOGADOR_1)
            {
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, jogada.x, jogada.y, tabuleiro.peca1))
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
                }
                else
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
                }
                continue;
            }
            else
            {
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, jogada.x, jogada.y, tabuleiro.peca2))
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
                }
                else
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
                }
                continue;
            }
        }
        if(jogador.id==ID_JOGADOR_1)
        {
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca1, jogada.x, jogada.y);
        }
        else
        {
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca2, jogada.x, jogada.y);
        }
        return tabuleiro;
    }
}