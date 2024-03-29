// TAD: Pilha
    // Adicionar os vagões na pilha começando do 1 e indo até N
    // A base da pilha será 1 e o topo, N.

// trilhos.h

typedef struct estacao Estacao;
typedef struct vagao Vagao;

// cria um elemento vagão.
Vagao* crieVagao(int chave);

// cria a pilha (estação) vazia.
Estacao* crieEstacaoVazia();

int estacaoEstaVazia(Estacao* estacao);

// Adiciona um vagao na pilha (estação)
void push(Estacao* estacao, Vagao* vagao);

// Remove um vagao da pilha (estação)
void pop(Estacao* estacao);

// Inverte a ordem da pilha (estação)
Estacao* invertaOrdemDosVagoes(Estacao* estacao);

void determineResultadoDaOrdemDosVagoes(Estacao* estacao, int* arrayDeChaves);

// trilhos.c

#include <stdio.h>
#include <stdlib.h>

#define SIM 1
#define NAO 0

struct estacao
{
    Vagao* base;
    Vagao* topo;
    int quantidadeVagoes;
};

struct vagao
{
    int chave;
    Vagao* proximo;
};

Vagao* crieVagao(int chave)
{
    Vagao* vagao = (Vagao*)malloc(sizeof(Vagao));

    if (vagao != NULL)
    {
        vagao->chave = chave;
        vagao->proximo = NULL;
    }
    
    return vagao;
}

Estacao* crieEstacaoVazia()
{
    Estacao* estacao = (Estacao*)malloc(sizeof(Estacao));

    if (estacao != NULL)
    {
        estacao->base = NULL;
        estacao->topo = NULL;
        estacao->quantidadeVagoes = 0;
    }
    
    return estacao;
}

int estacaoEstaVazia(Estacao* estacao)
{
    return (estacao->quantidadeVagoes == 0) ? SIM : NAO;
}

void push(Estacao* estacao, Vagao* vagao)
{
    if (estacao == NULL) return;

    if (estacaoEstaVazia(estacao))
    {
        estacao->base = vagao;
        estacao->topo = vagao;
    }
    else
    {
        estacao->topo->proximo = vagao;
        estacao->topo = vagao;  
    }

    estacao->quantidadeVagoes++;
}

void pop(Estacao* estacao)
{
    if (estacao == NULL || estacaoEstaVazia(estacao)) return;

    if (estacao->quantidadeVagoes == 1)
    {
        estacao->base = NULL;
        estacao->topo = NULL;
    }
    else
    {
        Vagao* iterator = estacao->base;

        while (iterator->proximo != estacao->topo)
        {
            iterator = iterator->proximo;
        }
        
        Vagao* topo = estacao->topo;
        iterator->proximo = NULL;
        estacao->topo = iterator;

        free(topo);
    }
    
    estacao->quantidadeVagoes--;
}

Estacao* invertaOrdemDosVagoes(Estacao* estacao)
{
    Estacao* estacaoVagoesInvertidos = crieEstacaoVazia();

    while (estacao->quantidadeVagoes != 0)
    {
        Vagao* topo = estacao->topo;
        Vagao* vagao = crieVagao(topo->chave);

        push(estacaoVagoesInvertidos, vagao);
        pop(estacao);
    }
    
    return estacaoVagoesInvertidos;
}

void determineResultadoDaOrdemDosVagoes(Estacao* estacao, int* arrayDeChaves)
{
    Vagao* iterator = estacao->base;
    int ehPossivel = SIM;

    int i;
    for (i = 0; i < estacao->quantidadeVagoes; i++)
    {
        if (iterator->chave != arrayDeChaves[i])
        {
            ehPossivel = NAO;
            break;
        }

        iterator = iterator->proximo;
    }
    
    (ehPossivel == SIM) ? printf("Yes\n") : printf("No\n");
}

// main.c

#include <stdio.h>

int main()
{   
    Estacao* estacao = crieEstacaoVazia();
    int quantidadeVagoes;

    scanf("%d", &quantidadeVagoes);

    // Limita a quantidade de vagões da estação em até 1000.
    if (quantidadeVagoes > 1000) return 0;

    int arrayDeChaves[quantidadeVagoes];

    // Lê a ordem que os vagões deverão sair da estação para comparação.
    int i;
    for (i = 0; i < quantidadeVagoes; i++)
    {
        Vagao* vagao = crieVagao(i + 1);
        push(estacao, vagao);

        scanf("%d", &arrayDeChaves[i]);
    }
    
    Estacao* estacaoVagoesInvertidos = invertaOrdemDosVagoes(estacao);
    determineResultadoDaOrdemDosVagoes(estacaoVagoesInvertidos, arrayDeChaves);

    return 0;
}
