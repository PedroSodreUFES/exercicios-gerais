#include "utils.h"
#include <stdio.h>

int main()
{
    int linhas, colunas, **p, **t;
    scanf("%d %d", &linhas, &colunas);
    p = CriaMatriz(linhas, colunas);
    LeMatriz(p , linhas, colunas);
    ImprimeMatrizTransposta(p, linhas, colunas);
    LiberaMatriz(p , linhas);
    return 0;
}