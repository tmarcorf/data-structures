#include <stdio.h>

void insertionSort(int* vetor, int tamanho);
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
    insertionSort(vetor, tamanho);

    return 0;
}

void insertionSort(int* vetor, int tamanho)
{
    int i, j, aux;

    i = 0;
    j = 1;
    aux = 0;

    while (j < tamanho)
    {
        aux = vetor[j];
        i = j - 1;

        while ((i >= 0) && (vetor[i] > aux))
        {
            vetor[i + 1] = vetor[i];
            i--;
        }
        
        vetor[i + 1] = aux;
        j++;

        imprimaVetor(vetor, tamanho);
    }
}

void imprimaVetor(int* vetor, int tamanho)
{
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("%d ", vetor[contador]);
    }
    
    printf("\n");
}
