#include "ColaDin.h"


int colaLlena(Cola *pc, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}


void vaciarCola(Cola *pc)
{
    while(pc->pri)
    {
        tNodo *elim = pc->pri;
        pc->pri = elim->sig;

        free(elim->info);
        free(elim);
    }
    pc->ult = NULL;
}


int colaVacia(const Cola *pc)
{
    return pc->pri == NULL;
}


int verCola(const Cola *pc, void *dato, unsigned tamBytes)
{
    if(pc->pri == NULL)
        return 0;
    memcpy(dato, pc->pri->info, minimo(tamBytes, pc->pri->tamBytes));
    return 1;
}


int sacarDeCola(Cola *pc, void *dato, unsigned tamBytes)
{
    tNodo *sacar = pc->pri;
    if(sacar == NULL)
        return 0;

    pc->pri = sacar->sig;
    memcpy(dato, sacar->info, minimo(tamBytes, sacar->tamBytes));

    free(sacar->info);
    free(sacar);

    if(pc->pri == NULL)
        pc->ult = NULL;

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
    poner->sig = NULL;
    if(pc->ult)
        pc->ult->sig = poner;
    else
        pc->pri = poner;

    pc->ult = poner;
    return 1;
}


void crearCola(Cola *pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}
