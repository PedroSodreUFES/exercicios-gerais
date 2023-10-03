#include "b1.h"
#include <stdio.h>

int main()
{
    float raio, area, volume;
    scanf("%f", &raio);
    area = CalculaArea(raio);
    volume = CalculaVolume(raio);
    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
    return 0;
}