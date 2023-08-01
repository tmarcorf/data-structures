// Definições

typedef struct cubo Cubo;

Cubo* criarCubo(float aresta);

void liberarCubo(Cubo* cubo);

float acessarCubo(Cubo* cubo);

void atribuirCubo(Cubo* cubo, float aresta);

float calcularArea(Cubo* cubo);

float calcularVolume(Cubo* cubo);