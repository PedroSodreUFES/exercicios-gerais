#include "esfera_utils.h"

void CalculaVolume (float R, float *volume)
{
    *volume = R*R*R*PI*4/3;
}

void CalculaArea (float R, float *area)
{
    *area = R*R*PI*4;
}