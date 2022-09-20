#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int abrirArchivo(FILE **pArch, const char *nomArch, const char *modo);
void mostrarArchivoGenericoBin(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato));

#endif // ARCHIVOS_H_INCLUDED
