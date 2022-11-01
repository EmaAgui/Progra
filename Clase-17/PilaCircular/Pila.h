#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

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

typedef tNodo *Pila;

void crearPila(Pila *pp);
int apilar(Pila *pp, const void *dato, unsigned tamBytes);
int desapilar(Pila *pp, void *dato, unsigned tamBytes);
int verTope(const Pila *pp, void *dato, unsigned tamBytes);
void vaciarPila(Pila *pp);
int pilaVacia(const Pila *pp);
int pilaLlena(Pila *pp, unsigned tamBytes);




#endif // PILA_H_INCLUDED
