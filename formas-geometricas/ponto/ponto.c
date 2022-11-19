/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

// Implementações

struct ponto 
{
    float coordenadaX;
    float coordenadaY;
};

Ponto* criarPonto(float coordenadaX, float coordenadaY)
{
    Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
    
    if (ponto != NULL)
    {
        ponto->coordenadaX = coordenadaX;
        ponto->coordenadaY = coordenadaY;
    }
    
    return ponto;
}

void liberarPonto(Ponto* ponto)
{
    if (ponto != NULL)
    {
        free(ponto);
    }
}

void acessarPonto(Ponto* ponto, float* coordenadaX, float* coordenadaY)
{
    *coordenadaX = ponto->coordenadaX;
    *coordenadaY = ponto->coordenadaY;
}

void atribuirPonto(Ponto* ponto, float coordenadaX, float coordenadaY)
{
    if (ponto != NULL)
    {
        ponto->coordenadaX = coordenadaX;
        ponto->coordenadaY = coordenadaY;
    }
}

float calcularDistanciaEntrePontos(Ponto* ponto1, Ponto* ponto2)
{
    float potenciaX = pow((ponto1->coordenadaX - ponto2->coordenadaX), 2);
    float potenciaY = pow((ponto1->coordenadaY - ponto2->coordenadaY), 2);
    
    float distanciaEuclidiana = sqrt(potenciaX + potenciaY);
    
    return distanciaEuclidiana;
}

int main()
{
    float distancia;
    
    Ponto *ponto1, *ponto2;
    
    ponto1 = criarPonto(10, 21);
    ponto2 = criarPonto(7, 25);
    
    distancia = calcularDistanciaEntrePontos(ponto1, ponto2);
    
    printf("Distancia entre pontos: %f\n", distancia);
    
    liberarPonto(ponto1);
    liberarPonto(ponto2);
    
    return 0;
}
