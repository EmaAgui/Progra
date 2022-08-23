#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;


int esFechaValida(Fecha *f1);
Fecha ingresarFecha();
int diferenciaDeDiasEntreFechas(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* f);
int cantDiasAnio(int anio);

#endif // FUNCIONES_H_INCLUDED
