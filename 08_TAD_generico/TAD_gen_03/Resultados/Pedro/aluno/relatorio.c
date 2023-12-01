#include "aluno.h"
#include "vector.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    data_type *vet;
    int tamanho;
};

struct Aluno{
    char nome[51], sex;
    float nota;
};


void ImprimeRelatorio(Vector *alunos)
{
    int i;
    char c;
    float nota=0, masculino=0, feminino=0, outro=0, aprovados=0, media=0;
    for(i=0 ; i<VectorSize(alunos) ; i++)
    {
        c = GetGeneroAluno(VectorGet(alunos, i));
        if(c=='M')
        {
            masculino++;
        }
        else if(c=='F')
        {
            feminino++;
        }
        else if(c=='O')
        {
            outro++;
        }
        nota = GetNotaAluno(VectorGet(alunos, i));
        if(nota >= 6)
        {
            aprovados+=1;
        }
        media += nota;
    }
    media /=VectorSize(alunos);
    aprovados = (aprovados/VectorSize(alunos)) * 100;
    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", aprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", masculino*100/VectorSize(alunos));
    printf("Feminino: %.2f%%\n", feminino*100/VectorSize(alunos));
    printf("Outro: %.2f%%\n", outro*100/VectorSize(alunos));
}