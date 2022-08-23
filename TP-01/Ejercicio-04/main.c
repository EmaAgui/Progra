#include <stdio.h>
#include <stdlib.h>


#define TOL 0.00001


double raiz(int num);


int main()
{
    int num = 4;
    printf("Raiz es %f", raiz(num));

    return 0;
}


double raiz(int num)
{
    float r = 1, b = 0, a = 0;

    do
    {
        b = r;
        r = ((b + (num / b)) /2);
        a = r - b;

        if(a < 0)
        {
            a *= -1;
        }
    }
    while(a > TOL);

    return r;
}
