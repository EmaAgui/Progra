#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *miMemmove(void *s1, const void *s2, size_t n);
void *miMemcpy(void *s1, const void *s2, size_t n);

int main()
{
    char dest[] = "oldstring";
    const char src[]  = "newstring";

    printf("Before memmove dest = %s, src = %s\n", dest, src);
    miMemmove(dest, src, 9);
    printf("After memmove dest = %s, src = %s\n", dest, src);



//   const char src[50] = "http://www.tutorialspoint.com";
//   char dest[50];
//   strcpy(dest,"Heloooo!!");
//   printf("Before memcpy dest = %s\n", dest);
//   miMemcpy(dest, src, strlen(src)+1);
//   printf("After memcpy dest = %s\n", dest);

    return 0;
}

/**
    Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por s1
    La función retorna el valor de s1. Si al copiar un objeto al otro se superponen, entonces
    el comportamiento no está definido.
**/
void *miMemcpy(void *s1, const void *s2, size_t n)
{
    if(s1 == NULL)
        return NULL;

    char *charS1 = (char*)s1;
    char *charS2 = (char*)s2;
    int i;

    for(i = 0; i < n; i++)
        *(charS1 + i) = *(charS2 + i);

    return s1;
}


/**
    Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por
    s1. Sin embargo, se asegura de que no estén superpuestos. Por esta razón, copia los
    caracteres a un array/arreglo temporalmente. Después vuelve a copiar del array
    temporal al objeto en cuestión.
**/
void *miMemmove(void *s1, const void *s2, size_t n)
{
    char *pS1 = (char*)s1;
    const char *pS2 = (const char*)s2;

    char *copia = malloc(sizeof(char) * n);

    if(copia == NULL)
        return NULL;

    int i;

    for(i = 0; i < n; i++)
        *(copia + i) = *(pS2 + i);

    for(i = 0; i < n; i++)
        *(pS1 + i) = *(copia + i);

    free(copia);

    return s1;
}
