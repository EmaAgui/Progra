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


void trozarAlumnoFijo(char *cad, Alumno *alu);
int trozarAlumnoVar(char *cad, Alumno *alu);


int main()
{
    Alumno alu1, alu2;

    char campoFijo[] = "1234567890ABCDLKJHGBNMKLOPIUYH10.50";
    char campoVari[] = "1234567890|ABCDLKJHGBNMKLOPIUYH|10.50";


    trozarAlumnoFijo(campoFijo, &alu1);
    printf("%d %s %.2f\n", alu1.dni, alu1.nomYApe, alu1.promedio);

    trozarAlumnoVar(campoVari, &alu2);
    printf("%d %s %.2f\n", alu2.dni, alu2.nomYApe, alu2.promedio);

    return 0;
}


///char campoVari[] = "1234567890|ABCDLKJHGBNMKLOPIUYH|10.50"
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


///char *cad = "1234567890ABCDLKJHGBNMKLOPIUYH10.50"
/// char campo[21] = ""
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

