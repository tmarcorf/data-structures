#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cilindro.h"

#define PI 3.14159265

// Implementações

struct cilindro
{
    float altura;
    float raio;
};

Cilindro* criarCilindro(float altura, float raio)
{
    Cilindro* cilindro = (Cilindro*) malloc(sizeof(Cilindro));
    
    if (cilindro != NULL)
    {
        cilindro->altura = altura;
        cilindro->raio = raio;
    }
    
    return cilindro;
}

void liberarCilindro(Cilindro* cilindro)
{
    if (cilindro != NULL)
    {
        free(cilindro);
    }
}

void acessarCilindro(Cilindro* cilindro, float* altura, float* raio)
{
    *altura = cilindro->altura;
    *raio = cilindro->raio;
}

void atribuirCilindro(Cilindro* cilindro, float altura, float raio)
{
    if (cilindro != NULL)
    {
        cilindro->altura = altura;
        cilindro->raio = raio;
    }
}

float obterAltura(Cilindro* cilindro)
{
    if (cilindro != NULL)
    {
        return cilindro->altura;
    }
}

float obterRaio(Cilindro* cilindro)
{
    if (cilindro != NULL)
    {
        return cilindro->raio;
    }
}

float calcularAreaDaBase(Cilindro* cilindro)
{
    return PI * pow(cilindro->raio, 2);
}

float calcularVolume(Cilindro* cilindro)
{
    float areaDaBase = PI * pow(cilindro->raio, 2);
    float volume = areaDaBase * cilindro->altura;
    
    return volume;
}

int main()
{
    float altura, raio, areaDaBase, volume;
    Cilindro* cilindro;
    
    cilindro = criarCilindro(8.0, 2.5);
    altura = obterAltura(cilindro);
    raio = obterRaio(cilindro);
    areaDaBase = calcularAreaDaBase(cilindro);
    volume = calcularVolume(cilindro);
    
    printf("A altura do cilindro eh: %f\n", altura);
    printf("O raio do cilindro eh: %f\n", raio);
    printf("A area da base do cilindro eh: %f\n", areaDaBase);
    printf("O volume do cilindro eh: %f\n", volume);

    return 0;
}
