#ifndef STRINGH_H_INCLUDED
#define STRINGH_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


/**
*   Calcula el numero de caracteres de la cadena apuntada por s.
**/
size_t miStrlen(const char *s);


/**
*   Copia la cadena apuntada por s2 (incluyendo el car�cter nulo) a la cadena
*   apuntada por s1.
*/
char *miStrcpy(char *s1, const char *s2);


/**
*  Localiza la primera aparicion de c (convertido a unsigned char) en la
*  cadena apuntada por s (incluyendo el car�cter nulo).
*/
char *miStrchr(char *s, int c);


/**
*   A�ade una copia de la cadena apuntada por s2 (incluyendo el car�cter nulo) al
*   final de la cadena apuntada por s1. El car�cter inicial de s2 sobrescribe el
*   car�cter nulo al final de s1.
*/
char *miStrcat(char*s1, const char *s2);


/**
*   Compara la cadena apuntada por s1 con la cadena apuntada por s2.
**/
int miStrcmp(const char *s1, const char *s2);


/**
*   Compara la cadena apuntada por s1 con la cadena apuntada por s2. Is not case sensitive.
**/
int miStrcmpi(const char *s1, const char *s2);


/**
*   Copia no m�s de n caracteres (caracteres posteriores al car�cter nulo no son copiados)
*   de la cadena apuntada por s2 a la cadena apuntada por s1
**/
char *miStrncpy(char *s1, const char *s2, size_t n);


/**
*   Localiza la �ltima aparici�n de c (convertido a unsigned char) en la cadena apuntada
*   por s (incluyendo el car�cter nulo).
**/
char *miStrrchr(char *s, int c);


/**
*   Compara no m�s de n caracteres (caracteres posteriores al car�cter nulo no se tienen en
*   cuenta) de la cadena apuntada por s1 con la cadena apuntada por s2.
**/
int miStrncmp(const char *s1, const char *s2, size_t n);


/**
*   Localiza la primera aparici�n en la cadena apuntada por s1 de la secuencia de
*   caracteres (excluyendo el car�cter nulo) en la cadena apuntada por s2.
**/
char *miStrstr(const char *s1, const char *s2);



#endif // STRINGH_H_INCLUDED
