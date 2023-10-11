#include "pessoa.h"
#include <stdio.h>

int main()
{
    int n;
    scanf("%d%*c", &n);
    tPessoa galera[n];
    int i=0;
    for(i=0 ; i<n ; i++)
    {
        galera[i] = CriaPessoa();
        LePessoa(galera+i);
    }
    printf("%s", galera[0].nome);
    return 0;
}