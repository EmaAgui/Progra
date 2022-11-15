#include "Arbol.h"


int eliminarElemArbol(Arbol *pa, void *dato, unsigned tambytes, int comp(const void *d1, const void *d2))
{
    if(!(pa = buscarNodoAElim(pa, dato, comp)))
        return 0;
    memcpy(dato, (*pa)->info, minimo(tambytes, (*pa)->tamBytes));

    return eliminarNodoRaiz(pa);
}


tNodo **buscarNodoAElim(const Arbol *pa, const void *dato, int comp(const void *d1, const void *d2))
{
    int rComp;

    while (*pa && (rComp = comp(dato, (*pa)->info)))
    {
        if(rComp < 0)
            pa = &(*pa)->izq;
        else
            pa = &(*pa)->der;
    }

    if(!*pa)
        return NULL;


    return (tNodo **)pa;
}


int eliminarNodoRaiz(Arbol *pa)
{
    tNodo **remp, *elim;

    if(!*pa)
        return 0;

    free((*pa)->info);

    if(!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return 1;
    }

    remp = alturaArbol(&(*pa)->izq) > alturaArbol(&(*pa)->der) ? mayorNodoArbol(&(*pa)->izq) : menorNodoArbol(&(*pa)->der);

    elim = *remp;
    (*pa)->info = elim->info;
    (*pa)->tamBytes = elim->tamBytes;

    *remp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}


tNodo ** menorNodoArbol(const Arbol *pa)
{
    if(!*pa)
        return NULL;
    while ((*pa)->izq)
        pa = &(*pa)->izq;

    return (tNodo **)pa;
}


tNodo ** mayorNodoArbol(const Arbol *pa)
{
    if(!*pa)
        return NULL;
    while ((*pa)->der)
        pa = &(*pa)->der;

    return (tNodo **)pa;
}



int esArbolAvl(const Arbol *pa)
{
    int hd = alturaArbol(&(*pa)->der);
    int hi = alturaArbol(&(*pa)->izq);

    if(!*pa)
        return 1;


    if ((hi - hd) > 1)
        return 0;

    return esArbolAvl(&(*pa)->der) && esArbolAvl(&(*pa)->izq);
}


unsigned alturaArbol(const Arbol *pa)
{
    int hi, hd;

    if(!*pa)
        return 0;
    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    return (hi > hd? hi : hd) + 1;
}


void vaciarArbol(Arbol *pa)
{
    if(!*pa)
        return;
    vaciarArbol(&(*pa)->izq);
    vaciarArbol(&(*pa)->der);

    free((*pa)->info);
    free((*pa));

    *pa = NULL;
}


int contarNodos(Arbol *pa)
{
    if(!*pa)
        return 0;
    return contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1;
}


void mostrarArbolPosOrden(Arbol *pa, void accion(const void *d1))
{
    if(!*pa)
        return;

    mostrarArbolPosOrden(&(*pa)->izq, accion);
    mostrarArbolPosOrden(&(*pa)->der, accion);
    accion((*pa)->info);
}


void mostrarArbolPreOrden(Arbol *pa, void accion(void *d1))
{
    if(!*pa)
        return;
    accion((*pa)->info);
    mostrarArbolPreOrden(&(*pa)->izq, accion);
    mostrarArbolPreOrden(&(*pa)->der, accion);
}


void mostrarArbolInOrden(Arbol *pa, int n, void accion(const void *d1))
{
    int i;
    if(!*pa)
        return;

    mostrarArbolInOrden(&(*pa)->izq, n + 1, accion);
    for(i = 0; i < n; i++)
        printf("    ");

    accion((*pa)->info);
    mostrarArbolInOrden(&(*pa)->der, n + 1, accion);
}


int insertarEnArbol(Arbol *pa, const void *dato, unsigned tamBytes, int (cmp)(const void *d1, const void *d2))
{
    tNodo *nue;
    int comp;

    if(*pa)
    {
        if((comp = cmp(dato, (*pa)->info)) < 0)
            return insertarEnArbol(&(*pa)->izq, dato, tamBytes, cmp);
        if(comp > 0)
            return insertarEnArbol(&(*pa)->der, dato, tamBytes, cmp);
        if(comp == 0)
            return 0;
    }

    nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;
    nue->info = malloc(tamBytes);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamBytes);
    nue->tamBytes = tamBytes;

    nue->izq = NULL;
    nue->der = NULL;

    *pa = nue;

    return 1;
}


void crearArbol(Arbol *pa)
{
    *pa = NULL;
}
