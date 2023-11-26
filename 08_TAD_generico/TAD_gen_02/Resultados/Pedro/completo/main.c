#include "pacote.h"
#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int opcao, tipo, numElemntos;
    Type p;
    tGerenciador *lista = CriaGerenciador();
    printf("tad_gen_02\n");
    while(1)
    {
        printf("\nEscolha uma opcao:\n	(1) Cadastrar um novo pacote\n	(2) Imprimir um pacote específico\n	(3) Imprimir todos os pacotes e sair\n");
        scanf("%d", &opcao);
        if(opcao==1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
            scanf("%d %d", &tipo, &numElemntos);
            if(tipo==1 || tipo==0)
            {
                if(tipo==1)
                {
                    p=INT;
                }
                else
                {
                    p=CHAR;
                }
                tPacote *pac = CriaPacote(p, numElemntos);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(lista, pac);
            }
            else
            {
                printf("Digite um tipo valido!");
            }    
        }
        else if(opcao==2)
        {
            scanf("%d", &tipo);
            ImprimirPacoteNoIndice(lista, tipo);
        }
        else if(opcao==3)
        {
            ImprimirTodosPacotes(lista);
            break;
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!");
        }
    }
    DestroiGerenciador(lista);
    return 0;
}