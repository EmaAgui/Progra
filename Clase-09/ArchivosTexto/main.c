#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Rename/Remove
    Maestro.dat

    Novedades.dat  tiene un campo mas alta o baja

    MaestroActulizado
**/

typedef struct
{
    unsigned dni;
    char nya[20];
    double sueldo;
} Empleado;

typedef struct
{
    Empleado emp;
    char novedad; ///Alta o Baja
} Novedad;


int crearLote();
int abrirArchivo(FILE **pArch, const char *nomArch, const char *modo);
void mostrarArchivoGenericoBin(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato));
int compararDni(const void *dato1, const void *dato2);
void mostrarEmpleado(const void *dato);
void recorrerAct(FILE *pfMae, FILE *pfNov, FILE *pfAct, int cmp(const void *dato1, const void *dato2));
void mostrarNovedades(const void *dato);
void mostrarArch();

int main()
{
    if(!crearLote())
        return -1;

    FILE *pMae, *pNov, *pMaeAc;

    if(!abrirArchivo(&pMae, "Maestro.dat", "rb"))
    {
        printf("No se pudo abrir maestro");
        return -10;
    }

    if(!abrirArchivo(&pNov, "Novedades.dat", "rb"))
    {
        printf("No se pudo abrir maestro");
        fclose(pMae);
        return -20;
    }

    if(!abrirArchivo(&pMaeAc, "MaestroActualizado.dat", "wb"))
    {
        printf("No se pudo abrir maestro");
        fclose(pMae);
        fclose(pNov);
        return -30;
    }

//    mostrarArchivoGenericoBin("Maestro.dat", sizeof(Empleado), mostrarEmpleado);
//    mostrarArchivoGenericoBin("Novedades.dat", sizeof(Novedad), mostrarNovedades);

    recorrerAct(pMae, pNov, pMaeAc, compararDni);
//    mostrarArchivoGenericoBin("MaestroActualizado.dat", sizeof(Empleado), mostrarEmpleado);

    mostrarArch();

    fclose(pMae);
    fclose(pMaeAc);
    fclose(pNov);

    return 0;
}

void mostrarArch()
{
    FILE *pArch = fopen("MaestroActualizado.dat", "rb");

    if(!pArch)
        return;
    Empleado emp;

    fread(&emp, sizeof(Empleado), 1, pArch);
    while(!feof(pArch))
    {
        printf("DNI[%d], NOMBRE[%s], SUELDO[%.2f]\n", emp.dni, emp.nya, emp.sueldo);
        fread(&emp, sizeof(Empleado), 1, pArch);
    }

    fclose(pArch);
}

void mostrarNovedades(const void *dato)
{
    Novedad emp = *(Novedad*)dato;
    printf("DNI[%d], NOMBRE[%s], SUELDO[%.2f], NOVEDAD[%c]\n", emp.emp.dni, emp.emp.nya, emp.emp.sueldo, emp.novedad);
}


void mostrarEmpleado(const void *dato)
{
    Empleado emp = *(Empleado*)dato;
    printf("DNI[%d], NOMBRE[%s], SUELDO[%.2f]\n", emp.dni, emp.nya, emp.sueldo);
}


int compararDni(const void *dato1, const void *dato2)
{
    Empleado emp = *(Empleado*)dato1;
    Novedad nov = *(Novedad*)dato2;

    return emp.dni - nov.emp.dni;
}


void recorrerAct(FILE *pfMae, FILE *pfNov, FILE *pfAct, int cmp(const void *dato1, const void *dato2))
{
    Empleado mae, maeAct;
    Novedad nov;

    rewind(pfMae);
    rewind(pfNov);
    rewind(pfAct);

    fread(&mae, sizeof(Empleado), 1, pfMae);
    fread(&nov, sizeof(Novedad), 1, pfNov);

    int comp;

    while(!feof(pfMae) && !feof(pfNov))
    {
        if((comp = cmp(&mae, &maeAct)) > 0)
        {
            if(nov.novedad == 'A')
            {
                fwrite(&mae, sizeof(Empleado), 1, pfAct);
            }
            else
            {
                printf("\nERROR");
            }
            fread(&nov, sizeof(Novedad), 1, pfNov);
        }
        else
        {
            if(comp == 0)
            {
                if(nov.novedad == 'A')
                {
                    printf("\nError Alta ya existe");
                    fwrite(&nov.emp, sizeof(Empleado), 1, pfAct);
                }
                if(nov.novedad == 'M')
                {
                    fwrite(&nov.emp, sizeof(Empleado), 1, pfAct);
                }
                fread(&mae, sizeof(Empleado), 1, pfMae);
                fread(&nov, sizeof(Novedad), 1, pfNov);
            }
            else
            {
                fwrite(&mae, sizeof(Empleado), 1, pfAct);
                fread(&mae, sizeof(Empleado), 1, pfMae);
            }
        }
    }

}


void mostrarArchivoGenericoBin(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato))
{
    void *dato = malloc(tamBytes);

    if(!dato)
        return;

    FILE *pArch = fopen(nomArch, "rb");

    fread(dato, tamBytes, 1, pArch);

    while (!feof(pArch))
    {
        imprimir(dato);
        fread(dato, tamBytes, 1, pArch);
    }

    free(dato);
    fclose(pArch);
}


int abrirArchivo(FILE **pArch, const char *nomArch, const char *modo)
{
    *pArch = fopen(nomArch, modo);
    if (!*pArch)
        return 0;
    return 1;
}


int crearLote()
{
    FILE *pEmp = fopen("Maestro.dat", "wb");
    FILE *pNov = fopen("Novedades.dat", "wb");

    if(!pEmp || !pNov)
        return 0;

    Empleado emp[] =
    {
        {10, "AA", 100},
        {20, "XA", 100},
        {30, "MZ", 300},
        {40, "WH", 500},
        {50, "XN", 300},
        {60, "EM", 200},
    };

    Novedad nov[] =
    {
        {{5, "ZX", 300}, 'A'},
        {{10, "AA", 150}, 'M'},
        {{20, "WH", 100}, 'A'},
        {{31, "XA", 200}, 'M'},
        {{40, "aH", 500}, 'B'},
        {{51, "XA", 300}, 'B'},
        {{70, "WX", 500}, 'A'},
        {{78, "MZ", 200}, 'B'},
    };

    fwrite(emp, sizeof(emp), 1, pEmp);
    fwrite(nov, sizeof(nov), 1, pNov);

    fclose(pEmp);
    fclose(pNov);

    return 1;
}
