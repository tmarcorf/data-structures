#include <stdio.h>

int gcd(int num1, int num2);

int main()
{
    int d, n;
    int contador = 0;
    int indiceDoNumero;

    scanf("%d", &indiceDoNumero);

    while (indiceDoNumero != 0)
    {
        for (d = 1; ; d++)
        {
            for (n = 0; n <= d; n++)
            {
                if (gcd(n, d) == 1)
                {
                    contador++;

                    if (contador == indiceDoNumero)
                    {
                        printf("%d/%d\n", n, d);
                        break;
                    }
                }
            }

            if (contador == indiceDoNumero)
            {
                contador = 0;
                break;
            }
        }

        scanf("%d", &indiceDoNumero);
    }
    
    return 0;
}

int gcd(int a, int b) 
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}