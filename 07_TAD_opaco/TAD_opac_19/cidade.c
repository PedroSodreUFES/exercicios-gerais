#include "missil.h"
#include "cidade.h"
#include "defesa.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct cidade{
    int nmissil, ndefesa;
    tMissil *listademisseis;
    tDefesa *listadedefesa;
    char *nome;
};

tCidade CriaCidade()
{
    tCidade cidade = malloc(sizeof(tCidade));
    cidade->listadedefesa=NULL;
    cidade->listademisseis=NULL;
    cidade->ndefesa=0;
    cidade->nmissil=0;
    cidade->nome=NULL;
    return cidade;
}