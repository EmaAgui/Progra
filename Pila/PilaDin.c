#include "PilaDin.h"


int pilaLlena(const Pila *pp, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}


void vaciarPila(Pila *pp)
{
    while(*pp)
    {
        tNodo *elim = *pp;
        *pp = elim->sig;

        free(elim->info);
        free(elim);
    }
}


int pilaVacia(const Pila *pp)
{
    return *pp == NULL;
}


int verTope(const Pila *pp, void *dato, unsigned tamBytes)
{
    if(*pp == NULL)
        return 0;
    memcpy(dato, (*pp)->info, minimo(tamBytes, (*pp)->tamBytes));

    return 1;
}


int sacarDePila(Pila *pp, void *dato, unsigned tamBytes)
{
    tNodo *sacar = *pp;

    if(sacar == NULL)
        return 0;

    *pp = sacar->sig;
    memcpy(dato, sacar->info, minimo(tamBytes, sacar->tamBytes));
    free(sacar->info);
    free(sacar);

    return 1;
}


int ponerEnPila(Pila *pp, const void *dato, unsigned tamBytes)
{
    tNodo *poner = malloc(sizeof(tNodo));
    if(poner == NULL)
        return 0;

    poner->info = malloc(tamBytes);
    if(poner->info == NULL)
    {
        free(poner->info);
        return 0;
    }

    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;
    poner->sig = *pp;
    *pp = poner;

    return 1;
}


void crearPila(Pila *pp)
{
    *pp = NULL;
}
