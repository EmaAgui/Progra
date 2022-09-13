#include <stdio.h>
#include <stdlib.h>
/**
    buscar el menor y la cantidad de menores
**/


int buscarMenor(int *vec, int ce, int **pMenor, int *cantM);


int main()
{
    int vec[] = {2, 3, 1, 1, 7, 0};

    int ce = sizeof(vec) / sizeof(vec[0]);
    int *pMenor = vec;
    int cantM = 0;


    if(buscarMenor(vec, ce, &pMenor, &cantM))
        puts("Menor que 10");

    printf("\nMenor es: %d", *pMenor);
    printf("\nCantidad de Menores: %d", cantM);


    return 0;
}


int buscarMenor(int *vec, int ce, int **pMenor, int *cantM)
{
    int i = 0;

    while(i <= ce)
    {
        if(**pMenor <= *vec)
        {
            vec++;
        }
        else
        {
            *pMenor = vec;
            (*cantM) = 0;
        }
        if(**pMenor == *vec)
            (*cantM)++;

        i++;
    }

    return **pMenor;
}
