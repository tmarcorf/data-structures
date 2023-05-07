#include <stdio.h>
#define SEM_ACESSO -1

void preenchaVetor(int* vetor, int tamanho);
void atualizeLinhaOuColuna(int indice, int linha, int coluna, int valor);

int main()
{
    int distanciaTotal = 0;

    // Carregar a matriz com as distâncias das cidades.
    int matrizDistancias[6][6] = {{0, 63, 210, 190, -1, 190},
                                  {63, 0, 160, 150, 95, 10},
                                  {210, 160, 0, 10, 1, 10},
                                  {190, 150, 10, 0, 10, 20},
                                  {10, 95, 7, 21, 0, 80},
                                  {190, 2, -1, 41, 80, 0}};


    // Ler um inteiro com o tamanho da rota.
    int tamanhoRota;
    scanf("%d", &tamanhoRota);

    // Ler o vetor com os números das cidades que estarão na rota.
    int vetorRota[tamanhoRota];
    preenchaVetor(vetorRota, tamanhoRota);

    // Percorrer a matriz das distâncias com base nesse vetor e ir incrementando na distância total.

    int linhaCidade = vetorRota[0], colunaCidade = vetorRota[1];

    for (int i = 0; i < tamanhoRota - 1; i++)
    {
        // Alterando o valor das linhas e colunas de acordo com a rota estabelecida.
        if (i > 0)
        {
            if (i % 2 == 0)
            {
                colunaCidade = vetorRota[i+1];
            }
            else
            {
                linhaCidade = vetorRota[i+1];
            }
        }

        if (matrizDistancias[linhaCidade][colunaCidade] == SEM_ACESSO)
        {
            printf("rota invalida!\n");
            break;
        }

        distanciaTotal += matrizDistancias[linhaCidade][colunaCidade];

        if (i == (tamanhoRota - 2))
        {
            printf("%d\n", distanciaTotal);
        }
    }
    
    return 0;
}

void preenchaVetor(int* vetor, int tamanho)
{
    if(tamanho < 2) return;

    for(int contador = 0; contador < tamanho; contador++)
    {
        scanf("%d", &vetor[contador]);
    }
}

void atualizeLinhaOuColuna(int indice, int linha, int coluna, int valor)
{
    
}