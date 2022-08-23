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
Fecha restarNDias(const Fecha *f, int dias);


#endif // FUNCIONES_H_INCLUDED
