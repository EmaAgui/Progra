#include "Pila.h"


int verTope(const Pila *pPila, void *dato, unsigned tamBytes)
{
    if(*pPila == NULL)
        return 0;

    tNodo *tope = *pPila;

    memcpy(dato, tope->info, MIN(tamBytes, tope->tamBytes));

    return 1;
}


void vaciarPila(Pila *pPila)
{
    tNodo *elim;

    while(*pPila)
    {
        elim = *pPila;
        *pPila = elim->sig;
        free(elim->info);
        free(elim);
    }
}


int pilaLlena(const Pila *pPila, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    nue->info = malloc(tamBytes);

    free(nue->info);
    free(nue);

    return !nue->info || !nue;
}


int pilaVacia(const Pila *pPila)
{
    return *pPila == NULL;
}


int sacarPila(Pila *pPila, void *dato, unsigned tamBytes)
{
    if(*pPila == NULL)
        return 0;

    tNodo *elim = *pPila;
    *pPila = elim->sig;

    memcpy(dato, elim->info, MIN(tamBytes, elim->tamBytes));

    free(elim->info);
    free(elim);

    return 1;
}


int ponerEnPila(Pila *pPila, const void *dato, unsigned tamBytes)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo)); ///Creo un nodo nuevo

    if(!nue)
        return 0;

    nue->info = malloc(tamBytes);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamBytes = tamBytes;
    nue->sig = *pPila;
    memcpy(nue->info, dato, tamBytes);

    *pPila = nue;

    return 1;
}

void crearPila(Pila *pPila)
{
    *pPila = NULL; ///Pila vacia
}
