#include "Pila.h"


int pilaLlena(Pila *pp, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}


int pilaVacia(const Pila *pp)
{
    return *pp == NULL;
}


void vaciarPila(Pila *pp)
{
    while(*pp)
    {
        tNodo *elim = (*pp)->sig;

        if(*pp == elim)
            *pp = NULL;
        else
            (*pp)->sig = elim->sig;

        free(elim->info);
        free(elim);
    }
}


int verTope(const Pila *pp, void *dato, unsigned tamBytes)
{
    if(!*pp)
        return 0;

    memcpy(dato, (*pp)->sig->info, minimo(tamBytes, (*pp)->sig->tamBytes));
    return 1;
}


int desapilar(Pila *pp, void *dato, unsigned tamBytes)
{
    tNodo *sacar = (*pp)->sig;

    if(!sacar)
        return 0;

    memcpy(dato, sacar->info, minimo(tamBytes, sacar->tamBytes));

    if(sacar == *pp) ///hay un solo elemento en la pila
        *pp = NULL;
    else
        (*pp)->sig = sacar->sig; ///apunta al sig de sacar

    free(sacar->info);
    free(sacar);

    return 1;
}


int apilar(Pila *pp, const void *dato, unsigned tamBytes)
{
    tNodo *poner = malloc(sizeof(tNodo));
    if(!poner)
        return 0;

    poner->info = malloc(tamBytes);
    if(!poner->info)
    {
        free(poner);
        return 0;
    }

    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;

    if(*pp == NULL) ///Si es el primero que pongo
    {
       poner->sig = poner; ///el sig apunta a si mismo
       *pp = poner; /// el puntero a la pila apunta a poner
    }
    else
    {
        poner->sig = (*pp)->sig; ///el sig de poner apunta al sig de la pila
        (*pp)->sig = poner; /// el puntero sig de la pila apunta a poner
    }

    return 1;
}


void crearPila(Pila *pp)
{
   *pp = NULL;
}
