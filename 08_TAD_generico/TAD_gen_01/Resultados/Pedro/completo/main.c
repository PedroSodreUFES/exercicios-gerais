#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    int tipo, nelementos;
    scanf("%d %d", &tipo, &nelementos);
    tGeneric *g = CriaGenerico(tipo, nelementos);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
    return 0;
}