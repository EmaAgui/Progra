#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dni;
    char nomYApe[20];
} tAlumno;


char *copiaCadena(const char *origen);
void *copiaCosas(const void *elemento);

int main()
{
    int *px;

    px = (int*)malloc(sizeof(int)); ///Reservo memoria para un entero

    if(!px) ///Si no puede reservar retorna error
        return -1;

    *px = 5;
    printf("%d", *px);

    free(px); ///Libero Memoria

    printf("\n%d", *px);

    float *vec = malloc(sizeof(float) * 20); ///Reservo para 20 numeros float
    printf("\n%d", (int)sizeof(float) * 20);

    if(!vec)
        return -1;

    free(vec);

    char cad[] = "Hola Mundo";
    char *result;

    result = copiaCadena(cad);

    printf("\n%s", result);///Hola Mundo
    free(result);


    tAlumno alum = {123, "Ema1"} ;
    tAlumno *pAlum;

    pAlum = copiaCosas(&alum);

    printf("\n%d %s", pAlum->dni, pAlum->nomYApe);
    free(pAlum);

    printf("\n\n%d",  (int)(sizeof(tAlumno)));


    return 0;
}


///Les queda para desarrollar el metodo void* copiaCosas(const void*) que,
///utilizando memoria dinamica realiza copias de cualquier elemento pasado como parametro.
void *copiaCosas(const void *elemento)
{
    void *pCopia;

    printf("\n\n%d\n", (int)(sizeof(elemento)));
    pCopia = malloc(sizeof(elemento));

    if(!pCopia)
        return NULL;

    memcpy(pCopia, elemento, (int)sizeof(elemento));
    return pCopia;
}


char *copiaCadena(const char *origen)
{
    int cantCarac = (strlen(origen)) * sizeof(char);
    char *aux = malloc(cantCarac + 1);

    if(!aux)
        return NULL;

    while(*origen)
    {
        *aux = *origen;
        origen++;
        aux++;
    }
    *aux = '\0';
    aux -= cantCarac;


    return aux;
}
