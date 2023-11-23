#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
    int dia, mes, ano;
};

tData* CriaData()
{
    tData *data = (tData*)malloc(sizeof(tData));
    data->dia=-1;
    data->mes=-1;
    data->ano=-1;
    return data;
}

void LeData(tData* data)
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    data->dia=dia;
    data->mes=mes;
    data->ano=ano;
}

void LiberaData(tData* data)
{
    if(data!=NULL)
    {
        free(data);
    }
}

int VerificaDataValida(tData* data)
{
    if(data->dia < 1 || data->dia > NumeroDiasMes(data))
    {
        return 0;
    }
    if(data->mes<1 || data->mes>12)
    {
        return 0;
    }
    return 1;
}

int VerificaBissexto(tData* data)
{
    if((data->ano % 4  == 0 && data->ano%100 != 0) || data->ano%400 ==0)
    {
        return 1;
    }
    return 0;
}

int NumeroDiasMes(tData* data)
{
    if(data->mes==1 || data->mes==3 || data->mes==5 || data->mes==7 || data->mes==8 || data->mes==10 || data->mes==12)
    {
        return 31;
    }
    if(data->mes==4 || data->mes==6 || data->mes==9 || data->mes==11 )
    {
        return 30;
    }
    if(data->mes==2)
    {
        if(VerificaBissexto(data))
        {
            return 29;
        }
        return 28;
    }
}

void ImprimeMesExtenso(tData* data)
{
    if(data->mes==1)
    {
        printf("Janeiro");
    }
    else if(data->mes==2)
    {
        printf("Fevereiro");
    }
    else if(data->mes==3)
    {
        printf("Março");
    }
    else if(data->mes==4)
    {
        printf("Abril");    
    }
    else if(data->mes==5)
    {
        printf("Maio");
    }
    else if(data->mes==6)
    {
        printf("Junho");
    }
    else if(data->mes==7)
    {
        printf("Julho");
    }
    else if(data->mes==8)
    {
        printf("Agosto");
    }
    else if(data->mes==9)
    {
        printf("Setembro");
    }
    else if(data->mes==10)
    {
        printf("Outubro");
    }
    else if(data->mes==11)
    {
        printf("Novembro");
    }
    else if(data->mes==12)
    {
        printf("Dezembro");
    }
}

void ImprimeDataExtenso(tData* data)
{
    printf("%d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

int ComparaData(tData* data1, tData* data2)
{
    if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia == data2->dia)
    {
        return 0;
    }
    if(data1->ano > data2->ano)
    {
        return 1;
    }
    else if(data1->ano==data2->ano)
    {
        if(data1->mes > data2->mes)
        {
            return 1;
        }
        else if(data1->mes==data2->mes)
        {
            if(data1->dia > data2->dia)
            {
                return 1;
            }
        }
    }
    return -1;
}

int CalculaDiasAteMes(tData* data)
{
    int i, soma=0;
    for(i=data->mes ; i>0 ; i--)
    {
        soma += NumeroDiasMes(i); 
    }
    return soma;
}

int CalculaDiferencaDias(tData* data1, tData* data2)
{
    
}