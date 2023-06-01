#include <stdio.h>
#include <stdlib.h>

#include "../Funciones/Funciones.h"

#define TAM 9
/**
    Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo
    de enteros.

**/


int eliminarPosVector(int *vec, int *ce, int posicion);


int main()
{
    int vec[TAM] = {5, 6, 7, 9, 11};
    int ce = 5;
    int posicion = 4;

    mostrarVectorInt(vec, ce);


    eliminarPosVector(vec, &ce, posicion);
    mostrarVectorInt(vec, ce);



    return 0;
}


int eliminarPosVector(int *vec, int *ce, int posicion)
{
    int *ini, *fin;

    if(posicion > *ce)
        return 0;

    ini = vec + posicion - 1;
    fin = vec + *ce;
    vec = ini;

    while(ini <= fin)
    {
        ini++;
        *vec = *ini;
        vec++;
    }

    (*ce)--;
    return 1;
}

