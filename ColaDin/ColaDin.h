#ifndef COLADIN_H_INCLUDED
#define COLADIN_H_INCLUDED

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

typedef struct
{
    tNodo *pri;
    tNodo *ult;
}Cola;

void crearCola(Cola *pc);
int ponerEnCola(Cola *pc, const void *dato, unsigned tamBytes);
int sacarDeCola(Cola *pc, void *dato, unsigned tamBytes);
int verCola(const Cola *pc, void *dato, unsigned tambytes);
int colaVacia(const Cola *pc);
void vaciarCola(Cola *pc);
int colaLlena(Cola *pc, unsigned tamBytes);



#endif // COLADIN_H_INCLUDED
