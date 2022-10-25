#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define esLetraMinuscula(X)   ((X) >= 'a' && (X) <= 'z')
#define esLetra(X)  ((X) >= 'a' && (X) <= 'z' || (X) >= 'A' && (X) <= 'Z')



bool desofuscarArchivo(FILE* archivo, char* nombreArchivo);
char* desofuscarLinea(char* cadena);
void invertirPalabra(char* cadena);

#endif // HEADER_H_INCLUDED
