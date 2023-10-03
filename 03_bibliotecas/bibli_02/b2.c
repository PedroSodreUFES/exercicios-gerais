#include "b2.h"
#include <stdio.h>
void ImprimeMatriz(int linha, int coluna, int mat1[MAX][MAX])
{
    int i=0, j=0; 
        for(i=0 ; i<linha ; i++)
        {
            printf("|");
            for(j=0 ; j<coluna; j++)
            {
                printf("%d", mat1[i][j]);
                if(j!=coluna-1)
                {
                    printf(" ");
                }
            }
            printf("|\n");
        }
        printf("\n");
}
void SomaMatriz(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX])
{
    if(linha1==linha2&&coluna1==coluna2)
    {
        printf("Opcao escolhida: \n");
        int i=0, j=0, mat3[MAX][MAX]; 
        for(i=0 ; i<linha1 ; i++)
        {
            for(j=0 ; j<coluna1; j++)
            {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        ImprimeMatriz(linha1, coluna1, mat3);
    }
    else
    {
        printf("Opcao escolhida: \n");
        printf("Erro: as dimensoes da matriz nao correspondem\n\n");
    }
}

void SubtrairMatrizes(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX])
{
    if(linha1==linha2&&coluna1==coluna2)
    {
        printf("Opcao escolhida: \n");
        int i=0, j=0, mat3[MAX][MAX]; 
        for(i=0 ; i<linha1 ; i++)
        {
            for(j=0 ; j<coluna1; j++)
            {
                mat3[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        ImprimeMatriz(linha1, coluna1, mat3);
    }
    else
    {
        printf("Opcao escolhida: \n");
        printf("Erro: as dimensoes da matriz nao correspondem\n\n");
    } 
}

void MultiplicarMatrizes(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX])
{
    if(coluna1==linha2)
    {
        printf("Opcao escolhida: \n");
        int mat3[MAX][MAX];
        int i=0, j=0, z=0;
        int soma=0;
        for(i=0;i<linha1;i++)
        {
            for(j=0;j<coluna2;j++)
            {
                soma=0;   
                for(z=0;z<coluna1;z++)
                {
                        soma=soma+(mat1[i][z]*mat2[z][j]);
                }
                mat3[i][j]=soma;
            }
        }
        ImprimeMatriz(linha1, coluna2, mat3);
    }
    else
    {
        printf("Opcao escolhida: \n");
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
    }
}

void MultiplicarPorEscalar(int linha, int coluna, int mat[MAX][MAX], int escalar)
{
    printf("Opcao escolhida: \n");
    int i=0, j=0;
    for(i=0 ; i<linha ; i++)
    {
        for(j=0 ; j<coluna ; j++)
        {
            mat[i][j]= mat[i][j]*escalar;
        }
    }
    ImprimeMatriz(linha, coluna, mat);
}

void ViraSuaTransposta(int linha, int coluna, int mat[MAX][MAX])
{
    int i=0, j=0, transposta[MAX][MAX], aux=0;
    for(i=0 ; i<linha ; i++)
    {
        for(j=0 ; j<coluna ; j++)
        {
            transposta[j][i] = mat[i][j];
        }
    }
    ImprimeMatriz(coluna, linha, transposta);
}

