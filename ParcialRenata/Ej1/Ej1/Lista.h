#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (x)< (y)? (x) : (y)

typedef struct s_nodo
{
    void *info;
    unsigned tam;
    struct s_nodo *sig;

}t_nodo;

typedef t_nodo *t_lista;

void crearLista (t_lista *l);
int ponerEnOrden (t_lista *l, const void *dato, unsigned tamBy, int(*cmp)(const void *d1, const void *d2), void(*accion)(void *d1, const void *d2));
int verPrimero(const t_lista *pl, void *dato, unsigned tamBytes);
int listaVacia (const t_lista *l);
void mostrarLista(t_lista* lista,void(*mostrar)(const void*));
#endif // LISTA_H_INCLUDED
