#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "data.h"

// Dias da semana

#define DOMINGO 1
#define SEGUNDA 2
#define TERCA 3
#define QUARTA 4
#define QUINTA 5
#define SEXTA 6
#define SABADO 7

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

// 4. Retorna uma data que é dias dias posteriores à data d.
Data* somaDiasData(Data d, unsigned int dias)
{
    Data* dataRetorno;
    int count;

    for (count = 1; count <= dias; count++)
    {
        d = adicioneDiaNaData(d);
    }
    
    dataRetorno = criaData(d.dia, d.mes, d.ano);
    
    return dataRetorno;
}

// 5. Retorna uma data que é dias dias anteriores à data d.
Data* subtrairDiasData(Data d, unsigned int dias)
{
    Data* dataRetorno;
    int count = 1;

    for (count; count <= dias; count++)
    {
        int quantidadeDiasDoMes = obtenhaQuantidadeDeDiasDoMes(d);

        if (d.dia == 1)
        {
            if (d.mes == 1)
            {
                d.dia = 31;
                d.mes = 12;
                d.ano--;
            }
            else
            {
                d.mes--;
                d.dia = obtenhaQuantidadeDeDiasDoMes(d);
            }
        }
        else
        {
            d.dia--;
        }
    }

    dataRetorno = criaData(d.dia, d.mes, d.ano);
    
    return dataRetorno;
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

// 11. Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2.
int comparaData(Data d1, Data d2)
{
    if (d1.ano == d2.ano)
    {
        if (d1.mes == d2.mes)
        {
            if (d1.dia == d2.dia)
            {
                return 0;
            }
            else if(d1.dia < d2.dia)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if(d1.mes < d2.mes)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if(d1.ano < d2.ano)
    {
        return -1;
    }
    else 
    {
        return 1;
    }
}

// 12. Retorna o número de dias que existe entre as datas d1 e d2.
unsigned int numeroDiasDatas(Data d1, Data d2)
{
    if (comparaData(d1, d2) == 0)
    {
        return 0;
    }

    unsigned int quantidadeDeDias = 0;

    do
    {
        d1 = adicioneDiaNaData(d1);
        quantidadeDeDias++;
    }
    while (comparaData(d1, d2) != 0);
    
    return quantidadeDeDias;
}

// 13. Se d1 e d2 estão no mesmo mês/ano, então o número de meses é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroMesesDatas(Data d1, Data d2)
{
    if (d1.mes == d2.mes)
    {
        return 0;
    }
    
    unsigned int quantidadeMeses = 0;

    for (d1.mes; d1.mes < d2.mes; d1.mes++)
    {
        quantidadeMeses++;
    }
    
    return quantidadeMeses;
}

// 14. Se d1 e d2 estão no mesmo ano, então o número de anos é igual a 0 (zero). Do contrário, será um número estritamente positivo.
unsigned int numeroAnosDatas(Data d1, Data d2)
{
    if (d1.ano == d2.ano)
    {
        return 0;
    }
    
    unsigned int quantidadeAnos = 0;

    for (d1.ano; d1.ano < d2.ano; d1.ano++)
    {
        quantidadeAnos++;
    }
    
    return quantidadeAnos;
}

// 15. Retorna o dia da semana correspodente à data d. Considerando que DOMINGO = 1; SEGUNDA-FEIRA = 2; ... ; SÁBADO = 7.
unsigned int obtemDiaSemanaData(Data d)
{
    unsigned int diaDaSemana, k, j;

    if (d.mes < 3)
    {
        d.mes += 12;
        d.ano--;
    }
    
    k = d.ano % 100;
    j = d.ano / 100;
    diaDaSemana = (d.dia + (((d.mes + 1) * 26) / 10) + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    switch (diaDaSemana)
    {
        case 0:
            return SABADO;
        case 1:
            return DOMINGO;
        case 2:
            return SEGUNDA;
        case 3:
            return TERCA;
        case 4:
            return QUARTA;
        case 5:
            return QUINTA;
        case 6:
            return SEXTA;
        default:
            break;
    }

    return 0;
}

// 16. Retorna uma string com a data “formatada” de acordo com o especificado em formato.
void imprimeData(Data d, char* formato)
{
    char* diaMesAno = "ddmmaaaa";
    char* anoMesDia = "aaaammdd";
    char* ano = "aaaa";
    char* mes = "mm";
    char* dia = "dd";
    char* diaMes = "ddmm";

    if (strncmp(formato, diaMesAno, 6) == 0)
    {
        if (d.dia < 10 && d.mes < 10)
        {
            printf("0%u/0%u/%u\n", d.dia, d.mes, d.ano);
            return;
        }
        else if (d.dia < 10 && d.mes >= 10)
        {
            printf("0%u/%u/%u\n", d.dia, d.mes, d.ano);
            return;
        }
        else if (d.dia >= 10 && d.mes < 10)
        {
            printf("%u/0%u/%u\n", d.dia, d.mes, d.ano);
            return;
        }
        
        printf("%u/%u/%u\n", d.dia, d.mes, d.ano);
    }
    else if (strncmp(formato, anoMesDia, 6) == 0)
    {
        if (d.dia < 10 && d.mes < 10)
        {
            printf("%u/0%u/0%u\n", d.ano, d.mes, d.dia);
            return;
        }
        else if (d.dia < 10 && d.mes >= 10)
        {
            printf("%u/%u/0%u\n", d.ano, d.mes, d.dia);
            return;
        }
        else if (d.dia >= 10 && d.mes < 10)
        {
            printf("%u/0%u/%u\n", d.ano, d.mes, d.dia);
            return;
        }

        printf("%u/%u/%u\n", d.ano, d.mes, d.dia);
    }
    else if (strncmp(formato, ano, 4) == 0)
    {
        printf("%u\n", d.ano);
    }
    else if (strncmp(formato, diaMes, 4) == 0)
    {
        if (d.dia < 10 && d.mes < 10)
        {
            printf("0%u/0%u\n", d.dia, d.mes);
            return;
        }
        else if (d.dia < 10 && d.mes >= 10)
        {
            printf("0%u/%u\n", d.dia, d.mes);
            return;
        }
        else if (d.dia >= 10 && d.mes < 10)
        {
            printf("%u/0%u\n", d.dia, d.mes);
            return;
        }

        printf("%u/%u\n", d.dia, d.mes);
    }
    else if (strncmp(formato, mes, 2) == 0)
    {
        if (d.mes < 10)
        {
            printf("0%u\n", d.mes);
            return;
        }

        printf("%u\n", d.mes);
    }
    else if (strncmp(formato, dia, 2) == 0)
    {
        if (d.dia < 10)
        {
            printf("0%u\n", d.dia);
            return;
        }

        printf("%u\n", d.dia);
    }
}

// Funções acessórias
void exibaResultadoTrueFalse(unsigned int resultado)
{
    resultado == 1 ? printf("TRUE\n") : printf("FALSE\n"); 
}

void exibaResultadoMenorIgualMaior(unsigned int resultado)
{
    switch (resultado)
    {
        case -1:
            printf("MENOR\n");
            break;
        case 0:
            printf("IGUAL\n");
            break;
        case 1:
            printf("MAIOR\n");
            break;
        default:
            break;
    }   
}

unsigned int obtenhaQuantidadeDeDiasDoMes(Data d)
{
    unsigned int dias = 31;

    switch (d.mes)
    {
        case 2:
            if (bissextoData(d) == 1)
            {
                dias -= 2;
            }
            else
            {
                dias -= 3;
            }
            break;
        case 4: case 6: case 9: case 11:
            dias--;
            break;
        default:
            break;
    }

    return dias;
}

Data adicioneDiaNaData(Data d)
{
    int quantidadeDiasDoMes = obtenhaQuantidadeDeDiasDoMes(d);

    if (d.dia == quantidadeDiasDoMes)
    {
        if (d.mes == 12)
        {
            d.dia = 1;
            d.mes = 1;
            d.ano++;
        }
        else
        {
            d.dia = 1;
            d.mes++;
        }
    }
    else
    {
        d.dia++;
    }

    return d;
}

