#include "Funciones.h"


int compararApeNomDNI(const void *dato1, const void *dato2)
{
    Empleado emp = *(Empleado *)dato1;
    Estudiante est = *(Estudiante *)dato2;

    int cmp = strcmp(emp.apellido, est.apellido);

    if (!cmp)
    {
        cmp = strcmp(emp.nombre, est.nombre);
        if (!cmp)
            cmp = emp.dni - est.dni;
    }

    return cmp;
}


void subirSueldos(const void *d1, const void *d2, FILE *pEmp, FILE *pEst, int comparacion(const void *dato1, const void *dato2))
{

    Empleado emp = *(Empleado *)d1;
    Estudiante est = *(Estudiante *)d2;
    int cmp;
    float aumento = 1.0728;

    if ((cmp = comparacion(&emp, &est)) == 0)
    {
        if (est.promedio >= 7)
        {
            emp.sueldo *= aumento;
            fseek(pEmp, -(long)sizeof(Empleado), SEEK_CUR);
            fwrite(&emp, sizeof(Empleado), 1, pEmp);
            fseek(pEmp, 0L, SEEK_CUR);
        }
        fread(&emp, sizeof(Empleado), 1, pEmp);
        fread(&est, sizeof(Estudiante), 1, pEst);
    }
    else
    {
        if (cmp > 0)
            fread(&est, sizeof(Estudiante), 1, pEst);
        else
            fread(&emp, sizeof(Empleado), 1, pEmp);
    }
}


void actualizar(const char *nomArchAct, const char *nomArch, unsigned tamBytesAct, unsigned tamBytes, int comparacion(const void *dato1, const void *dato2))
{
    FILE *pArchAct = fopen(nomArchAct, "r+b");
    FILE *pArch = fopen(nomArch, "rb");

    if (!pArchAct || !pArch)
        return;

    Empleado emp;
    Estudiante est;
    int cmp;
    float aumento = 1.0728;

    fread(&emp, tamBytesAct, 1, pArchAct);
    fread(&est, tamBytes, 1, pArch);

    while (!feof(pArchAct) && !feof(pArch))
    {
    subirSueldos(&emp, &est, pArchAct, pArch, comparacion);

//        if ((cmp = comparacion(&emp, &est)) == 0)
//        {
//            if (est.promedio >= 7)
//            {
//                emp.sueldo *= aumento;
//                fseek(pArchAct, -(long)tamBytesAct, SEEK_CUR);
//                fwrite(&emp, tamBytesAct, 1, pArchAct);
//                fseek(pArchAct, 0L, SEEK_CUR);
//            }
//
//                fread(&emp, tamBytesAct, 1, pArchAct);
//                fread(&est, tamBytes, 1, pArch);
//        }
//        else
//        {
//            if (cmp > 0)
//                fread(&est, tamBytes, 1, pArch);
//            else
//                fread(&emp, tamBytesAct, 1, pArchAct);
//        }
    }

    fclose(pArchAct);
    fclose(pArch);
}


void imprimirEmpleado(const void *dato)
{
    Empleado emp = *(Empleado *)dato;

    printf("DNi[%d], Apellido[%s], Nombre[%s], Sueldo[%.2f]\n", emp.dni, emp.apellido, emp.nombre, emp.sueldo);
}


void imprimirEstudiante(const void *dato)
{
    Estudiante est = *(Estudiante *)dato;

    printf("DNi[%d], Apellido[%s], Nombre[%s], Promedio[%.2f]\n", est.dni, est.apellido, est.nombre, est.promedio);
}


void mostrarArchivoGenerico(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato))
{
    void *dato = malloc(tamBytes);

    if (!dato)
        return;

    FILE *pArch = fopen(nomArch, "rb");
    if (!pArch)
    {
        printf("Error al leer %s", nomArch);
        return;
    }

    fread(dato, tamBytes, 1, pArch);
    while (!feof(pArch))
    {
        imprimir(dato);
        fread(dato, tamBytes, 1, pArch);
    }

    free(dato);
    fclose(pArch);
}


int crearLote()
{
    FILE *pEst = fopen("Estudiantes.dat", "wb");
    FILE *pEmp = fopen("Empleados.dat", "wb");

    if (!pEst || !pEmp)
        return 0;

    Estudiante est[] =
        {
            {16753951, "Barnes", "Bucky", 1},
            {26753951, "Dixon", "Daryl", 6.4},
            {14725896, "Greene", "Hershel", 5.5},
            {36918310, "Maximoff", "Wanda", 7.82},
            {12553942, "Milburn", "Otis", 10},
            {39728182, "Olsen", "Elizabeth", 6.0},
            {12657486, "Rogfo", "Mathias", 9},
            {45999753, "Stark", "Anthony", 10}};

    Empleado emp[] =
        {
            {16753951, "Barnes", "Bucky", 16005},
            {26753951, "Dixon", "Daryl", 50200},
            {52369741, "Maximoff", "vision", 605030},
            {12657486, "Rogfo", "Mathias", 50000},
            {46852369, "Snow", "jon", 52365},
            {45999753, "Stark", "Anthony", 195321},
            {49883645, "Zasco", "Octopus", 16590}};

    fwrite(est, sizeof(est), 1, pEst);
    fwrite(emp, sizeof(emp), 1, pEmp);

    fclose(pEst);
    fclose(pEmp);

    return 1;
}
