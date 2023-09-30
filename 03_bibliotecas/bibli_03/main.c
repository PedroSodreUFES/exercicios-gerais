#include "b3.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    //data invalida
    if(!verificaDataValida(dia1, mes1, ano1)||!verificaDataValida(dia2,mes2,ano2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }
    //data valida
    else
    {
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
    }
    //mesmo dia
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2)==0)
    {
        printf("As datas sao iguais\nA diferenca em dias entre as datas eh: 00 dias\n");
        return 1;
    }
    //primeiro dia vem antes
    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2)==-1)
    {
        printf("A primeira data eh mais antiga\n");
        printf("A diferenca em dias entre as datas eh: %02d dias\n" , calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
    }
    //segundo dia vem antes
    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2)==1)
    {
        printf("A segunda data eh mais antiga\n");
        printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia2, mes2, ano2, dia1, mes1, ano1));
    }
    return 1;
}