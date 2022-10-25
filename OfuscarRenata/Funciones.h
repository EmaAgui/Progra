#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ES_MAYUS(x) (x >= 'A' && x <= 'Z')
#define ES_MINUS(x) (x >= 'a' && x <= 'z')
#define ES_LETRA(x) ES_MAYUS(x) || ES_MINUS(x)

#define minimo(x, y) (x <= y)? x : y


typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct  sNodo *sig;
}tNodo;

typedef tNodo *Pila;

void crearPila(Pila *pp);
int apilar(Pila *pp, const void *dato, unsigned tamBytes);
int desapilar(Pila *pp, void *dato, unsigned tamBytes);
int pilaVacia(const Pila *pp);
int pilaLlena(const Pila *pp, unsigned tamBytes);
void vaciarPila(Pila *pp, unsigned tamBytes);


int abrirArchivo(FILE **pAcrh, const char *nombre, const char *modo);
void ofuscar(FILE *pArch, Pila *pila);
void vocalCorrecta(char *cad);
void correrCaracter(char *cad, int desv);
int myStrlen(char *cad);
char *myStrchr(char *cad, int c);
void ofuscarLinea(char *cad, Pila *pila);


#endif // FUNCIONES_H_INCLUDED
