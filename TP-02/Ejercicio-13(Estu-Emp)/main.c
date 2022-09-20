#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"




int main()
{
    if(!crearLote())
        return -1;

    printf("ANTES DE ACUALIZAR:\n");

    printf("EMPLEADOS:\n");
    mostrarArchivoGenerico(NOM_ARCH_EMP, sizeof(Empleado), imprimirEmpleado);
    printf("ESTUDIANTES:\n");
    mostrarArchivoGenerico(NOM_ARCH_EST, sizeof(Estudiante), imprimirEstudiante);

    printf("EMPLEADOS:\n");
    actualizar(NOM_ARCH_EMP, NOM_ARCH_EST, sizeof(Empleado), sizeof(Estudiante), compararApeNomDNI);
    mostrarArchivoGenerico(NOM_ARCH_EMP, sizeof(Empleado), imprimirEmpleado);

    return 0;
}
