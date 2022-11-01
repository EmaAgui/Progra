#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x < y)? x : y

typedef struct sNodo
{
    void *dato;
    unsigned tamBytes;
    struct sNodo *sig;
} tNodo;

typedef tNodo *Pila;

void crearPila(Pila *pp);
int apilar(Pila *pp, const void *dato, unsigned tamBytes);
int desapilar(Pila *pp, void *dato, unsigned tamBytes);
int verTope(Pila *pp, void *dato, unsigned tamBytes);
int pilaVacia(const Pila *pp);
void vaciarPila(Pila *pp);
int pilaLlena(const Pila *pp, unsigned tamBytes);

#endif // PILA_H_INCLUDED
