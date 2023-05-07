#include <stdio.h>

void bubbleSort(int* vetor, int tamanho);
void troca(int* a, int* b);
void imprimaVetor(int* vetor, int tamanho);

int main()
{
    int tamanho = 8;
    int vetor[tamanho];

    vetor[0] = 8;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 6;
    vetor[4] = 7;
    vetor[5] = 1;
    vetor[6] = 5;
    vetor[7] = 4;

    imprimaVetor(vetor, tamanho);
    bubbleSort(vetor, tamanho);

    return 0;
}

void bubbleSort(int* vetor, int tamanho)
{
    int i, fim;

    for (fim = (tamanho - 1); (fim > 0); fim--)
    {
        for (i = 0; (i < fim); i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                troca(&vetor[i], &vetor[i + 1]);
            }
        }

        imprimaVetor(vetor, tamanho);
    }
}

void troca(int* a, int* b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void imprimaVetor(int* vetor, int tamanho)
{
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("%d ", vetor[contador]);
    }
    
    printf("\n");
}
