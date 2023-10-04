#include "candidato.h"
#include <string.h>
#include <stdio.h>

tCandidato LeCandidato()
{
    tCandidato candidato;
    char nome[50] , partido[50] , cargo;
    int id;
    scanf("%[^,], %[^,], %c, %d%*c", nome, partido, &cargo, &id);
    candidato = CriaCandidato(nome, partido, cargo, id);
    return candidato;
}

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato; 
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    if(candidato.id==id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    float percentual;
    percentual = (float)candidato.votos/(float)totalVotos;
    return percentual*100;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n",candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if(candidato1.id==candidato2.id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
