#include <stdio.h>
#include <math.h>

void preenchaVetor(int* vetor, int tamanho, int numeroASerPreenchido);
void imprimaVetor(int* vetor, int tamanho);

int main()
{
    int tamanhoVetor, contador;
    long long int produtoVetor = 1;

    scanf("%d", &tamanhoVetor);

    int vetor[tamanhoVetor];

    for (contador = 0; contador < tamanhoVetor; contador++)
    {
        scanf("%d", &vetor[contador]);
        produtoVetor *= vetor[contador];
    }

    contador = 0;

    while (pow(contador, tamanhoVetor) <= produtoVetor)
    {
        contador++;
    }

    preenchaVetor(vetor, tamanhoVetor, contador);
    imprimaVetor(vetor, tamanhoVetor);

    return 0;
}

void preenchaVetor(int* vetor, int tamanho, int numeroASerPreenchido)
{
    int contador;

    for (contador = 0; contador < tamanho; contador++)
    {
        vetor[contador] = numeroASerPreenchido;
    }
}

void imprimaVetor(int* vetor, int tamanho)
{
    int contador;

    for (contador = 0; contador < tamanho; contador++)
    {
        printf("%d ", vetor[contador]);
    }
}