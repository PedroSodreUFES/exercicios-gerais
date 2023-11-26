#include "pacote.h"
#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacote{
    Type tipo;
    void *vetor;
    int tamanho;
};

tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote*)malloc(sizeof(tPacote));
    p->tamanho = numElem;
    p->tipo=type;
    p->vetor=NULL;
    if(type==INT)
    {
        p->vetor = malloc(sizeof(int) * numElem);
    }
    else if(type==CHAR)
    {
        p->vetor = malloc(sizeof(char) * (numElem /*+1*/));
    }
    return p;
}

void DestroiPacote(tPacote* pac)
{
    if(pac->vetor!=NULL)
    {
        free(pac->vetor);
    }
    if(pac!=NULL)
    {
        free(pac);
    }
}

void LePacote(tPacote* pac)
{
    int i;
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if(pac->tipo==CHAR)
    {
        char n;
        scanf("%*c");
        for(i=0 ; i<pac->tamanho ; i++)
        {
            scanf("%c", &n);
            memcpy(pac->vetor + (i*sizeof(char)), &n, sizeof(char));
        }
    }
    else if(pac->tipo==INT)
    {
        int n;
        for(i=0 ; i<pac->tamanho ; i++)
        {
            scanf("%d", &n);
            memcpy(pac->vetor + (i*sizeof(int)), &n, sizeof(int));
        }
    }   
}

void ImprimePacote(tPacote* pac)
{
    int i;
    if(pac->tipo==INT)
    {   
        CalculaSomaVerificacaoPacote(pac);
        int n;
        for(i=0 ; i<pac->tamanho ; i++)
        {
            memcpy(&n , pac->vetor + (i*sizeof(int)), sizeof(int));
            printf("%d", n);
            if(i!=pac->tamanho-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }   
    else if(pac->tipo==CHAR)
    {
        CalculaSomaVerificacaoPacote(pac);
        char n;
        for(i=0 ; i<pac->tamanho ; i++)
        {
            memcpy(&n , pac->vetor + (i*sizeof(char)), sizeof(char));
            if(n!='\n')
            {
                printf("%c", n);
            }
        }
        printf("\n");
    }
}

void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    int salva=0, i;
    if(pac->tipo==CHAR)
    {
        char n;
        for(i=0 ; i<pac->tamanho ; i++)
        {
            memcpy(&n , pac->vetor + (i*sizeof(char)), sizeof(char));
            if(n!='\n')
            {
                salva+= ((int)n);
            }
        }
    }
    else if(pac->tipo==INT)
    {
        int n;
        for(i=0 ; i<pac->tamanho ; i++)
        {
            memcpy(&n , pac->vetor + (i*sizeof(int)), sizeof(int));
            salva+=n;
        }
    }
    printf("%d ", salva);
}
