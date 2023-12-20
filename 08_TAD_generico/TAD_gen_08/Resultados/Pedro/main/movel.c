#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movel{
    void *p;
    int tamanho;
};

tMovel *CriaMovel(char *nome)
{
    tMovel *m = (tMovel*)malloc(sizeof(tMovel));
    m->tamanho = strlen(nome)+1;
    m->p = malloc(m->tamanho * sizeof(char));
    memcpy(m->p, nome, m->tamanho * sizeof(char));
    return m;
}

void DestroiMovel(tMovel *m)
{
    if(m->p!=NULL)
    {
        free(m->p);
    }
    if(m!=NULL)
    {
        free(m);
    }
}

tMovel *LeMovel()
{
    char nome[30];
    scanf("%s%*c", nome);
    tMovel *m = CriaMovel(nome);
    return m;
}

void ImprimeMovel(tMovel *m)
{
    char *n;
    n = (char*)malloc(sizeof(char)*m->tamanho);
    memcpy(n , m->p , sizeof(char)*m->tamanho);
    printf("%s\n", n);
    free(n);
}