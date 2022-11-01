#include "Cola.h"


int colaLlena(const Cola *pc, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}


int colaVacia(const Cola *pc)
{
    return *pc == NULL;
}


void vaciarCola(Cola *pc)
{
    while(*pc)
    {
        tNodo *elim = (*pc)->sig;

        if(*pc == NULL) /// si la cola esta vacia
            *pc = NULL;
        else
            (*pc)->sig = elim->sig;

        free(elim->info);
        free(elim);
    }
}


int verPrimero(const Cola *pc, void *dato, unsigned tamBytes)
{
    if(*pc == NULL)
        return 0;
    memcpy(dato, (*pc)->sig->info, minimo(tamBytes, (*pc)->sig->tamBytes));

    return 1;
}


int sacarDeCola(Cola *pc, void *dato, unsigned tamBytes)
{
    tNodo *sacar = (*pc)->sig;

    if(sacar == NULL)
        return 0;

    memcpy(dato, sacar->info, minimo(tamBytes, sacar->tamBytes));

    if(sacar == *pc)
        *pc = NULL;
    else
        (*pc)->sig = sacar->sig;

    free(sacar->info);
    free(sacar);

    return 1;
}


int ponerEnCola(Cola *pc, const void *dato, unsigned tamBytes)
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

    if(*pc == NULL) /// si la cola esta vacia
    {
        poner->sig = poner; /// el sig apunta a si mismo
    }
    else
    {
        poner->sig = (*pc)->sig; /// poner va a apuntar al primero de la cola
        (*pc)->sig = poner; /// el sig de la cola apunta a poner
    }
    *pc = poner; ///la cola apunta siempre al ultimo

    return 1;
}


void crearCola(Cola *pc)
{
    *pc = NULL;
}
