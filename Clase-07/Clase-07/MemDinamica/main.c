#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIL 5
#define COL 5

/**
    Punteros void* (Genericos)
    Punteros Funcion (Genericos)

    Memoria Dinamica
        malloc
        realloc: vuelve a asignar memoria dinamica sino alcanza, siempre asignarle a un puntero a la
                 variable, porque puedo perder la direccion de la variable sino tengo espacio en el heap
                 Sirve para Hacer una funcion concatenar
         void *realloc(void *ptr, size_t tamanyo);
        calloc

              ->Texto
            /
    Archivos
            \
             ->Binario

    Estructura de Datos
        Pilas
        Colas
        Listas
        Arboles
**/


void destruirMatrizEnteros(int **mat, int filas);
int **crearMatrizEnteros(int filas, int columnas);
void mostrarMat(int **mat, int filas, int columnas);
void *miMalloc(size_t tam);
void cargarMatrizEnt(int **mat, int filas, int columnas);


int main()
{
//    char cad[] = "Hola";
//    char *cad = malloc(5);
//    strcpy(cad, "Hola");
//
//    char cad2[] = "Mundo";
    int **mat = crearMatrizEnteros(FIL, COL);

    cargarMatrizEnt(mat, FIL, COL);

    mostrarMat(mat, FIL, COL);

    destruirMatrizEnteros(mat, FIL);
    mostrarMat(mat, FIL, COL);

    return 0;
}


void cargarMatrizEnt(int **mat, int filas, int columnas)
{
    int i, j;

    for(i = 0; i < FIL; i++)
    {
        for(j = 0; j < COL; j++)
           mat[i][j] = i * 10 + j;
    }
}


void *miMalloc(size_t tam)
{
    if(rand() % 5 == 3)///1 de cada 5 falla
        return NULL;
    else
        return malloc(tam);
}
#define malloc miMalloc


void mostrarMat(int **mat, int filas, int columnas)
{
    int i, j;

    for(i = 0; i < FIL; i++)
    {
        for(j = 0; j < COL; j++)
            printf("%02d ", mat[i][j]);
        printf("\n");
    }
}


void destruirMatrizEnteros(int **mat, int filas)
{
    int i;
    for(i = 0; i < filas; i++)
    {
        free(mat[i]);
        i++;
    }
        free(mat);
}


int **crearMatrizEnteros(int filas, int columnas)
{
    /// mat** Declaro puntero doble a entero, vector de punteros a enteros

    int **mat;
    int i;

    mat = malloc(sizeof(int*) * filas);

    if(!mat)
        return NULL;

    for(i = 0; i < columnas; i++)
    {
        mat[i] = malloc(sizeof(int*) * columnas);

        if(!*mat) /// si no hay espacio en el heap
        {
            for(i = i - 1; i >= 0; i--) ///i - 1 porque ya se que el ultimo malloc fallo i >= 0 porque no puede ser menor a 0
                free(mat[i]);
            free(mat);
            return NULL;
        }
    }

    return mat;
}



/**
    char a debe ser solicitada con maloc tambien, nose puede mezclar pila con heap
**/
//void concatenar(char *a, const char *b)
//{
//}
