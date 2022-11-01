#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOM_ARCH_ALUM "Alumnos.dat"


typedef struct
{
    int dni;
    char nomYApe[20];
    float promedio;
} Alumno;

/**
    ftell obtiene el valor del cabezal indicado en bytes
    sacar cantidad de registros
        fseek(pf, 0, seek_end);
        ftell(pf) / tam(sizeof(struct)) = cantReg

    Hacer funcion int fBusquedaBinaria(const char*nombreArchivo, void *info, )
        archivo ordenado por dni

    PARARSE EN LA MITAD DEL ARCHIVO

**/


int compararAlumno(const void *dato1, const void *dato2);
int crearLote(const char *nombreArch);
int fBusquedaBinaria(const char *nombreArchivo, void *info, unsigned tamBytes, int comparacion(const void *dato1, const void *dato2));
void mostrarArchivoBin(FILE *pArchBin, unsigned tamBytes, void mostrar(const void *dato));
void mostrarAlumno(const void *dato);
int abrirArchivo(FILE **pARch, const char *nombre, const char *modo);


int main()
{
    if(!crearLote(NOM_ARCH_ALUM))
        return -10;

    FILE *pArch;

    if(!abrirArchivo(&pArch, NOM_ARCH_ALUM, "rb"))
        return -20;

    mostrarArchivoBin(pArch, sizeof(Alumno), mostrarAlumno);

    Alumno alum;
    alum.dni = 10;

    printf("Dni a buscar: %d\n", alum.dni);

    if(fBusquedaBinaria(NOM_ARCH_ALUM, &alum, sizeof(Alumno), compararAlumno))
        printf("%d %s %.2f\n", alum.dni, alum.nomYApe, alum.promedio);
    else
        printf("No se Encontro\n");


    return 0;

}


int compararAlumno(const void *dato1, const void *dato2)
{
    Alumno alu1 = *(Alumno*)dato1;
    Alumno alu2 = *(Alumno*)dato2;

    return  alu1.dni - alu2.dni;
}


int fBusquedaBinaria(const char *nombreArchivo, void *info, unsigned tamBytes, int comparacion(const void *dato1, const void *dato2))
{
    FILE *pArch = fopen(nombreArchivo, "rb");

    void *alu = malloc(tamBytes);

    if(!pArch || !alu)
        return 0;

    int cantRegistros, li, ls, pm, comp;

    fseek(pArch, 0, SEEK_END); ///PARARSE AL FINAL DEL ARCHIVO
    cantRegistros = ftell(pArch) / tamBytes; ///OBTENER CANTIDAD DE REGISTROS

    li = 0;
    ls = cantRegistros - 1;
    pm = li +(ls +li) / 2;

    fseek(pArch, pm * tamBytes, SEEK_CUR);

    fread(alu, tamBytes, 1, pArch);

    while ( li <= ls) ///MIENTRAR NO ENCUENTRE EL REGISTRO
    {
        comp = comparacion(alu, info);
        if(comp > 0) /// alu >
        {
            li = 0;
            ls = pm - 1;
            pm = ls;
        }

        if(comp < 0) ///alu <
        {
            li = pm + 1;
            ls = ls;
            pm = li;
        }

        if (comp == 0)
        {
            memcpy(info, alu, tamBytes);
            free(alu);
            return 1;
        }

        fseek(pArch, pm * tamBytes, SEEK_SET);
        fread(alu, tamBytes, 1, pArch);
    }

    free(alu);
    return 0;
}


int abrirArchivo(FILE **pArchBin, const char *nombre, const char *modo)
{
    *pArchBin = fopen(nombre, modo);

    if(!*pArchBin)
        return 0;

    return 1;
}


void mostrarAlumno(const void *dato)
{
    Alumno alu = *(Alumno*)dato;

    printf("DNI: [%d], Nombre y Apellido: [%s], Promedio: [%.2f]\n", alu.dni, alu.nomYApe, alu.promedio);
}


void mostrarArchivoBin(FILE *pArchBin, unsigned tamBytes, void mostrar(const void *dato))
{
    void *dato = malloc(tamBytes);

    if(!dato)
        return;

    rewind(pArchBin);

    fread(dato, tamBytes, 1, pArchBin);
    while(!feof(pArchBin))
    {
        mostrar(dato);
        fread(dato, tamBytes, 1, pArchBin);
    }
    free(dato);
}


int crearLote(const char *nombreArch)
{
    FILE *pArch = fopen(nombreArch, "wb");

    if(!pArch)
        return 0;

    Alumno vAlum[] =
    {
        {10, "Adam Levine", 9.9},
        {20, "Mars Bruno ", 10},
        {30, "Freddie Mercury", 8.5},
        {40, "Taylor Roger", 6.4},
        {50, "Deacon John", 7.8},
        {60, "May Brian", 4.5},
        {70, "Adam Lambert", 2}
    };

    fwrite(vAlum, sizeof(vAlum), 1, pArch);

    fclose(pArch);

    return 1;
}


int trozarAlumnoVar(char *cad, Alumno *alu)
{
    char *pos = strrchr(cad, '|'); ///Busca el ultimo |
    if(!pos)
        return 0;
    sscanf(pos + 1, "%f", &alu->promedio);
    *pos = '\0';

    pos = strchr(cad, '|');
    if(!pos)
        return 0;
    strcpy(alu->nomYApe, pos + 1);
    *pos = '\0';


    sscanf(cad, "%d", &alu->dni);

    return 1;
}


void trozarAlumnoFijo(char *cad, Alumno *alu)
{
    char campo[21];

    strncpy(campo, cad, 10); /// DNI
    campo[10] = '\0';   /// Fin de cadena
    sscanf(campo, "%d", &alu->dni);

    cad += 10;
    strncpy(alu->nomYApe, cad, 20);
    alu->nomYApe[20] = '\0';

    cad += 20;
    sscanf(cad, "%f", &alu->promedio);
}
