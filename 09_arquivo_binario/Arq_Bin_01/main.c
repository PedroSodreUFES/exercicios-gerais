#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nalunos;
    printf("Digite o numero de alunos: ");
    scanf("%d%*c", &nalunos);
    Aluno **lista = CriaVetorAlunos(nalunos);
    LeAlunos(lista, nalunos);
    SalvaAlunosBinario(lista, "alunos.bin" , nalunos);
    ImprimeAlunos(lista, nalunos);
    LiberaAlunos(lista, nalunos);
    return 0;
}