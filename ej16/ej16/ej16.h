#ifndef EJ16_H_INCLUDED
#define EJ16_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,
        mes,
        anio;

}t_fecha;


t_fecha Cargar();
void mostrarFecha(t_fecha fecha);
int EsBisiesto(t_fecha fecha );
t_fecha Ndias(t_fecha fecha , int n);

#endif // EJ16_H_INCLUDED
