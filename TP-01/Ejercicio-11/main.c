#include <stdio.h>
#include <stdlib.h>


int sumatoriaPares(int num);


int main()
{
    int n = 8;

    printf("La sumatoria de los pares de %d es: %d\n", n, sumatoriaPares(n));

    return 0;
}


int sumatoriaPares(int num)
{
    int suma = 0, i;

    for(i = 1; i <= num; i++)
    {
        if(i % 2 == 0)
            suma += i;
    }

    return suma;
}
