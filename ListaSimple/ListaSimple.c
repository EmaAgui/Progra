#include "ListaSimple.h"

void ordenarLista(Lista *pl, int cmp(const void* d1, const void *d2))
{
    tNodo* nodo; ///nodo actual
    Lista lOrd = NULL; //creo una lista
    Lista* plOrd;   ///puntero a lista ordenada

    while (*pl) /// *pl != NULL
    {
        nodo = *pl; ///nodo actual
        *pl = nodo->sig;/// avanza el puntero de la lista
        plOrd = &lOrd; ///puntero a lista ordenada

        while (*plOrd && cmp(nodo->info, (*plOrd)->info) > 0) ///mientras que el puntero de la lista ordenada no sea NULL y el dato del nodo actual sea mayor al dato del nodo de la lista ordenada, igual que insertarOrdenado
            plOrd = &(*plOrd)->sig; ///avanza el puntero de la lista ordenada

        nodo->sig = *plOrd;///el nodo actual apunta al nodo de la lista ordenada
        *plOrd = nodo;///el puntero de la lista ordenada apunta al nodo actual
    }

    *pl = lOrd;//la lista original apunta a la lista ordenada
}


int ponerEnOrden(Lista *pl, const void *dato, unsigned tamBytes, int cmp(const void *d1, const void *d2))
{
    tNodo *poner = malloc(sizeof(tNodo));
    int comp;

    while(*pl && (comp = cmp((*pl)->info, dato)) < 0)
        pl = &(*pl)->sig;

    if(poner == NULL)
        return 0;

    poner->info = malloc(tamBytes);
    if(poner->info == NULL)
    {
        free(poner);
        return 0;
    }

    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;
    poner->sig = *pl;
    *pl = poner;

    return 1;
}


void mostrarLista(const Lista *pl, void (mostrar)(const void *d1))
{
    while(*pl)
    {
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }

}

int verUltimo(const Lista *pl, void *dato, unsigned tamBytes)
{
    if(*pl == NULL)
        return 0;
    while((*pl)->sig)
        pl = &(*pl)->sig;
    memcpy(dato, (*pl)->info, minimo((*pl)->tamBytes, tamBytes));
    return 1;
}


int sacarUltimo(Lista *pl, void *dato, unsigned tamBytes)
{
    if(*pl == NULL)
        return 0;
    while((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(dato, (*pl)->info, minimo((*pl)->tamBytes, tamBytes));
    free((*pl)->info);
    free(*pl);

    return 1;
}


int verPrimero(const Lista *pl, void *dato, unsigned tamBytes)
{
    if(*pl == NULL)
        return 0;
    memcpy(dato, (*pl)->info, minimo((*pl)->tamBytes, tamBytes));
    return 1;
}


int sacarPrimero(Lista *pl, void *dato, unsigned tamBytes)
{
    tNodo *sacar = *pl;
    if(sacar == NULL)
        return 0;

    *pl = sacar->sig;
    memcpy(dato, sacar->info, minimo(sacar->tamBytes, tamBytes));
    free(sacar->info);
    free(sacar);
    return 1;
}


int ponerAlfinal(Lista *pl, const void *dato, unsigned tamBytes)
{
    tNodo *poner = malloc(sizeof(tNodo));

    while(*pl)
        pl = &(*pl)->sig;
    if(poner == NULL)
        return 0;

    poner->info = malloc(tamBytes);
    if(poner->info == NULL)
    {
        free(poner);
        return 0;
    }
    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;

    poner->sig = NULL;
    *pl = poner;

    return 1;
}


int ponerAlComienzo(Lista *pl, const void *dato, unsigned tamBytes)
{
    tNodo *poner = malloc(sizeof(tNodo));

    if(poner == NULL)
        return 0;

    poner->info = malloc(tamBytes);

    if(poner->info == NULL)
    {
        free(poner);
        return 0;
    }

    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;

    poner->sig = *pl;
    *pl = poner;

    return 1;
}

void vaciarLista(Lista *pl)
{
    while(*pl)
    {
        tNodo *elim = *pl;
        *pl = elim->sig;

        free(elim->info);
        free(elim);
    }
}


int listaLlena(const Lista *pl, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}

int listaVacia(const Lista *pl)
{
    return *pl == NULL;
}


void crearLista(Lista *pl)
{
    *pl = NULL;
}
