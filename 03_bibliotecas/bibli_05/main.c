#include "b5.h"
#include <stdio.h>

int main()
{
    int opcao;
    char palavra[MAX];
    scanf("%[^\n]%*c", palavra);
    while(1)
    {
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\n");
        scanf("%d", &opcao);
        printf("Opcao escolhida: \n");
        if(opcao==1)
        {
            printf("Tamanho da string: %d", string_length(palavra));
            printf("\n\n");
        }
        else if(opcao==2)
        {
            char copia[MAX];
            string_copy(palavra, copia);
            printf("String copiada: %s", copia);
            printf("\n\n");
        }
        else if(opcao==3)
        {
            string_upper(palavra);
            printf("String convertida para maiusculas: %s", palavra);
            printf("\n\n");
        }
        else if(opcao==4)
        {
            string_lower(palavra);
            printf("String convertida para minusculas: %s", palavra);
            printf("\n\n");
        }
        else if(opcao==5)
        {
            string_reverse(palavra);
            printf("\n\n");
        }
        else if(opcao==6)
        {
            break;
        }
        else
        {
            printf("Numero invalido, tente novamente\n");
        }
    }
    return 0;
}