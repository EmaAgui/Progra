#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


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

typedef tNodo *Cola;

void crearCola(Cola *pc);
int ponerEnCola(Cola *pc, const void *dato, unsigned tamBytes);
int sacarDeCola(Cola *pc, void *dato, unsigned tamBytes);
int verPrimero(const Cola *pc, void *dato, unsigned tamBytes);
void vaciarCola(Cola *pc);
int colaVacia(const Cola *pc);


#endif // COLA_H_INCLUDED
