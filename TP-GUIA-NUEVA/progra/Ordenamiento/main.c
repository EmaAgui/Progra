#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void mostrarVec(int *vec, int ce);
void intercambiar(int *e1, int *e2);
int *buscarMenor(int *vec, int *fin);
void ordenarSeleccion(int *vec, int ce);


void ordenarSelecFun(void *vec, size_t ce, size_t tam, int (*cmp)(const void *d1, const void *d2));
void *buscarMenorGen(void *vec, void*fin, size_t tam, int (*cmp)(const void *d1, const void *d2));
int cmpEnt(const void *d1, const void *d2);
void intercambiarGen(void *e1, void *e2, size_t tam);
/**
    Diferencia entre memcpy y memmove.
**/

int main()
{
    int vec[] = {6, 8, 7, 5, 1, 10, 4, 3, 9, 2};
    int ce = sizeof(vec) / sizeof(*vec);


    mostrarVec(vec, ce);
    ordenarSeleccion(vec, ce);
    mostrarVec(vec, ce);

    ordenarSelecFun(vec, ce, sizeof(int), cmpEnt);


    return 0;
}
/**
    1- Leer el vector
    2- Encontrar el numero mas chico
    3- intercambio

**/

void mostrarVec(int *vec, int ce)
{
    for(int i = 0; i < ce; i++)
    {
        printf("%d ", *(vec+ i));
    }
    printf("\n");
}


///Inicio Funcion no generica
void intercambiar(int *e1, int *e2)
{
    int aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}


int *buscarMenor(int *vec, int *fin)
{
    int *menor = vec;
    vec++;
    while(vec <= fin)
    {
        if(*vec < *menor)
            menor = vec;
        vec++;
    }
    return menor;
}


void ordenarSeleccion(int *vec, int ce)
{
    int *fin, *men;

    fin = vec + (ce - 1);

    while(vec < fin)
    {
        men = buscarMenor(vec, fin);
        if(*men != *vec)
        {
            intercambiar(vec, men);
        }
        vec++;
    }
}

///Fin Funcion no Generica

int cmpEnt(const void *d1, const void *d2)
{
    const int *e1 = (const int*)(d1);
    const int *e2 = (const int*)(d2);

    return *e1 - *e2;
}


void ordenarSelecFun(void *vec, size_t ce, size_t tam, int (*cmp)(const void *d1, const void *d2))
{
    void *fin, *men;

    fin = vec + (ce -1) * tam;

    while(vec < fin)
    {
        men = buscarMenorGen(vec, fin, tam, cmp);
        if(men != vec)
        {
            intercambiarGen(vec, men, tam);
        }
        vec += tam;
    }
}


void *buscarMenorGen(void *vec, void*fin, size_t tam, int (*cmp)(const void *d1, const void *d2))
{
    void *menor = vec;

    vec += tam;

    while(vec <= fin)
    {
        if(cmp(vec, menor) < 0)
            menor = vec;

        vec += tam;
    }
    return menor;
}


void intercambiarGen(void *e1, void *e2, size_t tam)
{
    char aux[1000];
    memcpy(aux, e1, tam);
    memcpy(e1, e2, tam);
    memcpy(e2, aux, tam);
}
