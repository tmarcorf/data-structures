#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 10

int* criarPilha();
int* empilhar(int* pilha, int valor);
int desempilhar(int* pilha);
int estaVazia(int* pilha);
int obtenhaTamanhoDaPilha(int* pilha);
int* removeChave(int* pilha, int valor);
void imprimePilha(int* pilha);

int main()
{
    int* pilha = criarPilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    empilhar(pilha, 4);
    empilhar(pilha, 5);
    empilhar(pilha, 6);
    empilhar(pilha, 7);

    imprimePilha(pilha);

    removeChave(pilha, 3);
    imprimePilha(pilha);

    desempilhar(pilha);
    desempilhar(pilha);
    imprimePilha(pilha);
    
    return 0;
}

int* criarPilha()
{
    int* pilha = malloc(TAM_PILHA * (sizeof(int)));

    for (int count = 0; count < TAM_PILHA; count++)
    {
        pilha[count] = 0;
    }

    return pilha;
}

int* empilhar(int* pilha, int valor)
{
    int tamanho = obtenhaTamanhoDaPilha(pilha);
    
    if (tamanho == TAM_PILHA)
    {
        printf("A pilha atingiu o tamanho máximo!\n");

        return pilha;
    }
    
    if (estaVazia(pilha) == 1)
    {
        pilha[0] = valor;
    }
    
    pilha[tamanho] = valor;

    return pilha;
}

int desempilhar(int* pilha)
{
    if (estaVazia(pilha) == 1)    
    {
        printf("A pilha está vazia!\n");

        return 0;
    }

    int tamanho = obtenhaTamanhoDaPilha(pilha);

    int numeroTopoDaPilha = pilha[tamanho - 1];
    pilha[tamanho - 1] = 0;

    return numeroTopoDaPilha;
}

int estaVazia(int* pilha)
{
    int tamanho = obtenhaTamanhoDaPilha(pilha);

    return (tamanho == 0) ? 1 : 0;
}

int obtenhaTamanhoDaPilha(int* pilha)
{
    int count = 0;

    while (pilha[count] != 0)
    {
        count++;
    }
    
    return count;
}

int* removeChave(int* pilha, int valor)
{
    int* pilhaAux = criarPilha();
    int indiceParaReempilhar;

    int tamanho = obtenhaTamanhoDaPilha(pilha);

    for (int count = (tamanho - 1); count >= 0; count--)
    {
        if (pilha[count] != valor)
        {
            int elementoParaReempilhar = desempilhar(pilha);
            pilhaAux = empilhar(pilhaAux, elementoParaReempilhar);
        }
        else
        {
            indiceParaReempilhar = count;
            pilha[count] = 0;
            break;
        }
    }
    
    int tamanhoPilhaAux = obtenhaTamanhoDaPilha(pilhaAux);

    for (int count = (tamanhoPilhaAux - 1); count >= 0; count--)
    {
        pilha = empilhar(pilha, pilhaAux[count]);
    }
    
    return pilha;
}

void imprimePilha(int* pilha)
{
    int tamanho = obtenhaTamanhoDaPilha(pilha);

    printf("===================================\n");
    printf("Quantidade de elementos na pilha: %d\n", tamanho);
    printf("Elementos da pilha:\n");

    for (int count = (tamanho - 1); count >= 0; count--)
    {
        printf("%d\n", pilha[count]);
    }
}
