#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define TOL 0.01


unsigned long long factorial(int n);
double senox(double x);


int main()
{
    double n = 6;

    printf("%f\n", senox(n));

    return 0;
}


double senox(double x)
{
    int  i = 1, consig = 0;
    double sen = 0, res;

    do
    {
        res = (pow(x, i) / factorial(i));

        if(consig == 0)
        {
            sen += res;
            consig = 1;
        }
        else
        {
            sen -= res;
            consig = 0;
        }
        i += 2;
    }
    while(res > TOL);

    return sen;
}


unsigned long long factorial(int n)
{
    unsigned long long i, fact = 1;

    if(n == 0)
        return 1;

    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
