#include "circulo.h"
#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct ponto{
    float x, y;
};

struct circulo{
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r)
{
    tCirculo circle = (tCirculo)malloc(sizeof(struct circulo));
    tPonto p =Pto_Cria(x, y);
    Circulo_Atribui_Centro(circle, p);
    Circulo_Atribui_Raio(circle, r);
    return circle;
}

void Circulo_Apaga (tCirculo c)
{
    Pto_Apaga(c->centro);
    if(c!=NULL)
    {
        free(c);
    }
}

tPonto Circulo_Acessa_Centro (tCirculo c)
{
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c)
{
    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p)
{
    c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r)
{
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p)
{
    return Circulo_Acessa_Raio(c)  >= Pto_Distancia(p, c->centro);
}
