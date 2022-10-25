#ifndef PILADIN_H_INCLUDED
#define PILADIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define minimo(x, y) (x <= y)? x : y

typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct sNodo *sig;
}tNodo;


typedef tNodo *Pila;


void crearPila(Pila *pp);
int ponerEnPila(Pila *pp, const void *dato, unsigned tamBytes);
int sacarDePila(Pila *pp, void *dato, unsigned tamBytes);
int verTope(const Pila *pp, void *dato, unsigned tamBytes);
int pilaVacia(const Pila *pp);
void vaciarPila(Pila *pp);
int pilaLlena(const Pila *pp, unsigned tamBytes);

#endif // PILADIN_H_INCLUDED
