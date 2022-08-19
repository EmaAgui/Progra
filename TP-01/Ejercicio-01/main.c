#include <stdio.h>
#include <stdlib.h>


unsigned long long factorial(int n);


int main()
{
    printf("Factorial %llu\n", factorial(21));
    return 0;
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
