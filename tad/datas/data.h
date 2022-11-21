typedef struct data Data;

// 1 Cria, de maneira dinâmica, uma data a partir dos valores para dia, mês e ano fornecidos.
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano);

// 2. Cria uma cópia da data d, retornando-a.
Data* copiaData(Data d);

// 3. Destrói a data indicada por d.
void liberaData(Data* d);

// 4. Retorna uma data que é dias dias posteriores à data d.
Data* somaDiasData(Data d, unsigned int dias);

// 5. Retorna uma data que é dias dias anteriores à data d.
Data* subtrairDiasData(Data d, unsigned int dias);

// 6. Atribui, à data d, a data dia/mes/ano especificada.
void atribuirData(Data* d, unsigned int dia, unsigned int mes, unsigned int ano);

// 7. Retorna a componente dia da data d.
unsigned int obtemDiaData(Data d);

// 8. Retorna a componente mes da data d.
unsigned int obtemMesData(Data d);

// 9. Retorna a componente ano da data d.
unsigned int obtemAnoData(Data d);

// 10. Retorna TRUE se a data pertence a um ano bissexto. Do contrário, retorna FALSE.
unsigned int bissextoData(Data d);

// 11. Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2.
int comparaData(Data d1, Data d2);

// 12. Retorna o número de dias que existe entre as datas d1 e d2.
unsigned int numeroDiasDatas(Data d1, Data d2);

// 13. Se d1 e d2 estão no mesmo mês/ano, então o número de meses é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroMesesDatas(Data d1, Data d2);

// 14. Se d1 e d2 estão no mesmo ano, então o número de anos é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroAnosDatas(Data d1, Data d2);

// 15. Retorna o dia da semana correspodente à data d. Considerando que DOMINGO = 1; SEGUNDA-FEIRA = 2; ... ; SÁBADO = 7.
unsigned int obtemDiaSemanaData(Data d);

// 16. Retorna uma string com a data “formatada” de acordo com o especificado em formato.
char* imprimeData(Data d, char* formato);

// Funções acessórias
void exibaResultadoTrueFalse(unsigned int resultado);