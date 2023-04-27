#include <stdio.h>
#include <stdlib.h>

int factorial(int n);


int main()
{
    printf("El factorial es %d", factorial(5));

    return 0;
}

int factorial(int n)
{
    int resultado = 1;
    for (int i = 1; i <= n; i++)
        resultado *= i;

    return resultado;
}
