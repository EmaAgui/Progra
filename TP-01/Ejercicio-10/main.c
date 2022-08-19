#include <stdio.h>
#include <stdlib.h>


int sumatoria(int num);


int main()
{
    int num = 6;

    printf("La suma de los primeros numeros de %d es: %d", num, sumatoria(num));
    return 0;
}

int sumatoria(int num)
{
    int i, sum = 0;

    for(i = 1; i <= num; i++)
    {
        sum += i;
    }
    return sum;
}
