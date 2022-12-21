#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10  

int vetor[TAMANHO_VETOR];  
int quantidadeElementos = 0;  

void criarLista() {
    for (int count = 0; count < TAMANHO_VETOR; count++)
    {
        vetor[count] = 0;
    }
    
    quantidadeElementos = 0;
}

void inserirNoFinal(int x) {
    if (x == 0)
    {
        return;
    }
    
    if (quantidadeElementos < TAMANHO_VETOR) {
        vetor[quantidadeElementos] = x;
        quantidadeElementos++;
    }
}

void inserirNoComeco(int x) {
    if (quantidadeElementos < TAMANHO_VETOR) {
        for (int i = quantidadeElementos; i > 0; i--) {
            vetor[i] = vetor[i - 1];
        }
        vetor[0] = x;
        quantidadeElementos++;
    }
}

void removerDoFinal() {
    if (quantidadeElementos > 0) {
        quantidadeElementos--;
    }
}

void removerDoComeco() {
    if (quantidadeElementos > 0) {
        for (int i = 0; i < quantidadeElementos - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        quantidadeElementos--;
    }
}

void imprimirLista() {
    for (int i = 0; i < quantidadeElementos; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void imprimirTamanho() {
    printf("%d\n", quantidadeElementos);
}

void imprimirPrimeiroElemento() {
    if (quantidadeElementos > 0) {
        printf("%d\n", vetor[0]);
    }
}

void imprimirUltimoElemento() {
    if (quantidadeElementos > 0) {
        printf("%d\n", vetor[quantidadeElementos - 1]);
    }
}

int main() {
    criarLista();
    inserirNoFinal(1);
    inserirNoFinal(2);
    inserirNoComeco(3);
    inserirNoComeco(4);
    removerDoFinal();
    removerDoComeco();
    imprimirLista();
    imprimirTamanho();
    imprimirPrimeiroElemento();
    imprimirUltimoElemento();
    return 0;
}