#include "matrizgenerica.h"
#include "numcomplexo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct complexo{
    float imag, real;
};

int main()
{
    int opcao, numBytesElem, linhas, colunas, i, j, quebraprograma=0;
    while(1)
    {
        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");
        scanf("%d %d %d", &linhas, &colunas, &opcao);
        if(opcao==0)
        {
            numBytesElem=sizeof(int);
        }
        else if(opcao==1)
        {
            numBytesElem=sizeof(float);
        }
        else if(opcao==2)
        {
            numBytesElem=sizeof(double);
        }
        else if(opcao==3)
        {
            numBytesElem=sizeof(char);
        }    
        else if(opcao==4)
        {
            numBytesElem=sizeof(tNumComplexo);
        }
        else
        {
            continue;
        }

        //faz a matriz
        tMatrizGenerica *mat = CriaMatrizGenerica(linhas, colunas, numBytesElem);
        //Le matriz
        if(opcao==0)
        {
            numBytesElem=sizeof(int);
        }
        else if(opcao==1)
        {
            numBytesElem=sizeof(float);
        }
        else if(opcao==2)
        {
            numBytesElem=sizeof(double);
        }
        else if(opcao==3)
        {
            numBytesElem=sizeof(char);
        }    
        else if(opcao==4)
        {
            numBytesElem=sizeof(tNumComplexo);
        }
        else
        {
            continue;
        }
        //operacoes
        while(1)
        {
            scanf("%d", &opcao);
            if(opcao==1)
            {

            }
            else if(opcao==2)
            {

            }
            else if(opcao==3)
            {

            }
            else
            {
                continue;
            }
        }
        while(1)
        {
            scanf("%d", &opcao);
            if(opcao==1)
            {

            }
            else if(opcao==2)
            {

            }   
            else
            {

            }      
        }
    }
    return 0;
}