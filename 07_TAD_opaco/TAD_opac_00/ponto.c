#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct ponto{
    float x, y;
};

tPonto Pto_Cria (float x, float y)
{
    tPonto p = (tPonto)malloc(sizeof(struct ponto));
    if(p==NULL)
    {
        printf("PONTO NAO CRIADO\n");
        exit(1);
    }
    Pto_Atribui_x(p, x);
    Pto_Atribui_y(p, y);
    return p;
}

void Pto_Apaga (tPonto p)
{
    if(p!=NULL)
    {
        free(p);
    }
}

float Pto_Acessa_x (tPonto p)
{
    return p->x;
}

float Pto_Acessa_y (tPonto p)
{
    return p->y;
}

void Pto_Atribui_x (tPonto p, float x)
{
    p->x=x;
}

void Pto_Atribui_y (tPonto p, float y)
{
    p->y=y;
}

float Pto_Distancia (tPonto p1, tPonto p2)
{
    float deltax, deltay, soma;
    deltax = (p1->x-p2->x) * (p1->x-p2->x);
    deltay = (p1->y-p2->y) * (p1->y-p2->y);
    soma = deltax + deltay;
    return sqrt(soma);
}