#include <stdio.h>
#include <stdlib.h>

void funcion(int n);


int main()
{
    funcion(8128);
    return 0;
}

void funcion(int n)
{
    int i,clasi=0;

    for(i=1;i<n;i++)
    {
        if(n%i == 0)
        {
            clasi+=i;
        }
    }
    if(clasi == n)
    {
        printf("\nPERFECTO");
    }
    else
    {
        if (clasi>n)
        {
            printf("\nABUNDANTE");
        }
        else
        {
            printf("\nDEFICIENTE");
        }
    }
}
