#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno
{
    char nome[100], data[11], curso[50];
    float cr;
    int periodo;
};

tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno *a = malloc(sizeof(tAluno));
    strcpy(a->nome, nome);
    strcpy(a->data, dataNascimento);
    strcpy(a->curso, curso);
    a->cr = coeficienteRendimento;
    a->periodo = periodo;
    return a;
}

tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[100], data[11], curso[50];
    float cr;
    int periodo;
    tAluno *a;
    fread(nome, sizeof(char), 100, arquivo_binario);
    fread(data, sizeof(char), 11, arquivo_binario);
    fread(curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&cr, sizeof(float), 1, arquivo_binario);
    a = CriarAluno(nome, data, curso, periodo, cr);
    return a;
}

void DestruirAluno(tAluno* aluno)
{
    if(aluno!=NULL)
    {
        free(aluno);
    }
}

float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->cr;
}