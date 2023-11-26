#include "pacote.h"
#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gerenciadorpacotes{
    tPacote **listadepacotes;
    int npacotes;
};


tGerenciador* CriaGerenciador()
{
    tGerenciador *g = (tGerenciador*)malloc(sizeof(tGerenciador));
    g->listadepacotes=NULL;
    g->npacotes=0;
    return g;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac)
{
    geren->npacotes += 1;
    geren->listadepacotes = (tPacote**)realloc(geren->listadepacotes ,geren->npacotes * sizeof(tPacote*));
    geren->listadepacotes[geren->npacotes-1] = pac;   
}

void DestroiGerenciador(tGerenciador* geren)
{
    int i;
    for(i=0 ; i<geren->npacotes ; i++)
    {
        if(geren->listadepacotes[i]!=NULL)
        {
            DestroiPacote(geren->listadepacotes[i]);
        }
    }
    if(geren->listadepacotes!=NULL)
    {
        free(geren->listadepacotes);
    }
    if(geren!=NULL)
    {
        free(geren);
    }
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx)
{
    ImprimePacote(geren->listadepacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren)
{
    int i;
    for(i=0 ; i<geren->npacotes ; i++)
    {
        ImprimePacote(geren->listadepacotes[i]);
    }
}