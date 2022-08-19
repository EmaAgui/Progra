#include <stdio.h>
#include <stdlib.h>

int perteneceAFibonacci(int n);

int main()
{
    int n = 144;

    if(perteneceAFibonacci(n))
    {
        printf("El numero %d es un numero de Fibonacci\n", n);
    }
    else
    {
        printf("El numero %d no es un numero de Fibonacci\n", n);
    }

    return 0;
}


int perteneceAFibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;

    while (c < n) /// mientras el numero siguiente sea menor que el numero que se busca
    {
        c = a + b;
        a = b;
        b = c;
    }

    if (c == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
