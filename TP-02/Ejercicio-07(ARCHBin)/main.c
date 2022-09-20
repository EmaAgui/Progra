#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define TAM_VEC_CHAR 20
#define NOM_EST "Estudiantes.dat"
#define NOM_EMP "Empleados.dat"



typedef struct
{
    unsigned dni;
    char apellido[TAM_VEC_CHAR];
    char nombre[TAM_VEC_CHAR];
    double sueldo;
} Empleado;


typedef struct
{
    unsigned dni;
    char apellido[TAM_VEC_CHAR];
    char nombre[TAM_VEC_CHAR];
    float promedio;
} Estudiante;


int crearLotePrueba();
int abrirArchivo(FILE **arch, const char *nombreArch, const char *modo);
void actualizar(FILE *archEst, FILE *archEmp, int comparacion(const void *dato1, const void *dato2));

int compararApeNomDni(const void *dato1, const void *dato2);
void mostrarArchivoGenerico(FILE *pArch, unsigned tamBytes, void mostrar(const void *dato));
void mostrarEmpleado(const void *dato);
void mostrarEstudiante(const void *dato);


int main()
{
    FILE *archEst, *archEmp;

    if(!crearLotePrueba())
        return -1;


    if(!abrirArchivo(&archEst, NOM_EST, "rb"))
    {
        printf("No se pudo abir %s", NOM_EST);
        return -1;
    }


    if(!abrirArchivo(&archEmp, NOM_EMP, "r+b"))
    {
        printf("No se pudo abir %s", NOM_EMP);
        fclose(archEst);
        return -1;
    }

    printf("Archivo Original EMPLEADOS\n");
    mostrarArchivoGenerico(archEmp, sizeof(Empleado), mostrarEmpleado);

    printf("\nArchivo Original ESTUDIANTES\n");
    mostrarArchivoGenerico(archEst, sizeof(Estudiante), mostrarEstudiante);



    printf("Despues de Actualizar\n");
    actualizar(archEst, archEmp, compararApeNomDni);

    mostrarArchivoGenerico(archEmp, sizeof(Empleado), mostrarEmpleado);
    printf("\n");


    fclose(archEst);
    fclose(archEmp);

    return 0;
}


void actualizar(FILE *archEst, FILE *archEmp, int comparacion(const void *dato1, const void *dato2))
{
    Empleado emp;
    Estudiante est;

    rewind(archEmp);
    rewind(archEst);

    float aumento = 1.0728;


    fread(&est, sizeof(Estudiante), 1, archEst);
    fread(&emp, sizeof(Empleado), 1, archEmp);

    while(!feof(archEst) && !feof(archEmp))
    {
        if((compararApeNomDni(&emp, &est)) == 0)
        {
            if(est.promedio >= 7)
            {
                emp.sueldo *= aumento;
                fseek(archEmp, -(long)sizeof(Empleado), SEEK_CUR);
                fwrite(&emp, sizeof(Empleado), 1, archEmp);
                fseek(archEmp, 0L, SEEK_CUR);
            }
            fread(&emp, sizeof(Empleado), 1, archEmp);
            fread(&est, sizeof(Estudiante), 1, archEst);
        }
        else
        {
            if((compararApeNomDni(&emp, &est)) > 0)
                fread(&est, sizeof(Estudiante), 1, archEst);
            else
                fread(&emp, sizeof(Empleado), 1, archEmp);
        }
    }
}


int compararApeNomDni(const void *dato1, const void *dato2)
{
    Empleado emp = *(Empleado*)dato1;
    Estudiante est = *(Estudiante*)dato2;

    int cmp = strcmp(emp.apellido, est.apellido);

    if(!cmp)
    {
        cmp = strcmp(emp.nombre, est.nombre);
        if(!cmp)
            cmp = emp.dni - est.dni;
    }

    return cmp;
}


void mostrarEstudiante(const void *dato)
{
    Estudiante est = *(Estudiante*)dato;
    printf("DNI[%d], NOMBRE[%s], APELLIDO[%s], PROMEDIO[%.2f]\n", est.dni, est.nombre, est.apellido, est.promedio);

}

void mostrarEmpleado(const void *dato)
{
    Empleado emp = *(Empleado*)dato;
    printf("DNI[%d], NOMBRE[%s], APELLIDO[%s], SUELDO[%.2f]\n", emp.dni, emp.nombre, emp.apellido, emp.sueldo);

}


void mostrarArchivoGenerico(FILE *pArch, unsigned tamBytes, void mostrar(const void *dato))
{
    rewind(pArch);

    void *dato = malloc(tamBytes);

    fread(dato, tamBytes, 1, pArch);

    while(!feof(pArch))
    {
        mostrar(dato);
        fread(dato, tamBytes, 1, pArch);
    }
    free(dato);
}


int crearLotePrueba()
{
    FILE *pEst = fopen("Estudiantes.dat", "wb");
    FILE *pEmp = fopen("Empleados.dat", "wb");

    Estudiante est[] =
    {
        {16753951, "Barnes","Bucky", 1},
        {26753951, "Dixon", "Daryl", 6.4},
        {14725896, "Greene", "Hershel", 5.5},
        {36918310, "Maximoff", "Wanda", 7.82},
        {12553942, "Milburn", "Otis", 10},
        {39728182, "Olsen", "Elizabeth", 6.0},
        {12657486, "Rogfo", "Mathias",9},
        {45999753, "Stark", "Anthony", 10}
    };

    Empleado emp[] =
    {
        {16753951, "Barnes", "Bucky", 16005},
        {26753951, "Dixon", "Daryl", 50200},
        {52369741, "Maximoff","vision", 605030},
        {12657486, "Rogfo", "Mathias", 50000},
        {46852369, "Snow", "jon", 52365},
        {45999753, "Stark", "Anthony", 195321},
        {49883645, "Zasco", "Octopus", 16590}
    };


    if(!pEst || !pEmp)
        return 0;


    fwrite(est, sizeof(est), 1, pEst);
    fwrite(emp, sizeof(emp), 1, pEmp);

    fclose(pEst);
    fclose(pEmp);

    return 1;
}


int abrirArchivo(FILE **arch, const char *nombreArch, const char *modo)
{
    *arch = fopen(nombreArch, modo);
    if(!arch)
        return 0;

    return 1;
}

