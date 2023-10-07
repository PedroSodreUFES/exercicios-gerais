#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n)
{
    int d, j;
    scanf("%d %d", &d , &j);
    *m=d;
    *n=j;
}

int EhPrimo(int n)
{
    int i=0, count=0;
    for(i=1; i<=n ; i++)
    {
        if(n%i==0)
        {
            count++;
        }
        if(count>2)
        {
            return 0;
        }
    }
    if(count==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    int i=1;
    for(m ; m<=n ; m++)
    {
        if(i==1&&EhPrimo(m))
        {
            *menor=m;
            i=2;
        }
        if(EhPrimo(m))
        {
            *maior=m;
        }
    }
}