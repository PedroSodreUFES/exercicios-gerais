#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[51], sex;
    float nota;
};

tAluno *CriaAluno()
{
    tAluno *a = malloc(sizeof(tAluno));
    a->nota=-1;
    a->sex='1';
    a->nome[0]='\0';
    return a;
}

void DestroiAluno(data_type aluno)
{
    tAluno *a = (tAluno*)aluno;
    if(a!=NULL)
    {
        free(a);
    }
}

void LeAluno(tAluno *aluno)
{
    char nome[51], letra;
    float nota;
    scanf("%[^;];%c;%f", nome, &letra, &nota);
    nome[strlen(nome)]='\0';
    strcpy(aluno->nome, nome);
    aluno->nota=nota;
    aluno->sex=letra;
}

char GetGeneroAluno(tAluno *aluno)
{
    return aluno->sex;
}

float GetNotaAluno(tAluno *aluno)
{
    return aluno->nota;
}