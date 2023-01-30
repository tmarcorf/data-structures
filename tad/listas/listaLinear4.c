#include <stdio.h>
#include <stdlib.h>

struct elemento 
{
    int prioridade;
    struct elemento *proximo;
};

struct fila 
{
    struct elemento *inicio;
    struct elemento *fim;
};

void inicializar_fila(struct fila *f) 
{
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(struct fila *f, int prioridade) 
{
    struct elemento *novo = malloc(sizeof(struct elemento));
    novo->prioridade = prioridade;
    novo->proximo = NULL;


    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        struct elemento *atual = f->inicio;
        while (atual->proximo != NULL && atual->proximo->prioridade > prioridade) 
        {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

int remover(struct fila *f) 
{
    if (f->inicio == NULL) 
    {
        printf("Erro: a fila está vazia\n");
        exit(1);
    }

    int prioridade = f->inicio->prioridade;

    struct elemento *removido = f->inicio;
    f->inicio = f->inicio->proximo;
    free(removido);

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    return prioridade;
}

int vazia(struct fila *f) 
{
  return (f->inicio == NULL) ? 1 : 0;
}

int main() 
{
  
    struct fila f;
    inicializar_fila(&f);

    int n;
    printf("Insira o número de elementos a serem inseridos na fila: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int prioridade;
        printf("Insira o elemento com prioridade: ");
        scanf("%d", &prioridade);
        inserir(&f, prioridade);
    }

    printf("Elementos da fila (do primeiro ao último):\n");
    while (!vazia(&f)) {
        int prioridade = remover(&f);
        printf("%d\n", prioridade);
    }

    return 0;
}

