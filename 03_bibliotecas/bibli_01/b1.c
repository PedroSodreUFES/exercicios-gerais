#include "b1.h"

#define pi 3.14

float CalculaVolume(float raio)
{
    return (raio*raio*raio*pi*4)/3;
}

float CalculaArea(float raio)
{
    return 4 * pi * raio * raio;
}