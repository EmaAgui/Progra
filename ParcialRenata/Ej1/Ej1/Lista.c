#include "Lista.h"
void crearLista (t_lista *l)
{
    *l = NULL;
}

int ponerEnOrden (t_lista *l, const void *dato, unsigned tamBy, int(*cmp)(const void *d1, const void *d2), void(*accion)(void *d1, const void *d2))
{
    t_nodo *nue;
    int comparacion =1;

    while(*l && (comparacion= cmp(dato, (*l)->info))>0)
    {
        l= &(*l)->sig;
    }

    if( *l && !comparacion)
    {
        accion((*l)->info,dato);
        return 1;
    }

    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }

    nue->info=malloc(tamBy);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam= tamBy;
    memcpy(nue->info,dato, tamBy);

    nue->sig = *l;
    *l = nue;

    return 1;
}

int verPrimero(const t_lista *pl, void *dato, unsigned tamBytes)
{
    if(*pl == NULL)
        return 0;
    memcpy(dato, (*pl)->info, MIN((*pl)->tam, tamBytes));
    return 1;
}
int listaVacia (const t_lista *l)
{
    return *l == NULL;
}


void mostrarLista(t_lista* lista,void(*mostrar)(const void*))
{
    while(*lista)
    {
        mostrar((*lista)->info);
        lista = &(*lista)->sig;
    }
}
