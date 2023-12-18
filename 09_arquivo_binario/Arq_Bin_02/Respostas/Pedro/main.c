#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"

int main()
{
    char nome[200];
    tBaseAlunos *b = CriarBaseAlunos();
    scanf("%s", nome);
    LerBaseAlunos(b, nome);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(b));
    DestruirBaseAlunos(b);
    return 0;
}