#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 10001

int n;
double a, b, epsilon;
double coef[MAX_DEGREE];

double f(double x) 
{
    double result = 0;
    int i;

    for (i = 0; i <= n; i++) 
    {
        result += coef[i] * pow(x, i);
    }

    return result;
}

int main() {
    scanf("%d %lf", &n, &epsilon);
    scanf("%lf %lf", &a, &b);
    int i;

    for (i = 0; i <= n; i++) 
    {
        scanf("%lf", &coef[i]);
    }

    double mid;

    while (fabs(b - a) > epsilon) 
    {
        mid = (a + b) / 2;
        if (f(mid) == 0) 
        {
            printf("%.6lf\n", mid);
            break;
        }
        if (f(a) * f(mid) < 0) 
        {
            b = mid;
        } else 
        {
            a = mid;
        }
    }
    
    printf("%.6lf\n", (a + b) / 2);
    return 0;
}