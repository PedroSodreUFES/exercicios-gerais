#include "tabuleiro.h"
#include <stdio.h>

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    int i=0, j=0;
    for(i=0; i<TAM_TABULEIRO ; i++)
    {
        for(j=0 ; j<TAM_TABULEIRO ; j++)
        {
            if(tabuleiro.posicoes[i][j]=='-')
            {
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    char letra;
    if(peca==PECA_1)
    {
        letra='X';
    }
    else
    {
        letra='0';
    }
    if(tabuleiro.posicoes[y][x]==letra)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if(tabuleiro.posicoes[y][x]=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    int i=0, j=0;
    for( i=0 ; i<TAM_TABULEIRO ; i++)
    {
        printf("	");
        for( j=0 ; j<TAM_TABULEIRO ; j++)
        {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if(x>=0 && x<TAM_TABULEIRO && y>=0 && y<TAM_TABULEIRO)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    printf("Jogada [%d,%d]!\n", x, y);
    if(peca==PECA_1)
    {
        tabuleiro.posicoes[y][x]='X';
    }
    if(peca==PECA_2)
    {
        tabuleiro.posicoes[y][x]='0';
    }
    return tabuleiro;
}

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;
    int i=0, j=0;
    for(i=0; i<TAM_TABULEIRO ; i++)
    {
        for(j=0 ; j<TAM_TABULEIRO ; j++)
        {
            tabuleiro.posicoes[i][j]='-';
        }
    }
    tabuleiro.peca1 = PECA_1;
    tabuleiro.peca2 = PECA_2;
    tabuleiro.pecaVazio = '-';
    return tabuleiro;
}