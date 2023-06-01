#include <stdio.h>
#include <stdlib.h>

#define TAM 5

/**
Desarrollar una función que inserte un elemento en un arreglo de enteros,
dada la posición de inserción.

**/

int insertarElemento(int *vec, int *ce, int numero, int posicion);


int main()
{
    int vec[TAM] = {2, 56, 24, 8, 9};
    int ce = sizeof(vec) / sizeof(*vec);
    int num = 100;
    int posicion = 4;

    mostrarVectorInt(vec, ce);

    printf("\n");
    if(insertarElemento(vec, &ce, num, posicion))
        mostrarVectorInt(vec, ce);

    return 0;
}


int insertarElemento(int *vec, int *ce, int numero, int posicion)
{
    int *ini, *fin, aux;

    if(posicion > *ce)
        return 0;

    ini = vec + posicion;
    fin = vec + *ce - 1;

    while(ini <= fin)
    {
        aux = *ini;
        *ini = numero;
        ini++;
        numero = aux;
    }

    return 1;
}

