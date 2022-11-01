#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MIN(x,y) (x < y )? x : y

typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct sNodo *sig;
}tNodo;


typedef tNodo *Pila;


void crearPila(Pila *pPila);
int ponerEnPila(Pila *pPila, const void *dato, unsigned tamBytes);
int sacarPila(Pila *pPila, void *dato, unsigned tamBytes);
int pilaVacia(const Pila *pPila);
int pilaLlena(const Pila *pPila, unsigned tamBytes);
void vaciarPila(Pila *pPila);
int verTope(const Pila *pPila, void *dato, unsigned tamBytes);



#endif // PILA_H_INCLUDED
