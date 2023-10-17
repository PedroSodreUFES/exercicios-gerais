#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int **CriaMatriz(int linhas, int colunas)
{
    int **mat, i;
    mat = malloc (linhas * sizeof (int*)) ;
    for (i=0; i < linhas; i++)
    {
        mat[i] = malloc (colunas * sizeof (int)) ;   
    }
    return mat;
}
void LiberaMatriz(int **matriz, int linhas)
{
    int i;
    for(i=0 ; i<linhas ; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas)
{
    int i=0, j=0;
    for(i=0 ; i<linhas ; i++)
    {
        for(j=0 ; j<colunas ; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    int **t, i, j;
    t = CriaMatriz(colunas, linhas);
    for(i=0 ; i<linhas ; i++)
    {
        for(j=0 ; j<colunas ; j++)
        {
            t[j][i]=matriz[i][j];
        }
    }
    for(i=0 ; i<colunas ; i++)
    {
        for(j=0 ; j<linhas ; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    LiberaMatriz(t, colunas);
}