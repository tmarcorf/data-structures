// Definições

typedef struct cilindro Cilindro;

Cilindro* criarCilindro(float altura, float raio);

void liberarCilindro(Cilindro* cilindro);

void acessarCilindro(Cilindro* cilindro, float* altura, float* raio);

void atribuirCilindro(Cilindro* cilindro, float altura, float raio);

float obterAltura(Cilindro* cilindro);

float obterRaio(Cilindro* cilindro);

float calcularAreaDaBase(Cilindro* cilindro);

float calcularVolume(Cilindro* cilindro);