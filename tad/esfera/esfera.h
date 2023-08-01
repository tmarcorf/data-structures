// Definições

typedef struct esfera Esfera;

Esfera* criarEsfera(float raio);

void liberarEsfera(Esfera* esfera);

float acessarEsfera(Esfera* esfera, float* raio);

void atribuirEsfera(Esfera* esfera, float raio);

float obterRaio(Esfera* esfera);

float calcularArea(Esfera* esfera);

float calcularVolume(Esfera* esfera);