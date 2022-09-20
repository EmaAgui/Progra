/**
    Permanece en el tiempo
                                -> Literario(Carta, poesia, mail): Normalizar, Desofuscar
                               /
                -> Texto(ASCII)          -> Fijos (Cantidad fija de Car)
              /                \        /
             /                  -> Datos
            /                           \
    Archivos                             -> Variables(C/campo separado por un Car)
            \
             \                -> Registro Tam Fijo(Empleado, alumnos, enteros..)
              \             /
                -> Binarios
                            \
                              -> Registro Variable(NO)

    FILE*, fopen, fclose (rename, remove, unlink)

    Binario
        fread, fwrite, feof, fseek, rewind, ftell, fflush
    Texto
        fgets, fscanf, fprintf,(sscanf), (sprintf)

    1° Abrir el archivo con FILE *fopen(const char *nombre, const char *modo);
        Modo de Apertura: t(texto), b(binario).
            r(lectura: el archivo tiene que existir) (rt o rb)
            w(escritura, si el archivo existe lo reemplaza por uno nuevo)(wt o wb)
            r+b o r+t (igual que r, pero agrega capacidad de escritura).
            w+b o w+t (igual que w pero agrega capacidad de lectura).
            a(no)
        El puntero siempre apunta al principio

                            &alu        sizeof(alu)        1             pf
    Leer  size_t fread(void *puntero, size_t tamanyo, size_t nmemb, FILE *stream);

    int fseek(FILE *stream, long int desplazamiento, int origen);
                                                        seek_cur  desde donde estoy
                                                        seek_set  desde el principio
                                                        seek_end  desde el final


**/
#include <stdio.h>
#include <stdlib.h>

#define TAMNOM 20
#define NOMALUM "alumno.dat"

#define REDONDEO(x) (int)((x) + 0.5)

typedef struct
{
    int dni;
    char noYAp[TAMNOM];
    float promedio;
}tAlumno;

int crearLotePrueba01(const char *archNom);
int crearLotePrueba02(const char *archNom);
void imprimirAlumnos(const void * dato);
void mostrarArchivo(const char *archNom);
void mostrarArchivoGenerico(const char *archNom, unsigned tamBytes, void imprimir(const void *dato));

///Hacer MostrarArchivo
///Funcion Didactica
int abrirArchivo(FILE **pf, const char* nombreArch, const char *modo);
void redondearPromedios(FILE *pf);

void redondeoDeProm(void* dato, unsigned tamBytes, FILE *pf);
void actualizarArchivo(FILE *pf, unsigned tamBytes, void accion(void* dato, unsigned tamBytes, FILE *pf));

int main()
{
    FILE *pf;

    if(crearLotePrueba01(NOMALUM))
        mostrarArchivoGenerico(NOMALUM, sizeof(tAlumno), imprimirAlumnos);

    if(!abrirArchivo(&pf, NOMALUM, "r+b"))
        return 100;

    printf("\n");
//    redondearPromedios(pf);

    actualizarArchivo(pf, sizeof(tAlumno), redondeoDeProm);
    mostrarArchivoGenerico(NOMALUM, sizeof(tAlumno), imprimirAlumnos);

    fclose(pf);
    return 0;
}


void redondeoDeProm(void* dato, unsigned tamBytes, FILE *pf)
{
    tAlumno alum = *(tAlumno*)dato;

    alum.promedio = REDONDEO(alum.promedio);
    fseek(pf, -(long)tamBytes, SEEK_CUR);
    fwrite(&alum, tamBytes, 1, pf);
    fseek(pf, 0L, SEEK_CUR);

}


void actualizarArchivo(FILE *pf, unsigned tamBytes, void accion(void* dato, unsigned tamBytes, FILE *pf))
{
    void *dato;

    dato = malloc(tamBytes);

    if(!dato)
        return;

    rewind(pf);
    fread(dato, tamBytes, 1, pf);
    while(!feof(pf))
    {
        accion(dato, tamBytes, pf);
        fread(dato, tamBytes, 1, pf);
    }
    free(dato);
}



int abrirArchivo(FILE **pf, const char* nombreArch, const char *modo)
{
    *pf = fopen(NOMALUM, modo);

    if(!pf) ///arch == NULL
        return 0;

    return 1;
}


void redondearPromedios(FILE *pf)
{
    tAlumno alum;

    rewind(pf);

    fread(&alum, sizeof(tAlumno), 1, pf);
    while (!feof(pf))
    {
        alum.promedio = REDONDEO(alum.promedio);///Tengo que retroceder el cursor si no me pisa el siguiente alumno
        fseek(pf, -(long)sizeof(tAlumno), SEEK_CUR);/// - porque retrocede, seek_cur desde donde retrocede
        fwrite(&alum, sizeof(tAlumno), 1, pf);
        fseek(pf, 0, SEEK_CUR);///sin esto rompo el archivo
        fread(&alum, sizeof(tAlumno), 1, pf);
    }
}


void mostrarArchivoGenerico(const char *archNom, unsigned tamBytes, void imprimir(const void *dato))
{
    void *dato = malloc(tamBytes);

    if(!dato)
        return;

    FILE *pf = fopen(NOMALUM, "rb");
    if(!pf)
        return;


    fread(dato, tamBytes, 1, pf);
    while(!feof(pf))
    {
        imprimir(dato);
        fread(dato, tamBytes, 1, pf);
    }

    free(dato);
    fclose(pf);
}


void imprimirAlumnos(const void * dato)
{
    const tAlumno alum = *(const tAlumno*)dato;

    printf("DNI[%d], Nombre[%s], Promedio[%.2f]\n", alum.dni, alum.noYAp, alum.promedio);

}


void mostrarArchivo(const char *archNom)
{
    FILE *pf = fopen(NOMALUM, "rb");

    if(!pf)
        return;

    tAlumno alum;

    fread(&alum, sizeof(tAlumno), 1, pf);
    while(!feof(pf))
    {
        imprimirAlumnos(&alum);
        fread(&alum, sizeof(tAlumno), 1, pf);
    }
    fclose(pf);
}


int crearLotePrueba03(const char *archNom)
{
    int i;
   tAlumno alus[] =
    {
        {10, "Maria Pia", 9.9},
        {20, "Juan Perez", 10},
        {30, "Danilo Beltran", 5.5}
    };

    tAlumno *pAlu = alus;

    FILE *pf = fopen(archNom, "wb");

    if(!pf)
        return 0;
    for(i = 0; i < sizeof(alus) / sizeof(tAlumno); i++, pAlu++)
        fwrite(pAlu, sizeof(tAlumno), 1, pf);


    fclose(pf);
    return 1;
}


int crearLotePrueba02(const char *archNom)
{
   tAlumno alus[] =
    {
        {10, "Maria Pia", 9.9},
        {20, "Juan Perez", 10},
        {30, "Danilo Beltran", 5.5}
    };

    FILE *pf = fopen(archNom, "wb");

    if(!pf)
        return 0;

    fwrite(alus, sizeof(tAlumno), sizeof(alus) / sizeof(tAlumno), pf);

    fclose(pf);
    return 1;
}


int crearLotePrueba01(const char *archNom)
{
    tAlumno alus[] =
    {
        {10, "Maria Pia", 9.9},
        {20, "Juan Perez", 10},
        {30, "Danilo Beltran", 5.5}
    };

    FILE *pf = fopen(archNom, "wb");

    if(!pf)
        return 0;
    ///sizeof(alus) = sizeof(alus) * nItems
    fwrite(alus, sizeof(alus), 1, pf);

    fclose(pf);
    return 1;
}

