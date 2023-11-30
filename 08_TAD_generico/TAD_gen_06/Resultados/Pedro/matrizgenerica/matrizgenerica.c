#include "matrizgenerica.h"
#include "numcomplexo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct matrizgenerica{
    int linhas, colunas, numByteElem;
    void *mat;
};

tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    tMatrizGenerica *gen = (tMatrizGenerica*)malloc(sizeof(tMatrizGenerica));
    if(gen==NULL)
    {
        printf("nao alocou o tad\n");
        exit(1);
    }
    gen->colunas=colunas;
    gen->linhas=linhas;
    gen->numByteElem=numByteElem;
    gen->mat = calloc(linhas * colunas,  numByteElem);
    if(gen->mat==NULL)
    {
        printf("matriz nao alocada\n");
        exit(2);
    }
    return gen;
}

void DestroiMatrizGenerica(tMatrizGenerica * mat)
{
    if(mat->mat!=NULL)
    {
        free(mat->mat);
    }
    if(mat!=NULL)
    {
        free(mat);
    }
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat)
{
    return mat->linhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat)
{
    return mat->colunas;
}

void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna)
{
    return mat->mat + (linha*(mat->colunas*mat->numByteElem) + (coluna*mat->numByteElem));
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem)
{
    memcpy(mat->mat + (linha*(mat->colunas*mat->numByteElem) + (coluna*mat->numByteElem)), elem, mat->numByteElem);
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat)
{
    tMatrizGenerica *transposta = CriaMatrizGenerica(ObtemNumeroColunasMatrizGenerica(mat), ObtemNumeroLinhasMatrizGenerica(mat) , mat->numByteElem);
    int i, j;
    void *copia;
    for(i=0 ; i<ObtemNumeroLinhasMatrizGenerica(mat) ; i++)
    {
        for(j=0 ; j<ObtemNumeroColunasMatrizGenerica(mat) ; j++)
        {
            copia = ObtemElementoMatrizGenerica(mat, i, j);
            AtribuiElementoMatrizGenerica(transposta, j , i, copia);
        }
    }
    return transposta;
}

tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*))
{
    tMatrizGenerica *convertida = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat2), ObtemNumeroColunasMatrizGenerica(mat2), novoNumByteElem);
    int i, j;
    void *copia;
    for(i=0 ; i<ObtemNumeroLinhasMatrizGenerica(mat2) ; i++)
    {
        for(j=0 ; j<ObtemNumeroColunasMatrizGenerica(mat2) ; j++)
        {
            copia = ObtemElementoMatrizGenerica(mat2, i, j);
            copia = converte_elem(copia);
            AtribuiElementoMatrizGenerica(convertida, i, j, copia);
            free(copia);
        }
    }
    return convertida;    
}

tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*))
{
    int i, j, z;
    void *elem1, *elem2, *produto, *soma, *result;
    result = calloc(1, numByteTarget);
    tMatrizGenerica *multiplicada = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat1), ObtemNumeroColunasMatrizGenerica(mat2), numByteTarget);
    for(i=0;i<ObtemNumeroLinhasMatrizGenerica(mat1);i++)
    {
        for(j=0;j<ObtemNumeroColunasMatrizGenerica(mat2);j++)
        {
            soma = calloc(1, numByteTarget);
            memcpy(result , soma, numByteTarget);
            for(z=0 ; z< ObtemNumeroColunasMatrizGenerica(mat1) ; z++)
            {
                free(soma);
                elem1 = ObtemElementoMatrizGenerica(mat1, i, z);
                elem2 = ObtemElementoMatrizGenerica(mat2, z, j);
                produto = multi_elem(elem1, elem2);
                soma = soma_elem(result, produto);
                memcpy(result, soma, numByteTarget);
                free(produto);
            }
            AtribuiElementoMatrizGenerica(multiplicada, i, j, soma);
            free(soma);
        }
    }
    free(result);
    return multiplicada;
}

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*)))
{
    int i , j;
    for(i=0 ; i<ObtemNumeroLinhasMatrizGenerica(mat); i++)
    {
        for(j=0 ; j<ObtemNumeroColunasMatrizGenerica(mat) ; j++)
        {
            imprime_elemento(ObtemElementoMatrizGenerica(mat, i , j));
            if(j!=ObtemNumeroColunasMatrizGenerica(mat)-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}