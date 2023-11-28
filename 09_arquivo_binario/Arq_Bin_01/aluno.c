#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct aluno{
    char *nome, *curso, *datadenascimento, *periodo;
    int porcentagem;
    float coeficiente;
 };

Aluno** CriaVetorAlunos(int numeroAlunos)
{
    Aluno **lista = (Aluno**)malloc(sizeof(Aluno*)*numeroAlunos);
    if(lista==NULL)
    {
        printf("NAO ALOCOU A LISTA DE ALUNOS\n");
        exit(1);
    }
    return lista; 
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    aluno->nome=(char*)malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(aluno->nome, nome);
    aluno->datadenascimento=(char*)malloc(sizeof(char)*(strlen(dtNasc)+1));
    strcpy(aluno->datadenascimento, dtNasc);
    aluno->curso=(char*)malloc(sizeof(char)*(strlen(cursoUfes)+1));
    strcpy(aluno->curso, cursoUfes);
    aluno->periodo=(char*)malloc(sizeof(char)*(strlen(periodoIngresso)+1));
    strcpy(aluno->periodo, periodoIngresso);
    aluno->coeficiente=CRA;
    aluno->porcentagem=percConclusao;
    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
    int i;
    char nome[200], data[200], curso[200], periodo[200];
    int pctg;
    float cra;
    for(i=0 ; i<numeroAlunos ; i++)
    {
        scanf("%[^\n]%*c", nome);
        nome[strlen(nome)]='\0';
        scanf("%[^\n]%*c", data);
        data[strlen(data)]='\0';
        scanf("%[^\n]%*c", curso);
        curso[strlen(curso)]='\0';
        scanf("%[^\n]%*c", periodo);
        periodo[strlen(periodo)]='\0';
        scanf("%d", &pctg);
        scanf("%f%*c", &cra);
        vetorAlunos[i]=CriaAluno(nome, data, curso, periodo, pctg, cra);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
    int i;
    for(i=0 ; i<numeroAlunos ; i++)
    {
        if(alunos[i]->nome!=NULL)
        {
            free(alunos[i]->nome);
        }
        if(alunos[i]->datadenascimento!=NULL)
        {
            free(alunos[i]->datadenascimento);
        }
        if(alunos[i]->curso!=NULL)
        {
            free(alunos[i]->curso);
        }
        if(alunos[i]->periodo!=NULL)
        {
            free(alunos[i]->periodo);
        }
        if(alunos[i]!=NULL)
        {
            free(alunos[i]);
        }
    }
    if(alunos!=NULL)
    {
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    FILE *arquivo;
    arquivo = fopen(fileName, "wb");
    if(arquivo==NULL)
    {
        printf("arquivo nao foi aberto\n");
        exit(1);
    }
    int i, j=0;
    j += fwrite(&numeroAlunos , sizeof(int), 1, arquivo);
    for(i=0 ; i<numeroAlunos ; i++)
    {
        j += fwrite(alunos[i], sizeof(Aluno), 1, arquivo);
        j += fwrite(alunos[i]->nome, sizeof(char), strlen(alunos[i]->nome), arquivo);
        j += fwrite(alunos[i]->periodo, sizeof(char), strlen(alunos[i]->periodo), arquivo);
        j += fwrite(alunos[i]->curso, sizeof(char), strlen(alunos[i]->curso), arquivo);
        j += fwrite(alunos[i]->datadenascimento, sizeof(char), strlen(alunos[i]->datadenascimento), arquivo);
    }
    printf("Numero de bytes salvos: %d\n", j);
    fclose(arquivo);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
    int i;
    for(i=0 ; i<numeroAlunos ; i++)
    {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->datadenascimento);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->porcentagem);
        printf("CRA: %.2f\n", alunos[i]->coeficiente);
    }
}