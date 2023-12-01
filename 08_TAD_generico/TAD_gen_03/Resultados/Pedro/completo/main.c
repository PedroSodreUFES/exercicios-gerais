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


int main()
{
    Vector *v = VectorConstruct();
    tAluno *a;
    int d, i;
    scanf("%d%*c", &d);
    for(i=0 ; i<d ; i++)
    {
        a=CriaAluno();
        LeAluno(a);
        VectorPushBack(v, (void*)a);
    }
    ImprimeRelatorio(v);
    VectorDestroy(v, DestroiAluno);
    return 0;
}