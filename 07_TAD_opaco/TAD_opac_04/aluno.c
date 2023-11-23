#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char *nome;
    int matricula, n1, n2, n3;
};

void ApagaAluno(tAluno *aluno)
{
    if(aluno->nome!=NULL)
    {
        free(aluno->nome);
    }
    if(aluno!=NULL)
    {
        free(aluno);
    }
}

tAluno* CriaAluno()
{
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));
    if(aluno==NULL)
    {
        printf("NAO ALOCOU O ALUNO\n");
        exit(1);
    }
    aluno->nome=NULL;
    aluno->n1=-1;
    aluno->n2=-1;
    aluno->n3=-1;
    aluno->matricula=-1;
    return aluno;
}

void LeAluno(tAluno *aluno)
{
    char nome[100];
    int n1, n2, n3, matricula;
    scanf("%[^\n]%*c", nome);
    aluno->nome = (char*)malloc((strlen(nome)+1) * sizeof(char));
    if(aluno->nome==NULL)
    {
        printf("nome do aluno nao alocado\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    scanf("%d", &matricula);
    scanf("%d %d %d%*c", &n1, &n2, &n3);
    aluno->matricula=matricula;
    aluno->n1=n1;
    aluno->n2=n2;
    aluno->n3=n3;
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2)
{
    if(aluno1->matricula > aluno2->matricula)
    {
        return 1;
    }
    if(aluno1->matricula < aluno2->matricula)
    {
        return -1;
    }
    return 0;
}

int VerificaAprovacao(tAluno* aluno)
{
    if(CalculaMediaAluno(aluno)>=7)
    {
        return 1;
    }
    return 0;
}

int CalculaMediaAluno(tAluno* aluno)
{
    return (aluno->n1+aluno->n2+aluno->n3)/3;
}

void ImprimeAluno(tAluno* aluno)
{
    printf("%s\n", aluno->nome);
}