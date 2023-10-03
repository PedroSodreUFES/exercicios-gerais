#include "b4.h"
#include <stdio.h>

void imprimeMesExtenso(int mes)
{
    if(mes==1)
    {
        printf("Janeiro ");
    }
    else if(mes==2)
    {
        printf("Fevereiro ");
    }
    else if(mes==3)
    {
        printf("Marco ");
    }
    else if(mes==4)
    {
        printf("Abril ");
    }
    else if(mes==5)
    {
        printf("Maio ");
    }
    else if(mes==6)
    {
        printf("Junho ");
    }
    else if(mes==7)
    {
        printf("Julho ");
    }
    else if(mes==8)
    {
        printf("Agosto ");
    }
    else if(mes==9)
    {
        printf("Setembro ");
    }
    else if(mes==10)
    {
        printf("Outubro ");
    }
    else if(mes==11)
    {
        printf("Novembro ");
    }
    else if(mes==12)
    {
        printf("Dezembro ");
    }
}

void imprimeData(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf("de %04d\n", ano);
}

int verificaBissexto(int ano)
{
    if((ano%4==0 && ano%100!=0)  || ano%400==0)
    {
        return 1;
    }
    else return 0;
}

int verificaDataValida(int dia, int mes, int ano)
{
    if((mes<1 || mes>12))
    {
        return 0;
    }
    if(ano<0)
    {
        return 0;
    }
    if(dia>=1 && dia <= numeroDiasMes(mes, ano))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if(mes1==mes2 && dia1 == dia2 && ano1==ano2)
    {
        return 0;
    }
    else if(ano1<ano2)
    {
        return -1;
    }
    else if(ano2<ano1)
    {
        return 1;
    }
    else if(ano2==ano1)
    {
        if(mes1<mes2)
        {   
            return -1;
        }
        else if(mes2<mes1)
        {
            return 1;
        }
        else if(mes2==mes1)
        {
            if(dia1<dia2)
            {   
                return -1;
            }
            else if(dia2<dia1)
            {
                return 1;
            }
        }
    }
}

int numeroDiasMes(int mes, int ano)
{
    if(mes==1 || mes==3 ||mes==5||mes==7 ||mes==8 ||mes==10 || mes==12)
    {
        return 31;
    }
    else if(mes==4 ||mes==6 ||mes==9 ||mes==11)
    {
        return 30;
    }
    else if(mes==2)
    {
        if(verificaBissexto(ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

int calculaDiasAteMes(int mes, int ano)
{
    int dia=0, x=0;
    for(x = mes ; x > 0 ; x--)
    {
        dia = dia + numeroDiasMes(x, ano);
    }
    return dia;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int x=0, y=0, z=0, count=0;
    for(x = ano1 ; x<=ano2 ; x++)
    {
        for(y = mes1 ; y<= 12 ; y++)
        {
            for(z = dia1 ; z <= numeroDiasMes(y, x) ; z++)
            {
                if(x==ano2 && y == mes2 && z==dia2)
                {
                    return count;
                }
                count++;
            }
            dia1=1;
        }
        mes1=1;
    }
}

void imprimeProximaData(int dia, int mes, int ano)
{
    if(dia+1 > numeroDiasMes(mes, ano))
    {
        dia=1;
        mes+=1;
        if(mes==13)
        {
            mes=1;
            ano+=1;
        }
    }
    else
    {
        dia+=1;
    }
    printf("A data seguinte eh: %02d/%02d/%02d", dia, mes, ano);
}