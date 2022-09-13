#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dni;
    char noyApe[20];
    float promedio;
} tAlumnoA;


void mostrarAlumnoA(const tAlumnoA *pAlu);
void recorrerVector(void *vec, unsigned nItems, unsigned cantBytes, void fImpresion(void* dato));
void fImpresionInt(void* dato);

void *buscarMenor(void *vec, unsigned nItems, unsigned tam, int cmp(const void *dato1, const void *dato2)); ///Retorno la dir del menor
int cmpInt(const void *dato1, const void *dato2);

void ordSeleccion(void *vec, unsigned nItems, unsigned tam, int cmp(const void *dato1, const void *dato2)); ///Retorno la dir del menor
void intercambio(void *a, void *b, unsigned cantBytes);


int main()
{
    int vec[] = {3, 7, 5, 1, 16, 8, 15};
    int tam = sizeof(vec[0]);
    int nItems = sizeof(vec) /sizeof(vec[0]);

    int *menor = buscarMenor(vec, nItems, tam, cmpInt);
    printf("El Menor es: %d\n", *menor);

    ordSeleccion(vec, nItems, tam, cmpInt);
    recorrerVector(vec, nItems, tam, fImpresionInt);

    return 0;
}


///{3, 7, 5, 1, 16, 8, 15}
void ordSeleccion(void *vec, unsigned nItems, unsigned tam, int cmp(const void *dato1, const void *dato2))
{
    int i;
    void *menor;

    for(i = 0; i < nItems - 1; i++)
    {
        menor = buscarMenor(vec, nItems - i, tam, cmp); ///Busco el menor del resto del vector
        intercambio(vec, menor, tam);///Intercambio el menor con el primero
        vec += tam; ///Avanzo el puntero al siguiente elemento
    }
}


void intercambio(void *a, void *b, unsigned cantBytes)
{
    int i;
    char aux;

    for(i = 0; i < cantBytes; i++, a++, b++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
    }
}


int cmpInt(const void *dato1, const void *dato2)
{
   int d1 = *(int*)dato1;
   int d2 = *(int*)dato2;

   return d1 - d2;
}


void *buscarMenor(void *vec, unsigned nItems, unsigned tam, int cmp(const void *dato1, const void *dato2))
{
    int i;
    void* menor = vec;
    vec += tam;

    for(i = 0; i < nItems - 1; i++)
    {
        if(cmp(vec, menor) < 0)
            menor = vec;

        vec += tam;
    }
    return menor;
}


void fImpresionInt(void* dato)
{
    printf("\n%d", *(int*)dato);
}


void recorrerVector(void *vec, unsigned nItems, unsigned cantBytes, void fImpresion(void* dato))
{
    int i;
    for(i = 0; i < nItems; i++)
    {
        fImpresion(vec);
        vec += cantBytes;
    }
}


void mostrarAlumnoA(const tAlumnoA *pAlu)
{
    printf("\n%d %s  %.2f", pAlu->dni,
           pAlu->noyApe,
           pAlu->promedio);
}

