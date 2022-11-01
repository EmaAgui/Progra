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


int EsBisiesto(t_fecha fecha);
t_fecha CargaFecha();
t_fecha ProxDia(t_fecha fecha);
void mostrarFecha(t_fecha fecha);


#endif // EJ14_H_INCLUDED
