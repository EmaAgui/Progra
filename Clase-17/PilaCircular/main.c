#include "Pila.h"

/**
    Hacer las primitivas de cola y pila circular
    Compararlas
**/
int main()
{
    Pila pila;
    int vNum[] = {1,2,3,4,5,6,7,8,9};
    int i, ce, num;

    ce = sizeof(vNum) / sizeof(*vNum);

    crearPila(&pila);

    for(i = 0; i < ce; i++)
        apilar(&pila, vNum + i, sizeof(*vNum));

    while(!pilaVacia(&pila))
    {
        desapilar(&pila, &num, sizeof(num));
        printf("%d ", num);
    }

    return 0;
}


