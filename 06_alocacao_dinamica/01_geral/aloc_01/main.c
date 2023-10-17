#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    int *v = CriaVetor(tamanho);
    LeVetor(v, tamanho);
    float media = CalculaMedia(v, tamanho);
    printf("%.2f\n", media);
    LiberaVetor(v);
    return 0;
}