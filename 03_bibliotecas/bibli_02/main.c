#include <stdio.h>
#include "b2.h"

int main()
{
    int linha1, coluna1, linha2, coluna2, i=0, j=0, mat1[MAX][MAX], mat2[MAX][MAX], opcao=0, aux=0;
    scanf("%d %d", &linha1, &coluna1);
    for(i=0 ; i<linha1 ; i++)
    {
        for(j=0 ; j<coluna1 ; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    scanf("%d %d", &linha2, &coluna2);
    for(i=0 ; i<linha2 ; i++)
    {
        for(j=0 ; j<coluna2 ; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    while(1)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        scanf("%d", &opcao);
        if(opcao==1)
        {
            SomaMatriz(linha1, coluna1, mat1, linha2, coluna2, mat2);
        }
        else if(opcao==2)
        {
            SubtrairMatrizes(linha1, coluna1, mat1, linha2, coluna2, mat2);
        }
        else if(opcao==3)
        {
            MultiplicarMatrizes(linha1, coluna1, mat1, linha2, coluna2, mat2);
        }
        else if(opcao==4)
        {
            scanf("%d %d", &opcao, &aux);
            if(aux==1)
            {
                MultiplicarPorEscalar(linha1, coluna1, mat1, opcao);
            }
            else if(aux==2)
            {
                MultiplicarPorEscalar(linha2, coluna2, mat2, opcao);
            }  
        }
        else if(opcao==5)
        {
            printf("Opcao escolhida: \n");
            ViraSuaTransposta(linha1 , coluna1, mat1);
            ViraSuaTransposta(linha2 , coluna2, mat2);
        }
        else
        {
            printf("Opcao escolhida: \n");
            break;
        }
    }
    return 0;
}