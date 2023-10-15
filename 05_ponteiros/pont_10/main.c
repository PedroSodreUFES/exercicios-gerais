#include "pessoa.h"
#include <stdio.h>
int main()
{
    int n;
    scanf("%d%*c", &n);
    tPessoa pessoas[n];
    int i=0;
    for(i=0 ; i<n ; i++)
    {
        pessoas[i]=CriaPessoa();
        LePessoa(pessoas+i);
    }
    AssociaFamiliasGruposPessoas(pessoas, n);
    for(i=0 ; i<n ; i++)
    {
        if(VerificaSeTemPaisPessoa(pessoas+i))
        {
            ImprimePessoa(pessoas+i);
        }
    }
    return 0;
}