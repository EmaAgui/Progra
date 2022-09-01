#include <stdio.h>
#include <stdlib.h>


int insertarEnVectorOrdenadoAsc1(int *vec, int cantElem, int dato, int tam);
void mostrarVector(int *vec, int ce);
void intercambio(int *d1, int *d2);
int insertar(int *vec, int pos, int dato, int ce, int tam);


int main()
{
    int vec[8] = {1, 5, 8, 9};
    int cantElem = sizeof(vec) / sizeof(int);
    int dato = 2;


    printf("\nVector antes de insertar elemento: ");
    mostrarVector(vec, cantElem);

    printf("\nVector despues de insertar elemento: ");
    printf("\nDato: %d", dato);

    if(insertarEnVectorOrdenadoAsc1(vec, cantElem, dato, 5))
        mostrarVector(vec, cantElem);
    else
        printf("\nError");
    return 0;
}


int insertarEnVectorOrdenadoAsc1(int *vec, int cantElem, int dato, int tam)
{
    int  *pVecPos = vec, pos = 1;

    while(dato > *(pVecPos) && pos <= cantElem)
    {
        pos++;
        pVecPos++;
    }

    if(pos > tam)
        return 0;

    insertar(vec, pos, dato, cantElem, tam);

    return 1;

}


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
