#include "estabelecimento.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    tEstabelecimento *e = CriaEstabelecimento();
    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);
    return 0;
}