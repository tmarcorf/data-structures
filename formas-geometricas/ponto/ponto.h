
// Definições

typedef struct ponto Ponto;

Ponto* criarPonto(float coordenadaX, float coordenadaY);

void liberarPonto(Ponto* ponto);

void acessarPonto(Ponto* ponto, float* coordenadaX, float* coordenadaY);

void atribuirPonto(Ponto* ponto, float coordenadaX, float coordenadaY);

float calcularDistanciaEntrePontos(Ponto* ponto1, Ponto* ponto2);