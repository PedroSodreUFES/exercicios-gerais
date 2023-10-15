#include <stdio.h>
#include "calculadora.h"

float Divisao(float num1, float num2)
{
    return num1/num2;
}

float Multiplicacao(float num1, float num2)
{
    return num1*num2; 
}

float Adicao(float num1, float num2)
{
    return num1+num2;
}

float Subtracao(float num1, float num2)
{
    return num1-num2;
}

int main()
{
    CalculatoraCallback p;
    float num1, num2;
    char letra;
    while(1)
    {
        scanf("%c%*c", &letra);
        if(letra=='f')
        {
            break;
        }
        scanf("%f %f%*c", &num1, &num2);
        if(letra=='d')
        {
            p=Divisao;
            printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, p));
        }
        else if(letra=='m')
        {
            p=Multiplicacao;
            printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, p));
        }
        else if(letra=='a')
        {
            p=Adicao;
            printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, p));
        }
        else if(letra=='s')
        {
            p=Subtracao;
            printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, p));
        }
    }
}