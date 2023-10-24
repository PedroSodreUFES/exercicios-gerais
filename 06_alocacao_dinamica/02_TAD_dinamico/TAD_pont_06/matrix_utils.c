#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

tMatrix* MatrixCreate(int rows, int cols)
{
    tMatrix *mat;
    mat = (tMatrix *) malloc(sizeof(tMatrix));
    int i=0, j=0;
    mat->rows=rows;
    mat->cols=cols;
    mat->data = (int *) malloc(rows * sizeof(int));
    for(i=0  ; i<rows ; i++)
    {
        mat->data[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

void MatrixFree(tMatrix* matrix)
{
    int i, j;
    for(i=0 ; i<matrix->rows ; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void MatrixRead(tMatrix* matrix)
{
    int i, j;
    for(i=0; i<matrix->rows ; i++)
    {
        for(j=0 ; j<matrix->cols ; j++)
        {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void MatrixPrint(tMatrix* matrix)
{
    int i, j;
    for(i=0; i<matrix->rows ; i++)
    {   
        printf("|");
        for(j=0 ; j<matrix->cols ; j++)
        {
            printf("%d", matrix->data[i][j]);
            if(j!=matrix->cols-1)
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2)
{
    if(matrix1->cols==matrix2->cols && matrix1->rows==matrix2->rows)
    {
        return 1;
    }
    return 0;
}

int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2)
{
    if(matrix1->cols==matrix2->cols && matrix1->rows==matrix2->rows)
    {
        return 1;
    }
    return 0;
}

int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2)
{
    if(matrix1->cols==matrix2->rows)
    {
        return 1;
    }
    return 0;
}

tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2)
{
    int i, j;
    tMatrix *m = MatrixCreate(matrix1->rows, matrix1->cols);
    for(i=0; i<matrix1->rows ; i++)
    {
        for(j=0 ; j<matrix1->cols ; j++)
        {
            m->data[i][j]= matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    MatrixPrint(m);
    MatrixFree(m);
    return matrix1;
}

tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2)
{
    int i , j;
    tMatrix *m = MatrixCreate(matrix1->rows, matrix1->cols);
    for(i=0; i<matrix1->rows ; i++)
    {
        for(j=0 ; j<matrix1->cols ; j++)
        {
            m->data[i][j]= matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    MatrixPrint(m);
    MatrixFree(m);
    return matrix1;
}

tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2)
{
    int i , j, soma, z;
    tMatrix *m = MatrixCreate(matrix1->rows, matrix2->cols);
    for(i=0 ; i<matrix1->rows ; i++)
        {
            for(j=0 ; j<matrix2->cols ; j++)
            {
                soma=0;   
                for(z=0 ; z<matrix1->cols ; z++)
                {
                        soma=soma+(matrix1->data[i][z]*matrix2->data[z][j]);
                }
                m->data[i][j]=soma;
            }
        }
    MatrixPrint(m);
    MatrixFree(m);
    return matrix1;
}

tMatrix* TransposeMatrix(tMatrix* matrix)
{
    int i=0, j=0, aux=0;
    tMatrix *transposta = MatrixCreate(matrix->cols , matrix->rows);
    for(i=0 ; i<matrix->rows ; i++)
    {
        for(j=0 ; j<matrix->cols ; j++)
        {
            transposta->data[j][i] = matrix->data[i][j];
        }
    }
    MatrixFree(matrix);
    MatrixPrint(transposta);
    return transposta;
}

tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar)
{
    int i=0, j=0;
    for(i=0 ; i<matrix->rows ; i++)
    {
        for(j=0 ; j<matrix->cols ; j++)
        {
            matrix->data[i][j]= matrix->data[i][j]*scalar;
        }
    }
    MatrixPrint(matrix);
    return matrix;
}

