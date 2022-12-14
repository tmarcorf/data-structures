#include <stdio.h>

int numeroEhPrimo(int numero);
int obtenhaNumeroPrimoPelaOrdem(int ordem);
void imprimaNumerosPrimos(int *vetorDeOrdem, int tamanho);
void ordeneVetor(int V[], int tam);
int somaVetorRecursivo(int vetor[], int tam);

int main()
{
    int tamanhoVetor;
    scanf("%d", &tamanhoVetor);

    int vetorDeOrdem[tamanhoVetor];

    for (int count = 0; count < tamanhoVetor; count++)
    {
        scanf("%d", &vetorDeOrdem[count]);
    }

    imprimaNumerosPrimos(vetorDeOrdem, tamanhoVetor);

    return 0;
}

void imprimaNumerosPrimos(int *vetorDeOrdem, int tamanho)
{
    int vetorSoma[tamanho];

    ordeneVetor(vetorDeOrdem, tamanho);

    for (int count = 0; count < tamanho; count++)
    {
        int numeroPrimo = obtenhaNumeroPrimoPelaOrdem(vetorDeOrdem[count]);

        printf("%d ", numeroPrimo);
        vetorSoma[count] = numeroPrimo;
    }

    printf("\n");
    printf("%d\n", somaVetorRecursivo(vetorSoma, tamanho));
}

int obtenhaNumeroPrimoPelaOrdem(int ordem)
{
    int count = 0;
    int numero = 0;

    while (count != ordem)
    {
        numero++;

        if (numeroEhPrimo(numero) == 1)
        {
            count++;
        }
    }

    return numero;
}

int numeroEhPrimo(int numero)
{
    int count = numero;
    int contadorDeDivisaoExata = 0;

    for (count; count >= 1; count--)
    {
        if (numero % count == 0)
        {
            contadorDeDivisaoExata++;
        }
    }

    return (contadorDeDivisaoExata == 2) ? 1 : 0;
}

void ordeneVetor(int V[], int tam)
{    
  int i, j, aux; 
 
  for(i = 1; i > tam; i++){ 
    j = i; 
 
    while((j != 0) && (V[j] > V[j - 1])) { 
      aux = V[j]; 
      V[j] = V[j - 1]; 
      V[j - 1] = aux; 
      j--;     
    } 
  } 
}

int somaVetorRecursivo(int vetor[], int tam){
    if(tam == 0) 
        return 0;
    else
        return vetor[tam - 1] + somaVetorRecursivo(vetor, tam - 1);
}