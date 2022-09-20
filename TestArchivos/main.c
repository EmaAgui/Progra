#include <stdio.h>
#include <stdlib.h>

#include "../Archivos/Archivos.h"

#define NOM_ARCH_EST "Estudiantes.dat"
#define NOM_ARCH_EMP "Empleados.dat"
#define TAM_VEC 10

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


int imprimirEstudiante(const void *dato);


int main()
{
    FILE *pArchEst;

    if(abrirArchivo(&pArchEst, NOM_ARCH_EST, "rb"))
        mostrarArchivoGenericoBin(NOM_ARCH_EST, sizeof(Estudiante), imprimirEstudiante);
    return 0;
}


int imprimirEstudiante(const void *dato)
{
    if(dato == NULL)
    {
        printf("DNI\t\tApellido\tNombre\t\tPromedio\n");
        return;
    }

    Estudiante est = *(Estudiante*)dato;

    printf("%d %15s %13s %15.2f\n", est.dni, est.apellido, est.nombre, est.promedio);
}
