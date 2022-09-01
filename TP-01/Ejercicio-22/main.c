#include <stdio.h>
#include <stdlib.h>


void mostrarVector(int *vec, int ce);
int insertar(int *vec, int pos, int elem, int cantElem, int tam);


int main()
{
    int vec[] = {1, 2, 3, 4, 5, 12};
    int cantElem = sizeof(vec)/sizeof(int);

    printf("Antes de insertar");
    mostrarVector(vec, cantElem);

    printf("\n\nDespues de insertar");
    if(insertar(vec, 4, 10, cantElem, cantElem))
        mostrarVector(vec, cantElem);
    else
        printf("\nError");

    return 0;
}


///Inserta un elemento entero en una posicion
int insertar(int *vec, int pos, int dato, int ce, int tam)
{
    int aux;

    if(pos > tam || pos <= 0)
        return 0;

    vec += pos-1;

    while(pos <= ce)
    {
        aux = *vec;
        *vec = dato;
        dato = aux;

        vec++;
        pos++;
    }

    return 1;
}


void mostrarVector(int *vec, int ce)
{
    int i;
    for(i = 0; i < ce; i++, vec++)
    {
        printf("\n%d", *vec);
    }
}
