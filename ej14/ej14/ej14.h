#ifndef EJ14_H_INCLUDED
#define EJ14_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia,
        mes,
        anio;
}t_fecha;

int EsFechaValida(t_fecha fecha);
int cantDiasMes(int mes,int anio);
int EsBisiesto(int anio);
t_fecha DiaSiguiente (t_fecha x);

#endif // EJ14_H_INCLUDED
