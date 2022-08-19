#include <stdio.h>
#include <math.h>

#define TOL 0.0000001


unsigned long long factorial(int n);
unsigned long long elevar(int base, int exponente);
float exponente(int x, int i);


int main()
{
    int x = 3, i = 0;
    double res = 0, res2 = 1, error;

    do
    {
        res += exponente(x, i);
        res2 += exponente(x, i+1);
        error = res2 - res;

        i++;
    }
    while(error  > TOL);

    printf("Error %e\n\n", error);
    printf("Tol %e\n\n", TOL);
    printf("El res: %f", res);

    return 0;
}


float exponente(int x, int i)
{
    return ((float)(pow(x, i)) / (float)(factorial(i)));
}


unsigned long long elevar(int base, int exponente)
{
    unsigned long long i, res = 1;

    for(i = 1; i <= exponente; i++)
        res *= base;

    return res;
}


unsigned long long factorial(int n)
{
    unsigned long long i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

