#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "esfera.h"

#define PI 3.1415926

// Implementações

struct esfera
{
    float raio;
};

Esfera* criarEsfera(float raio)
{
    Esfera* esfera = (Esfera*) malloc(sizeof(Esfera));
    
    if (esfera != NULL)
    {
        esfera->raio = raio;
    }
    
    return esfera;
}

void liberarEsfera(Esfera* esfera)
{
    free(esfera);
}

float acessarEsfera(Esfera* esfera, float* raio)
{
     *raio = esfera->raio;
}

void atribuirEsfera(Esfera* esfera, float raio)
{
    if (esfera != NULL)
    {
        esfera->raio = raio;
    }
}

float obterRaio(Esfera* esfera)
{
    return esfera->raio;
}

float calcularArea(Esfera* esfera)
{
    return 4 * PI * pow(esfera->raio, 2);
}

float calcularVolume(Esfera* esfera)
{
    return (4 * PI * pow(esfera->raio, 3)) / 3;
}

int main()
{
    float areaDaEsfera, volumeDaEsfera;
    Esfera* esfera;

    esfera = criarEsfera(6.5);

    areaDaEsfera = calcularArea(esfera);
    volumeDaEsfera = calcularVolume(esfera);

    printf("Area da esfera: %f\n", areaDaEsfera);
    printf("Volume da esfera: %f\n", volumeDaEsfera);

    return 0;
}
