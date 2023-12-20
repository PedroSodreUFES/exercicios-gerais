#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    Fila *f = FilaConstruct();
    tMovel *m;
    int d, i;
    char nome[30];
    scanf("%d%*c", &d);
    while(scanf("%s%*c", nome)==1)
    {
        if(strcmp(nome, "ENTRADA")==0)
        {
            m = LeMovel();
            FilaPush(f, (void*)m);
        }
        else
        {
            m = (tMovel*)FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }
    FilaDestroy(f, DestroiMovel);
    return 0;
}