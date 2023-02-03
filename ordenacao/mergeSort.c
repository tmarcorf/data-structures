#include <stdio.h>

void mergeSort(int* vetor, int inicio, int fim);
void imprimaVetor(int* vetor, int tamanho);
void merge(int* vetor, int inicio, int meio, int fim);

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

void mergeSort(int* vetor, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
    
}

void merge(int* vetor, int inicio, int meio, int fim)
{
    int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[fim - inicio + 1];

    while ((com1 <= meio) && (com2 <= fim)) 
    {
        if (vetor[com1] <= vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else 
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }

        comAux++;
}

void imprimaVetor(int* vetor, int tamanho)
{
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("%d ", vetor[contador]);
    }
    
    printf("\n");
}
