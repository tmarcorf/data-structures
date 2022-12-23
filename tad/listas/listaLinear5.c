#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct digito 
{
  int valor;
  struct digito *proximo;
};

struct numero 
{
  struct digito *inicio;
  int tamanho;
  bool negativo;
};

void inicializar_numero(struct numero *n) 
{
  n->inicio = NULL;
  n->tamanho = 0;
  n->negativo = false;
}

void ler_numero(struct numero *n) 
{
  char c;

  c = getchar();
  if (c == '-') 
  {
    n->negativo = true;
  }
  else 
  {
    n->negativo = false;
    ungetc(c, stdin);
  }

  n->tamanho = 0;
  n->inicio = NULL;
  while ((c = getchar()) != '\n' && c != EOF) 
  {
    struct digito *novo = malloc(sizeof(struct digito));
    novo->valor = c - '0';
    novo->proximo = NULL;

    novo->proximo = n->inicio;
    n->inicio = novo;
    n->tamanho++;
  }
}

void exibir_numero(struct numero n) 
{
  if (n.negativo) 
  {
    printf("-");
  }

  struct digito *atual = n.inicio;
  while (atual != NULL) 
  {
    printf("%d", atual->valor);
    atual = atual->proximo;
  }
}

int main() {
  struct numero n1, n2;
  printf("Insira o primeiro número: ");
  ler_numero(&n1);
  printf("Insira o segundo número: ");
  ler_numero(&n2);

  printf("Soma: ");
  exibir_numero(n1);
  printf(" + ");
  exibir_numero(n2);
  printf(" = ");
  printf("\n");

  printf("Subtração: ");
  exibir_numero(n1);
  printf(" - ");
  exibir_numero(n2);
  printf(" = ");
  printf("\n");

  printf("Multiplicação: ");
  exibir_numero(n1);
  printf(" * ");
  exibir_numero(n2);
  printf(" = ");
  printf("\n");

  printf("Divisão inteira: ");
  exibir_numero(n1);
  printf(" / ");
  exibir_numero(n2);
  printf(" = ");
  printf("\n");

  return 0;
}