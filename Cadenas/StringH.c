#include "StringH.h"
#include "String.h"
#include <ctype.h>


char *miStrstr(const char *s1, const char *s2)
{
    int tam = miStrlen(s2);

    while(*s1 != '\0' && strncmp(s1, s2, tam) != 0)
        s1++;

    return *s1 != '\0' ? (char*)s1 : NULL;
}


int miStrncmp(const char *s1, const char *s2, size_t n)
{
    int cant = 0;

    if(n == 0)
        return 0;

    while( *s1 != '\0' && *s1 == *s2  && cant < n)
    {
        s1++;
        s2++;
        cant++;
    }

    int cmp = (int)*(char*)s1 - (int)*(char*)s2;

    if(cmp == 0)
        return 0;

    if(cmp  < 0)
        return -1;

    return 1;
}


char *miStrrchr(char *s, int c)
{
    char *aux = s;

    while(*aux != '\0')
        aux++;

    while(aux > s && *aux != (char)c)
        aux--;

    return *aux == c ? aux : NULL;
}


char *miStrncpy(char *s1, const char *s2, size_t n)
{
    char *aux = s1;
    size_t cant = 0;

    while(*s2 != '\0' && cant < n)
    {
        *s1 = *s2;
        s1++;
        s2++;
        cant++;
    }

    *s1 = '\0';

    return aux;
}


int miStrcmpi(const char *s1, const char *s2)
{
    while(*s1 != '\0' &&  toupper(*s1) == toupper(*s2))
    {
        s1++;
        s2++;
    }

    int cmp = (int)*(char*)s1 - (int)*(char*)s2;

    if(cmp  > 0)
        return 1;

    if(cmp  < 0)
        return -1;

    return 0;
}


int miStrcmp(const char *s1, const char *s2)
{
    while(*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    int cmp = (int)*(char*)s1 - (int)*(char*)s2; ///convierto a char* y accedo al contenido

    if(cmp  > 0)
        return 1;

    if(cmp  < 0)
        return -1;

    return 0;
}


char *miStrcat(char *s1, const char *s2)
{
    char *aux = s1;

    while(*s1 != '\0')
        s1++;

    while(*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return aux;
}


char *miStrchr(char *s, int c)
{
    while(*s != (char)c && *s != '\0')
        s++;

    return *s == '\0'? NULL : s;
}


char *miStrcpy(char *s1, const char *s2)
{
    char *aux = s1; ///aux es el puntero al primer caracter de s1.

    while(*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return aux; ///Devuelvo el puntero al primer caracter de s1.
}


///size_t miStrlen(const char *s)
size_t miStrlen(const char *s)
{
    size_t cantLetras = 0;

    while(*s != '\0')
    {
        cantLetras++;
        s++;
    }

    return cantLetras;
}
