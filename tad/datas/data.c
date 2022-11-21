#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"

struct data
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

// 1 Cria, de maneira dinâmica, uma data a partir dos valores para dia, mês e ano fornecidos.
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
    Data* data = (Data*) malloc(sizeof(Data));

    if (data != NULL)
    {
        data->dia = dia;
        data->mes = mes;
        data->ano = ano;
    }
    
    return data;
}

// 2. Cria uma cópia da data d, retornando-a.
Data* copiaData(Data d)
{
    Data* data = criaData(d.dia, d.mes, d.ano);
    
    return data;
}

// 3. Destrói a data indicada por d.
void liberaData(Data* d)
{
    free(d);
}

// 6. Atribui, à data d, a data dia/mes/ano especificada.
void atribuirData(Data* d, unsigned int dia, unsigned int mes, unsigned int ano)
{
    if (d != NULL)
    {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    }
}

// 7. Retorna a componente dia da data d.
unsigned int obtemDiaData(Data d)
{
    return d.dia;
}

// 8. Retorna a componente mes da data d.
unsigned int obtemMesData(Data d)
{
    return d.mes;
}

// 9. Retorna a componente ano da data d.
unsigned int obtemAnoData(Data d)
{
    return d.ano;
}

// 10. Retorna TRUE se a data pertence a um ano bissexto. Do contrário, retorna FALSE.
unsigned int bissextoData(Data d)
{
    return (d.ano % 4 == 0) ? 1 : 0;
}


void exibaResultadoTrueFalse(unsigned int resultado)
{
    resultado == 1 ? printf("TRUE\n") : printf("FALSE\n"); 
}

int main()
{
    return 0;
}