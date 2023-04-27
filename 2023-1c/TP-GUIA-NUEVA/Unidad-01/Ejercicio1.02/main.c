#include <stdio.h>
#include <stdlib.h>

#define TAM 8


int insertarElementoOrdenado(int *vec, int *ce, int numero);

/**
    Desarrollar una función que inserte un elemento en un arreglo de
    enteros, ordenado en forma ascendente, de forma de no alterar el orden.
**/

int main()
{
    int vec[TAM] = {1, 4, 8, 15, 22};
    int ce = 5;
    int num = 50;


    mostrarVectorInt(vec, ce);

    printf("\n");
    if(insertarElementoOrdenado(vec, &ce, num))
        mostrarVectorInt(vec, ce);


    return 0;
}



int insertarElementoOrdenado(int *vec, int *ce, int numero)
{
    int *ini, *fin, aux;

    ini = vec;
    fin = vec + *ce - 1;

    while(*ini <= numero)
        ini++;

    vec = ini;

    while(ini <= fin)
    {
        aux = *vec;
        *vec = numero;
        numero = aux;

        ini++;
        vec++;
    }

    return 1;
}
