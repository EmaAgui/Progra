#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define minimo(x, y) (x <= y)? x : y


typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct sNodo *sig;
}tNodo;

typedef tNodo *Lista;


void crearLista(Lista *pl);
int listaVacia(const Lista *pl);
int listaLlena(const Lista *pl, unsigned tamBytes);
void vaciarLista(Lista *pl);
int ponerAlComienzo(Lista *pl, const void *dato, unsigned tamBytes);
int ponerAlfinal(Lista *pl, const void *dato, unsigned tamBytes);
int sacarPrimero(Lista *pl, void *dato, unsigned tamBytes);
int verPrimero(const Lista *pl, void *dato, unsigned tamBytes);
int sacarUltimo(Lista *pl, void *dato, unsigned tamBytes);
int verUltimo(const Lista *pl, void *dato, unsigned tamBytes);
void mostrarLista(const Lista *pl, void (mostrar)(const void *d1));
int ponerEnOrden(Lista *pl, const void *dato, unsigned tamBytes, int cmp(const void *d1, const void *d2));
void ordenarLista(Lista *pl, int cmp(const void* d1, const void *d2));

#endif // LISTASIMPLE_H_INCLUDED
