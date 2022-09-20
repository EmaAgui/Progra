#include "Cadena.h"


int miStrncmp(const char *s1, const char *s2, size_t n)
{
    int cant = 0;

    while(*s1 && *s1 == *s2 && cant < n)
    {
        s1++;
        s2++;
        cant++;
    }

    return (int)(*(char *)s1 - *(char *)s2);
}


char *miStrrchr(char *s, int c)
{
    char *aux = (char*)s;

    while(*aux)
        aux++;

    while(aux > s && *aux != c)
        aux--;

    return *aux == c ? aux : NULL;
}


char *miStrncpy(char *destino, const char *origen, size_t n)
{
    char *auxiliar = destino;
    int cant = 0;

    while(*origen !='\0' && cant < n)
    {
        *(destino++) = *(origen++);
        cant++;
    }

    *destino='\0';

    return auxiliar;
}


char *miStrstr(const char *s1, const char *s2)
{
    int tam = miStrlen(s2);

    while(*s1 && miStrncmp(s1, s2, tam))
        s1++;

    return *s1 ? (char*)s1 : NULL;
}


int miStrcmpi(const char *s1, const char *s2)
{
    while(*s1 && toupper(*s1) == toupper(*s2))
    {
        s1++;
        s2++;
    }

    return (int)(*(char *)s1 - *(char *)s2);
}


int miStrcmp(const char *s1, const char *s2) ///Comparo caracter a caracter
{
    while(*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (int)(*(char *)s1 - *(char *)s2);
}


char *miStrcat(char *destino, const char *origen)
{
    char *auxiliar = destino;

    while(*destino != '\0')
        destino++;

    while(*origen != '\0')
        *(destino++) = *(origen++);

    *destino = '\0';

    return auxiliar;
}


char *miStrchr(char *cadena, int c)
{
    while(*cadena != (char)c && *cadena != '\0')
        cadena++;

    return *cadena != '\0'? cadena : NULL;
}


char *miStrcpy(char *destino, const char *origen)
{
    char *auxiliar = destino;

    while(*origen != '\0')
    {
        *destino = *origen;
        destino++;
        origen++;
    }

    *destino='\0';

    return auxiliar;
}


size_t miStrlen(const char *cadena)
{
    int cantCarac = 0;

    while(*cadena != '\0')
    {
        cantCarac++;
        cadena++;
    }

    return cantCarac;
}
