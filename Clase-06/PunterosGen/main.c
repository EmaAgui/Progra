#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;


typedef struct
{
    int dni;
    char noyApe[20];
    tFecha fNac;
    float promedio;
}tAlumnoA;


typedef struct
{
    int dni;
    char noyApe[20];
    tFecha* fNac;
    int *matAprob;
    float promedio;
}tAlumnoB;


void mostrarAlumnoA(const tAlumnoA *pAlu);
void mostrarAlumnoB(const tAlumnoB *pAlu);


int main()
{
    tFecha f = {10,5, 1990};
    int matAprob = 7;
    tAlumnoA aluA = {20, "Maria Pia", {30, 10, 1980}, 9.9};
    tAlumnoB aluB = {30, "Mario Bel", &f, &matAprob, 5.5}; ///Paso las direcciones


    printf("%.2f", aluA.promedio);

    mostrarAlumnoA(&aluA);
    mostrarAlumnoB(&aluB);

    return 0;
}


void mostrarAlumnoB(const tAlumnoB *pAlu)
{
    printf("\n%d %s %02d/%02d/%d %d %.2f", pAlu->dni, pAlu->noyApe,
                                        pAlu->fNac->dia, pAlu->fNac->mes,
                                        pAlu->fNac->anio, *(pAlu->matAprob),
                                        pAlu->promedio); ///con * accedo al contenido del puntero
}


void mostrarAlumnoA(const tAlumnoA *pAlu)
{
    printf("\n%d %s %02d/%02d/%d %.2f", pAlu->dni, pAlu->noyApe,
                                        pAlu->fNac.dia, pAlu->fNac.mes,
                                        pAlu->fNac.anio, pAlu->promedio);
}


