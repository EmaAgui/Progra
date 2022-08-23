#include <stdio.h>
#include <stdlib.h>


void mostrarVector(int* vec, int ce);
void intercambiar(int *vec1, int *vec2);
void ordenarPorBurbujeo(int* vec, int cantElem);
void ordenarPorSeleccion(int* vec, int cantElem);
int buscarMenor(int* vec, int desde, int hasta);
void ordenarPorInsercion(int* vec, int cantElem);


int main()
{
    int vec1[] = {10, 12, 11, 5, 8, 1, 21, 34};

    mostrarVector(vec1, 8);

    printf("\nVector ordenado burbujeo:\n");
    ordenarPorBurbujeo(vec1, 8);
    mostrarVector(vec1, 8);

    int vec2[] = {10, 12, 11, 5, 8, 1, 21, 34};
    printf("\nVector ordenado Seleccion:\n");
    ordenarPorSeleccion(vec2, 8);
    mostrarVector(vec2, 8);

    int vec3[] = {10, 12, 11, 5, 8, 1, 21, 34};
    printf("\nVector ordenado Insercion:\n");
    ordenarPorInsercion(vec3, 8);
    mostrarVector(vec3, 8);


    return 0;
}


void ordenarPorInsercion(int* vec, int cantElem)
{
    int j;
    int elemAInsertar;

    for(int i = 1; i < cantElem; i++)
    {
        elemAInsertar = *(vec + i);
        j = i - 1;

        while(j >= 0 && elemAInsertar < *(vec + j))
        {
            *(vec + j + 1) = *(vec + j);
            j--;
        }
        *(vec + j + 1) = elemAInsertar;
    }
}


int buscarMenor(int* vec, int desde, int hasta)
{
    int m = desde;

    for(int j = desde + 1; j <= hasta; j++)
    {
        if(*(vec + j) < *(vec + m))
            m = j;
    }

    return m;
}


void ordenarPorSeleccion(int* vec, int cantElem)
{
    int i, menor;

    for(i = 0; i < cantElem - i; i++)
    {
        menor = buscarMenor(vec, i, cantElem - 1);

        if(menor != i)
            intercambiar( (vec + menor), (vec + i));

    }
}


void intercambiar(int *vec1, int *vec2)
{
    int aux;

    aux = *vec1;
    *vec1 = *vec2;
    *vec2 = aux;
}


void ordenarPorBurbujeo(int* vec, int cantElem)
{
    int i = 1, j;
    int huboIntercambio = 1;

    while(i < cantElem && huboIntercambio)
    {
        huboIntercambio = 0;

        for(j = 0; j < cantElem - i; j++)
        {
            if( *(vec + j) > *(vec + j + 1))
            {
                intercambiar((vec + j), (vec + j + 1));
                huboIntercambio = 1;
            }
        }

        i++;
    }

}


void mostrarVector(int* vec, int ce)
{
    int i;

    for(i = 0; i < ce; i++,vec++)
    {
        printf("[%d] ", *vec);
    }
}
