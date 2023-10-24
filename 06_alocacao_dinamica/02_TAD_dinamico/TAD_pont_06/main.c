#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main()
{
    int l1, c1;
    scanf("%d %d", &l1, &c1);
    tMatrix *m1 = MatrixCreate(l1, c1);
    MatrixRead(m1);
    int l2, c2;
    scanf("%d %d", &l2, &c2);
    tMatrix *m2 = MatrixCreate(l2, c2);
    MatrixRead(m2);
    int n;
    while(n!=6)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        scanf("%d", &n);
        printf("Opcao escolhida:\n");
        if(n==1)
        {
            if(PossibleMatrixSum(m1, m2))
            {
                MatrixAdd(m1, m2);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(n==2)
        {
            if(PossibleMatrixSub(m1, m2))
            {
                MatrixSub(m1, m2);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(n==3)
        {
            if(PossibleMatrixMultiply(m1, m2))
            {
                MatrixMultiply(m1, m2);
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        else if(n==4)
        {
            int escalar;
            scanf("%d", &escalar);
            scanf("%d", &n);
            if(n==1)
            {
                m1 = MatrixMultiplyByScalar(m1, escalar);
            }
            else
            {
                m2 = MatrixMultiplyByScalar(m2, escalar);
            }
        }
        else if(n==5)
        {
            m1 = TransposeMatrix(m1);
            m2 = TransposeMatrix(m2);
        }
        else if(n==6)
        {
            break;
        }
        else
        {
            printf("Opcao Invalida\n");
        }
    }
    MatrixFree(m1);
    MatrixFree(m2);
    return 0;
}