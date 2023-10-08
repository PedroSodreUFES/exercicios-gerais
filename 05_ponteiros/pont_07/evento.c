#include "evento.h"
#include <stdio.h>
#include <string.h>

void cadastrarEvento(Evento* eventos, int* numEventos)
{
    if(*numEventos==10)
    {
        printf("Limite de eventos atingido!\n");
        return;
    }
    int dia, mes, ano; 
    char nome[50];
    scanf("%*c%[^\n]%*c", nome);   
    scanf("%d %d %d", &dia, &mes, &ano);
    strcpy(eventos[*numEventos].nome, nome);
    eventos[*numEventos].dia=dia;
    eventos[*numEventos].mes=mes;
    eventos[*numEventos].ano=ano;
    *numEventos+=1;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos)
{
    int i=0;
    if(*numEventos==0)
    {
        printf("Nenhum evento cadastrado.\n");
        return;
    }
    printf("Eventos cadastrados:\n");
    for(i=0; i<*numEventos ; i++)
    {
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int indice;
    scanf("%d", &indice);
    if(indice>*numEventos||*numEventos==0)
    {
        printf("Indice invalido!\n");
        return;
    }
    int dia, mes, ano; 
    scanf("%d %d %d", &dia, &mes, &ano);
    eventos[indice].dia=dia;
    eventos[indice].mes=mes;
    eventos[indice].ano=ano;
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    if(*indiceA>=*numEventos || *indiceB>=*numEventos ||*numEventos<2 || *indiceA<0 || *indiceB<0)
    {
        printf("Indices invalidos!\n");
        return;
    }
    Evento aux;
    aux = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;
    printf("Eventos trocados com sucesso!\n");
}