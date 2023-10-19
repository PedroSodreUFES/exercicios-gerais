#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

tMatrix* MatrixCreate(int rows, int cols)
{
    tMatrix *mat;
    mat = malloc(sizeof(tMatrix));
    int i=0, j=0;
    mat->rows=rows;
    mat->cols=cols;
    mat->data = malloc(rows * sizeof(int));
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
    for(i=0; i<matrix1->rows ; i++)
    {
        for(j=0 ; j<matrix1->cols ; j++)
        {
            matrix1->data[i][j] += matrix2->data[i][j];
        }
    }
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
            m->data[i][j]
        }
    }
    return matrix1;
}

