#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM_VEC 10
#define NOM_ARCH_EST "Estudiantes.dat"
#define NOM_ARCH_EMP "Empleados.dat"
typedef struct
{
    int dni;
    char apellido[TAM_VEC];
    char nombre[TAM_VEC];
    double sueldo;
} Empleado;


typedef struct
{
    int dni;
    char apellido[TAM_VEC];
    char nombre[TAM_VEC];
    float promedio;
} Estudiante;


int crearLote();
void mostrarArchivoGenerico(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato));

void imprimirEstudiante(const void *dato);
void imprimirEmpleado(const void *dato);

void actualizar(const char *nomArchAct, const char *nomArch, unsigned tamBytesAct, unsigned tamBytes, int comparacion(const void *dato1, const void *dato2));
void subirSueldos(const void *d1, const void *d2, FILE *pEmp, FILE *pEst, int comparacion(const void *dato1, const void *dato2));
int compararApeNomDNI(const void *dato1, const void *dato2);

#endif // FUNCIONES_H_INCLUDED
