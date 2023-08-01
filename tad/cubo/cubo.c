#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

// Implementações

struct cubo
{
    float aresta;
};

Cubo* criarCubo(float aresta)
{
    Cubo* cubo = (Cubo*) malloc(sizeof(Cubo));
    
    if (cubo != NULL)
    {
        cubo->aresta = aresta;
    }
    
    return cubo;
}

void liberarCubo(Cubo* cubo)
{
    if (cubo != NULL)
    {
        free(cubo);
    }
}

float acessarCubo(Cubo* cubo)
{
    if (cubo != NULL)
    {
        return cubo->aresta;
    }
    
    return 0;
}

void atribuirCubo(Cubo* cubo, float aresta)
{
    if (cubo != NULL)
    {
        cubo->aresta = aresta;
    }
}

float calcularArea(Cubo* cubo)
{
    float areaDaBase = cubo->aresta * cubo->aresta;
    float areaTotal = 6 * areaDaBase;
    
    return areaTotal;
}

float calcularVolume(Cubo* cubo)
{
    float volume = pow(cubo->aresta, 3);
    
    return volume;
}

int main()
{
    float area, volume;
    Cubo* cubo;
    
    cubo = criarCubo(2.0);
    area = calcularArea(cubo);
    volume = calcularVolume(cubo);
    
    printf("A area do cubo eh: %f\n", area);
    printf("O volume do cubo eh: %f\n", volume);
    
    return 0;
}
