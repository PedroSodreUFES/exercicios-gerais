#include "circulo.h"
#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ponto{
    float x, y;
};

struct circulo{
    tPonto centro;
    float raio;
};

int main(int argc, char **argv)
{
    float cx, cy, r, x, y;
    scanf("%f %f %f %f %f", &cx, &cy, &r, &x, &y);
    tCirculo circle = Circulo_Cria(cx, cy, r);
    tPonto point = Pto_Cria(x, y);
    if(Circulo_Interior(circle, point))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    Pto_Apaga(point);
    Circulo_Apaga(circle);
    return 1;
}