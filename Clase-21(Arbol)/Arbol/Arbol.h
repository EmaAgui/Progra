#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define minimo(x, y) (x < y)? x : y

typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct sNodo *izq;
    struct sNodo *der;
}tNodo;


typedef tNodo *Arbol;


void crearArbol(Arbol *pa);
int insertarEnArbol(Arbol *pa, const void *dato, unsigned tamBytes, int cmp(const void *d1, const void *d2));


int contarNodos(Arbol *pa);
unsigned alturaArbol(const Arbol *pa);
int esArbolAvl(const Arbol *pa);

tNodo **buscarNodoAElim(const Arbol *pa, const void *dato, int comp(const void *d1, const void *d2));
tNodo ** mayorNodoArbol(const Arbol *pa);
tNodo ** menorNodoArbol(const Arbol *pa);

int eliminarNodoRaiz(Arbol *pa);
int eliminarElemArbol(Arbol *pa, void *dato, unsigned tambytes, int comp(const void *d1, const void *d2));


void mostrarArbolInOrden(Arbol *pa,int n, void accion(const void *d1));
void mostrarArbolPreOrden(Arbol *pa, void accion(void *d1));
void mostrarArbolPosOrden(Arbol *pa, void accion(const void *d1));
void vaciarArbol(Arbol *pa);

#endif // ARBOL_H_INCLUDED
