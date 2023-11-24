#include "array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    Array *a = CriarArray();
    LerArray(a);
    OrdenarArray(a);
    int valor, indice;
    scanf("%d", &valor);
    indice = BuscaBinariaArray(a, valor);
    if(indice==-1)
    {
        printf("Elemento %d não encontrado no array (-1).\n", valor);
    }
    else
    {
        printf("Elemento %d encontrado no índice %d.\n", valor, indice);
    }
    DestruirArray(a);
    return 0;
}