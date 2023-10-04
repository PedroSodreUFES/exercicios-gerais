#include "eleitor.h"
#include <stdio.h>

tEleitor LeEleitor()
{
    tEleitor eleitor;
    int id, vp, vg;
    scanf("%d %d %d", &id, &vp, &vg);
    eleitor = CriaEleitor(id, vp, vg);
    return eleitor;
}

tEleitor CriaEleitor(int id, int votoP, int votoG)
{
    tEleitor eleitor;
    eleitor.id=id;
    eleitor.votoP=votoP;
    eleitor.votoG=votoG;
    return eleitor;  
}

int ObtemVotoPresidente(tEleitor eleitor)
{
    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor)
{
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2)
{
    if(eleitor1.id==eleitor2.id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
