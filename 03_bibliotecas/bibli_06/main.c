#include "b6.h"
#include <stdio.h>

int main()
{
    float temperatura;
    char grau, transformacao;
    scanf("%f %c %c", &temperatura, &grau, &transformacao);
    //celsius to kelvin
    if(grau == 'c' && transformacao == 'k')
    {
        temperatura = convert_temperature(temperatura, convert_celsius_to_kelvin);
        printf("Temperature: %.2fK", temperatura);
    }

    //celsius to fahrenheint
    else if(grau == 'c' && transformacao == 'f')
    {
        temperatura = convert_temperature(temperatura, convert_celsius_to_fahrenheit);
        printf("Temperature: %.2fFº", temperatura);
    }

    //fahrenheint to kelvin
    else if(grau == 'f' && transformacao == 'k')
    {
        temperatura = convert_temperature(temperatura, convert_fahrenheit_to_kelvin);
        printf("Temperature: %.2fK", temperatura);
    }

    //fahrenheint to celsius
    else if(grau == 'f' && transformacao == 'c')
    {
        temperatura = convert_temperature(temperatura, convert_fahrenheit_to_celsius);
        printf("Temperature: %.2fCº", temperatura);
    }

    //kelvin to celsius
    else if(grau == 'k' && transformacao == 'c')
    {
        temperatura = convert_temperature(temperatura, convert_kelvin_to_celsius);
        printf("Temperature: %.2fCº", temperatura);
    }

    //kelvin to fahrenheint
    else if(grau == 'k' && transformacao == 'f')
    {
        temperatura = convert_temperature(temperatura, convert_kelvin_to_fahrenheit);
        printf("Temperature: %.2fFº", temperatura);
    }
    return 0;
}