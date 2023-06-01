#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char clave;
    float valor;
}Producto;


int main()
{
    int ce = 6, i = 0;
    char clave;
    float total;
    Producto vPro[] =
    {
        {'A', 10},
        {'A', 15},
        {'B', 10},
        {'B', 20},
        {'B', 8},
        {'C', 10}
    };
    while(i < ce)
    {
        clave = vPro[i].clave;
        total = 0;

        while(i < ce && vPro[i].clave  == clave)
        {
            total += vPro[i].valor;
            i++;
        }
        printf("Clave: %c Total: %f\n",clave, total);
    }

    return 0;
}
