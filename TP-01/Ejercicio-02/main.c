#include <stdio.h>
#include <stdlib.h>


int combinatoria(int m, int n);
int factorial(int n);


int main()
{
    int comb = combinatoria(-1,-1);
    if(comb)
        printf("La combinatoria es: %d", comb );
    else
        printf("Error");
    return 0;
}


int combinatoria(int m, int n)
{
    if(m >= n && n >= 0)
    {
        return (factorial(m) / (factorial(n) * factorial(m - n)));
    }
    return 0;
}


int factorial(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
