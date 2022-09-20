#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAM 20


size_t miStrlen(const char *cadena);

char *miStrcpy(char *destino, const char *origen);

char *miStrchr(char *cadena, int c);
char *miStrcat(char *s1, const char *s2);
int miStrcmp(const char *s1, const char *s2);
int miStrcmpi(const char *s1, const char *s2);

char *miStrstr(const char *s1, const char *s2);
char *miStrncpy(char *s1, const char *s2, size_t n);
char *miStrrchr(char *s, int c);

int miStrncmp(const char *s1, const char *s2, size_t n);

#endif // CADENA_H_INCLUDED
