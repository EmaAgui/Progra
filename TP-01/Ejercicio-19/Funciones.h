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
int diaDelAnio(const Fecha* f);
int cantDiasAnio(int anio);
void diaDeLaSemana(const Fecha *f1);
int cantDiasDesde1601(const Fecha *f);


#endif // FUNCIONES_H_INCLUDED
