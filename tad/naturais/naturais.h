// Definições 

// SUCESSO = 1; FALHA = 0;
// TRUE = 1; FALSE = 0;
// CRESCENTE = 1; DECRESCENTE = 0;

typedef struct conjunto Conjunto;

// 1. criar um conjunto C, inicialmente vazio
int criaConjunto(Conjunto* conjunto, int codigo);

// 2. verificar se o conjunto C é vazio:
int conjuntoVazio(Conjunto* conjunto);

// 3. incluir o elemento x no conjunto C:
int insereElementoConjunto(int x, Conjunto* conjunto);

// 4. excluir o elemento x do conjunto C:
int excluirElementoConjunto(int x, Conjunto* conjunto);

// 5. calcular a cardinalidade do conjunto C
int tamanhoConjunto(Conjunto* conjunto);

// 6. determinar a quantidade de elementos do conjunto C que são maiores que x:
int maior(int x, Conjunto* conjunto);

// 7. determinar a quantidade de elementos do conjunto C que são menores que x:
int menor(int x, Conjunto* conjunto);

// 8. verificar se o elemento x pertence ao conjunto C:
int pertenceConjunto(int x, Conjunto* conjunto);

// 9. comparar se dois conjuntos, C1 e C2 são idênticos:
int conjuntosIdenticos(Conjunto* conjunto1, Conjunto* conjunto2);

// 10. identificar se o conjunto C1 é subconjunto do conjunto C2:
int subconjunto(Conjunto* conjunto1, Conjunto* conjunto2);

// 11. gerar o complemento do conjunto C1 em relação ao conjunto C2:
Conjunto* complemento(Conjunto* conjunto1, Conjunto* conjunto2);

// 12. gerar a união do conjunto C1 com o conjunto C2:
Conjunto* uniao(Conjunto* conjunto1, Conjunto* conjunto2);

// 13. gerar a intersecção do conjunto C1 com o conjunto C2:
Conjunto* interseccao(Conjunto* conjunto1, Conjunto* conjunto2);

// 14. gerar a diferença entre o conjunto C1 e o conjunto C2:
Conjunto* diferenca(Conjunto* conjunto1, Conjunto* conjunto2);

// 15. gerar o conjunto das partes do conjunto C:
Conjunto* conjuntoPartes(Conjunto* conjunto);

// 16. mostrar os elementos presentes no conjunto C:
void mostraConjunto(Conjunto* conjunto, int ordem);

// 17. copiar o conjunto C1 para o conjunto C2:
int copiarConjunto(Conjunto* conjunto1, Conjunto* conjunto2);

// 18. destruir o conjunto C:
int destroiConjunto(Conjunto* conjunto);

// Funções acessórias
void exibaResultadoSucessoFalha(int resultado);

void exibaResultadoTrueFalse(int resultado);