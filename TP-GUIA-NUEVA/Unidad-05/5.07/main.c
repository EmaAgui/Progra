#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMB_ARCH_EMP "Empleados.dat"
#define NOMB_ARCH_EST "Estudiantes.dat"


typedef struct
{
    int dni;
    char nombre[30];
    char apellido[30];
    double sueldo;
}Empleado;

typedef struct
{
    int dni;
    char nombre[30];
    char apellido[30];
    float promedio;
}Estudiante;

int compararEstEmp(Estudiante *est, Empleado *emp);
void actualizarSueldo(const char *nombreEmp, const char *nombreEst);
void mostrarEstudiante(const void *dato);
void mostrarEmpleados(const void *dato);
void leerArchGen(const char *nombreArchivo, size_t cantBytes,void mostrarArchivo(const void *dato));
void crearLote(const char *nombreEmp, const char *nombreEst);



int main()
{
    crearLote(NOMB_ARCH_EMP, NOMB_ARCH_EST);
    leerArchGen(NOMB_ARCH_EMP, sizeof(Empleado), mostrarEmpleados);
    printf("\n");
    leerArchGen(NOMB_ARCH_EST, sizeof(Estudiante), mostrarEstudiante);

    printf("\n");    printf("\n");
    actualizarSueldo(NOMB_ARCH_EMP, NOMB_ARCH_EST);
    leerArchGen(NOMB_ARCH_EMP, sizeof(Empleado), mostrarEmpleados);


    return 0;
}


int compararEstEmp(Estudiante *est, Empleado *emp)
{
    int cmp = strcmp(est->apellido, emp->apellido);

    if (!cmp)
    {
        cmp = strcmp(est->nombre, emp->nombre);
        if (!cmp)
            cmp = est->dni - emp->dni;
    }

    return cmp;
}


void actualizarSueldo(const char *nombreEmp, const char *nombreEst)
{
    Estudiante est;
    Empleado emp;
    FILE *pEmp, *pEst;

    pEmp = fopen(nombreEmp, "r+b");
    pEst = fopen(nombreEst, "rb");

    if(!pEmp || ! pEst)
    {
        fclose(pEmp);
        fclose(pEst);
        return;
    }

    fread(&emp, sizeof(emp), 1, pEmp);
    fread(&est, sizeof(est), 1, pEst);

    while(!feof(pEmp) && !feof(pEst))
    {
        int cmp = compararEstEmp(&est, &emp);
        if(cmp == 0 && est.promedio > 7)
        {
            emp.sueldo *= 1.0728;
            fseek(pEmp, -(long)sizeof(Empleado), SEEK_CUR);
            fwrite(&emp, sizeof(Empleado), 1, pEmp);
            fseek(pEmp, 0L, SEEK_CUR);
            fread(&emp, sizeof(emp), 1, pEmp);
            fread(&est, sizeof(est), 1, pEst);
        }
        else
        {
            if(compararEstEmp(&est, &emp) > 0)
                fread(&emp, sizeof(emp), 1, pEmp);
            else
                fread(&est, sizeof(est), 1, pEst);
        }
    }

    fclose(pEmp);
    fclose(pEst);
}


void mostrarEstudiante(const void *dato)
{
    Estudiante *est = (Estudiante*)dato;

    printf("DNI: [%d], Apellido: [%s], Nombre: [%s], Promedio: [%.2f]\n",
           est->dni, est->apellido, est->nombre, est->promedio);
}


void mostrarEmpleados(const void *dato)
{
    Empleado *emp = (Empleado*)dato;

    printf("DNI: [%d], Apellido: [%s], Nombre: [%s], Sueldo: [%.2f]\n",
           emp->dni, emp->apellido, emp->nombre, emp->sueldo);
}


void leerArchGen(const char *nombreArchivo, size_t cantBytes,void mostrarArchivo(const void *dato))
{
    void *dato = malloc(cantBytes);
    FILE *pArch = fopen(nombreArchivo, "rb");

    if(!dato || !pArch)
        return;

    fread(dato, cantBytes, 1, pArch);

    while(!feof(pArch))
    {
        mostrarArchivo(dato);
        fread(dato, cantBytes, 1, pArch);
    }

    free(dato);
    fclose(pArch);
}


void crearLote(const char *nombreEmp, const char *nombreEst)
{
    FILE *pEmp, *pEst;
    Empleado vEmp[] =
    {
        {12345678, "Nombre01", "Apellido01", 150000},
        {12316678, "Nombre05", "Apellido05", 550000},
        {92156678, "Nombre06", "Apellido06", 450000},
        {14845678, "Nombre09", "Apellido09", 120000},
        {19645678, "Nombre10", "Apellido10", 300000}
    };
    Estudiante vEst[] =
    {
        {12345678, "Nombre01", "Apellido01", 10},
        {99553658, "Nombre02", "Apellido02", 7},
        {14816678, "Nombre03", "Apellido03", 5},
        {92156678, "Nombre06", "Apellido06", 4},
        {14845678, "Nombre09", "Apellido09", 8},
        {29555678, "Nombre12", "Apellido12", 7},
    };

    pEmp = fopen(nombreEmp, "wb");
    pEst = fopen(nombreEst, "wb");

    if(!pEmp || !pEmp)
        return;

    fwrite(vEmp, sizeof(vEmp), 1, pEmp);
    fwrite(vEst, sizeof(vEst), 1, pEst);

    fclose(pEmp);
    fclose(pEst);

}


