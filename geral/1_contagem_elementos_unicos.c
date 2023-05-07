#include <stdio.h>

void preenchaVetor(int* vetor, int tamanho);
int elementoEhUnicoNoVetor(int elemento, int* vetor, int tamanho);

int main()
{
    int n, quantidadeElementosUnicos = 0;
    scanf("%d", &n);

    int vetor[n];

    preenchaVetor(vetor, n);

    for (int contador = 0; contador < n; contador++)
    {
        if (elementoEhUnicoNoVetor(vetor[contador], vetor, n) == 1)
        {
            quantidadeElementosUnicos++;
        }
    }

    printf("%d\n", quantidadeElementosUnicos);
    
    return 0;
}

void preenchaVetor(int* vetor, int tamanho)
{
    if(tamanho >= 5000) return;

    for(int contador = 0; contador < tamanho; contador++)
    {
        scanf("%d", &vetor[contador]);
    }
}

int elementoEhUnicoNoVetor(int elemento, int* vetor, int tamanho)
{
    int quantidadeAparicoes = 0;

    for(int contador = 0; contador < tamanho; contador++)
    {
        if (elemento == vetor[contador])
        {
            quantidadeAparicoes++;
        }
    }

    return quantidadeAparicoes == 1 ? 1 : 0;
}