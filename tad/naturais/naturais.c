// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limits.h"
#include "naturais.h"

struct conjunto
{
    int codigo;
    long int* elementos;
};

// Funções acessórias

void exibaResultadoSucessoFalha(int resultado)
{
    resultado == 1 ? printf("SUCESSO\n") : printf("FALHA\n");
}

void exibaResultadoTrueFalse(int resultado)
{
    resultado == 1 ? printf("TRUE\n") : printf("FALSE\n");
}

int main()
{
    Conjunto* con;

    int resultado = criaConjunto(con, 1);

    if (con != NULL)
    {
        printf("O conjunto %d foi criado\n", con->codigo);
        
        con->elementos[0] = 5;

        if (con->elementos[0] == 5)
        {
            printf("O valor foi setado!\n");
        }
    }
    
    // con = (Conjunto*) malloc(sizeof(Conjunto));
    // con->elementos = (long int*) malloc(5 * sizeof(long int));
    con->elementos[0] = 5;
    con->elementos[1] = 10;
    con->elementos[2] = 15;

    int i = 0;

    while (con->elementos)
    {
        printf("VALOR %i : %li\n", i, con->elementos[i]);
        i++;
    }
    

    int tamanhoConjunto = sizeof(con->elementos) / sizeof(long int);

    exibaResultadoSucessoFalha(resultado);
    printf("Tamanho do conjunto: %i\n", tamanhoConjunto);


    printf("MENOR LONG INT: %li\n", LONG_MIN);
    printf("MAIOR LONG INT: %li\n", LONG_MAX);

    return 0;
}

// 1. criar um conjunto C, inicialmente vazio
int criaConjunto(Conjunto* conjunto, int codigo)
{
    conjunto = (Conjunto*) malloc(sizeof(Conjunto));

    if (conjunto != NULL)
    {
        conjunto->codigo = codigo;

        printf("O codigo %d foi setado\n", conjunto->codigo);

        return 1;
    }
    
    return 0;
}