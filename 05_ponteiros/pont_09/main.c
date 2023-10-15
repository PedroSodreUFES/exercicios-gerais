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
    scanf("%d%*c", &i);
    while(i)
    {
        AssociaFamiliasGruposPessoas(galera);
        i--;
    }
    for(i=0; i<n ; i++)
    {
        if(VerificaSeTemPaisPessoa(galera+i))
        {
            ImprimePessoa(galera+i);
        }
    }
    return 0;
}