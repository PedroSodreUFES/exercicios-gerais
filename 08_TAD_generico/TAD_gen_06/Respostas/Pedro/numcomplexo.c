#include "matrizgenerica.h"
#include "numcomplexo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct complexo{
    float imag, real;
};

int RetornaNumBytesComplexo()
{
    return sizeof(tNumComplexo);
}

tNumComplexo* CriaNumComplexo(float real, float imag)
{
    tNumComplexo *n = (tNumComplexo*)malloc(sizeof(tNumComplexo));
    n->imag=imag;
    n->real=real;
    return n;
}

float PegaParteImagComplexo(tNumComplexo *cplx)
{
    return cplx->imag;
}

float PegaParteRealComplexo(tNumComplexo *cplx)
{
    return cplx->real;
}

void ImprimeNumeroComplexo(tNumComplexo *cplx)
{
    printf("%.2f + i%.2f", PegaParteRealComplexo(cplx) , PegaParteImagComplexo(cplx));
}

void DestroiNumeroComplexo(tNumComplexo *cplx)
{
    if(cplx!=NULL)
    {
        free(cplx);
    }
}

tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo *n2)
{
    tNumComplexo* soma = CriaNumComplexo(PegaParteRealComplexo(n1)+PegaParteRealComplexo(n2), PegaParteImagComplexo(n1)+PegaParteImagComplexo(n2));
    return soma;
}

tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2)
{
    tNumComplexo *produto = CriaNumComplexo(0 ,0);
    produto->real = (PegaParteRealComplexo(n1) * PegaParteRealComplexo(n2)) + (PegaParteImagComplexo(n1) * PegaParteImagComplexo(n2) * -1); 
    produto->imag = (PegaParteRealComplexo(n1) * PegaParteImagComplexo(n2)) + (PegaParteRealComplexo(n2) * PegaParteImagComplexo(n1));
    return produto;
}