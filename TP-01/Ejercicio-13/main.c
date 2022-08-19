#include <stdio.h>
#include <stdlib.h>


int esNumeroPrimo(int num);


int main()
{
    int num = 5;

    if(esNumeroPrimo(num))
        printf("%d es numero primo\n", num);
    else
        printf("%d no es numero primo\n", num);

    return 0;
}


int esNumeroPrimo(int n)
{
    int i, contDiv = 0;

    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            contDiv++;
        }
    }

    return contDiv == 2;
}
