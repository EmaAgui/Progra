#include <stdio.h>
#include <stdlib.h>


int sumatoriaParesMenoresQueN(int num);


int main()
{
    int n = 9;

    printf("La sumatoria de los pares de %d es: %d\n", n, sumatoriaParesMenoresQueN(n));

    return 0;
}


int sumatoriaParesMenoresQueN(int num)
{
    int sum = 0, i;

    for(i = 1; i <= num; i++)
    {
        if(i % 2 == 0)
            sum += i;
    }
    return sum;
}
