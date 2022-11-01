#include "Pila.h"

void vaciarPila(Pila *pp)
{
    tNodo *elim;
    while (*pp)
    {
        elim = *pp;
        *pp = elim->sig;
        free(elim->dato);
        free(elim);
    }
    
}
int verTope(Pila *pp, void *dato, unsigned tamBytes)
{
    tNodo *tope = *pp;

    if(*pp == NULL)        
        return 0;
    
    memcpy(dato, tope->dato, MIN(tamBytes, tope->tamBytes));

    return 1;
}

int pilaLlena(const Pila *pp, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    nue->dato = malloc(tamBytes);

    free(nue->dato);
    free(nue);

    return !nue || !nue->dato;
}


int pilaVacia(const Pila *pp)
{
    return *pp == NULL;
}


int desapilar(Pila *pp, void *dato, unsigned tamBytes)
{
    tNodo *elim = *pp;

    if(*pp == NULL)        
        return 0;
    
    *pp = elim->sig;
    memcpy(dato, elim->dato, MIN(tamBytes, elim->tamBytes));

    free(elim->dato);
    free(elim);

    return 1;
}


int apilar(Pila *pp, const void *dato, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    if(!nue)    
        return 0;

    nue->dato = malloc(tamBytes);
    if (!nue->dato)
    {
        free(nue);
        return 0;
    }

    nue->tamBytes = tamBytes;
    nue->sig = *pp;

    memcpy(nue->dato, dato, tamBytes);
    *pp = nue;

    return 1;
}


void crearPila(Pila *pp)
{
    *pp = NULL;
}


