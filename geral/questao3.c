#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caracterEhUmaVogal(char caracter);

int main()
{
    char casosDeTesteStr[100];
    int casosDeTeste;
    int contador = 0;
    int contadorDeVogais = 0;
    char string[10000];
    int i;

    fgets(casosDeTesteStr, 100, stdin);
    casosDeTeste = atoi(casosDeTesteStr);

    while (contador < casosDeTeste)
    {
        fgets(string, 10000, stdin);
        int tamanhoString = strlen(string);
        
        for (i = 0; i < tamanhoString; i++)
        {
            if (caracterEhUmaVogal(string[i]) == 1)
            {
                contadorDeVogais++;
            }
        }
        
        printf("%d\n", contadorDeVogais);
        contadorDeVogais = 0;

        contador++;
    }
    
    return 0;
}

int caracterEhUmaVogal(char caracter)
{   
    int ehVogal = 0;
    int contador;
    int arrayDeCodigosDasVogais[10] = {97, 101, 105, 111, 117, 65, 69, 73, 79, 85};

    for (contador = 0; contador < 10; contador++)
    {
        if (arrayDeCodigosDasVogais[contador] == caracter)
        {
            ehVogal = 1;
            break;
        }
    }
    
    return ehVogal;
}