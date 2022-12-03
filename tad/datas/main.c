#include "data.c"

void exibaMenu();
void pularLinha();
void executeFuncaoEspecifica(int opcaoEscolhida);
void limparTela();
Data* obtenhaData();
void exibaDiaDaSemana(unsigned int diaDaSemana);

int main()
{
    int opcaoEscolhida;

    limparTela();

    do
    {
        exibaMenu();
        scanf("%d", &opcaoEscolhida);

        limparTela();

        if (opcaoEscolhida >= 0 && opcaoEscolhida <= 16)
        {
            executeFuncaoEspecifica(opcaoEscolhida);
        }
        

    } while (opcaoEscolhida != 0);
    
    printf("=================== FIM DO PROGRAMA ====================\n");
    pularLinha();

    return 0;
}

void executeFuncaoEspecifica(int opcaoEscolhida)
{
    Data* data1;
    Data* data2;
    unsigned int diasSomarSubtrair;
    unsigned int dia, mes, ano;
    char formatoData[6];

    switch (opcaoEscolhida)
    {
        case 1:
            printf("1 - Criar data\n");
            data1 = obtenhaData();

            printf("Data criada: ");
            imprimeData(*data1, "ddmmaaaa");

            break;
        case 2:
            printf("2 - Copiar data\n");
            data1 = obtenhaData();
            data2 = copiaData(*data1);

            printf("Data copiada: ");
            imprimeData(*data2, "ddmmaaaa");

            break;
        case 3:
            printf("3 - Liberar data\n");
            data1 = obtenhaData();

            liberaData(data1);

            printf("A data foi destruida\n");

            break;
        case 4:
            printf("4 - Somar dias na data\n");
            data1 = obtenhaData();

            printf("Informe a quantidade de dias: ");
            scanf("%u", &diasSomarSubtrair);

            data2 = somaDiasData(*data1, diasSomarSubtrair);

            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data com os dias somados: ");
            imprimeData(*data2, "ddmmaaaa");

            break;
        case 5:
            printf("5 - Subtrair dias na data\n");
            data1 = obtenhaData();

            printf("Informe a quantidade de dias: ");
            scanf("%u", &diasSomarSubtrair);

            data2 = subtrairDiasData(*data1, diasSomarSubtrair);

            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data com os dias subtraidos: ");
            imprimeData(*data2, "ddmmaaaa");

            break;
        case 6:
            printf("6 - Atribuir valores a uma data\n");
            data1 = obtenhaData();

            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Informe os novos dados (dia, mes, ano):\n");
            scanf("%u", &dia);
            scanf("%u", &mes);
            scanf("%u", &ano);      
            
            atribuirData(data1, dia, mes, ano);

            printf("Data com os novos valores: ");
            imprimeData(*data1, "ddmmaaaa");

            break;
        case 7:
            printf("7 - Obter o dia da data\n");
            data1 = obtenhaData();
            
            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            dia = obtemDiaData(*data1);

            if (dia < 10)
            {
                printf("Dia da data: 0%u\n", dia);
            }
            else
            {
                printf("Dia da data: %u\n", dia);
            }

            break;
        case 8:
            printf("8 - Obter o mes da data\n");
            data1 = obtenhaData();
            
            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            mes = obtemMesData(*data1);

            if (mes < 10)
            {
                printf("Mes da data: 0%u\n", mes);
            }
            else
            {
                printf("Mes da data: %u\n", mes);
            }
            
            break;
        case 9:
            printf("9 - Obter o ano da data\n");
            data1 = obtenhaData();
            
            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            ano = obtemAnoData(*data1);

            printf("Ano da data: %u\n", ano);
            
            break;
        case 10:
            printf("10 - Verificar se o ano da data e bissexto\n");
            data1 = obtenhaData();
            
            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            exibaResultadoTrueFalse(bissextoData(*data1));
            
            break;
        case 11:
            printf("11 - Comparar duas datas\n");
            data1 = obtenhaData();
            data2 = obtenhaData();
            
            printf("Data informada 1: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data informada 2: ");
            imprimeData(*data2, "ddmmaaaa");

            exibaResultadoMenorIgualMaior(comparaData(*data1, *data2));
            
            break;
        case 12:
            printf("12 - Numero de dias entre uma data e outra\n");
            data1 = obtenhaData();
            data2 = obtenhaData();
            
            printf("Data informada 1: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data informada 2: ");
            imprimeData(*data2, "ddmmaaaa");

            dia = numeroDiasDatas(*data1, *data2);

            printf("Dias entre data 1 e data 2: %u\n", dia);
            
            break;
        case 13:
            printf("13 - Numero de meses entre uma data e outra\n");
            data1 = obtenhaData();
            data2 = obtenhaData();
            
            printf("Data informada 1: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data informada 2: ");
            imprimeData(*data2, "ddmmaaaa");

            mes = numeroMesesDatas(*data1, *data2);

            printf("Meses entre data 1 e data 2: %u\n", mes);
            
            break;
        case 14:
            printf("14 - Numero de anos entre uma data e outra\n");
            data1 = obtenhaData();
            data2 = obtenhaData();
            
            printf("Data informada 1: ");
            imprimeData(*data1, "ddmmaaaa");

            printf("Data informada 2: ");
            imprimeData(*data2, "ddmmaaaa");

            ano = numeroAnosDatas(*data1, *data2);

            printf("Anos entre data 1 e data 2: %u\n", ano);
            
            break;
        case 15:
            printf("15 - Obter o dia da semana\n");
            data1 = obtenhaData();
            
            printf("Data informada: ");
            imprimeData(*data1, "ddmmaaaa");

            exibaDiaDaSemana(obtemDiaSemanaData(*data1));
            
            break;
        case 16:
            printf("16 - Imprimir uma data\n");
            data1 = obtenhaData();
            
            printf("Digite o formato da data:\n");
            scanf("%s", &formatoData);

            printf("Formato: %s\n", formatoData);

            imprimeData(*data1, formatoData);
            
            break;
        default:
            break;
    }
}

void exibaMenu()
{
    pularLinha();

    printf("======================== MENU ========================\n");
    
    pularLinha();
    printf("Selecione uma das opcoes abaixo ou 0 (zero) para sair:\n");
    pularLinha();

    printf("1 - Criar data\n");
    printf("2 - Copiar data\n");
    printf("3 - Liberar data\n");
    printf("4 - Somar dias na data\n");
    printf("5 - Subtrair dias na data\n");
    printf("6 - Atribuir valores a uma data\n");
    printf("7 - Obter o dia da data\n");
    printf("8 - Obter o mes da data\n");
    printf("9 - Obter o ano da data\n");
    printf("10 - Verificar se o ano da data e bissexto\n");
    printf("11 - Comparar duas datas\n");
    printf("12 - Numero de dias entre uma data e outra\n");
    printf("13 - Numero de meses entre uma data e outra\n");
    printf("14 - Numero de anos entre uma data e outra\n");
    printf("15 - Obter o dia da semana\n");
    printf("16 - Imprimir uma data\n");

    pularLinha();
}

void pularLinha()
{
    printf("\n");
}

void limparTela()
{
    system("cls");
}

Data* obtenhaData()
{
    Data* data;
    unsigned int dia, mes, ano;

    printf("Informe dia, mes e ano:\n");

    scanf("%u", &dia);
    scanf("%u", &mes);
    scanf("%u", &ano);

    data = criaData(dia, mes, ano);

    return data;
}

void exibaDiaDaSemana(unsigned int diaDaSemana)
{
    switch (diaDaSemana)
    {
        case SABADO:
            printf("SABADO\n");
            break;
        case DOMINGO:
            printf("DOMINGO\n");
            break;
        case SEGUNDA:
            printf("SEGUNDA-FEIRA\n");
            break;
        case TERCA:
            printf("TERCA-FEIRA\n");
            break;
        case QUARTA:
            printf("QUARTA-FEIRA\n");
            break;
        case QUINTA:
            printf("QUINTA-FEIRA\n");
            break;
        case SEXTA:
            printf("SEXTA-FEIRA\n");
            break;
        default:
            break;
    }
}
