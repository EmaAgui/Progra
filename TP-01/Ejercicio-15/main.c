#include "Funciones.h"


int main()
{
    Fecha f1 = {31, 03, 2022};
    Fecha fSuma = sumarUnDia(&f1);

    printf("Desarrollar una funcion que a partir de una fecha obtenga la correspondiente al dia siguiente.");
    printf("\n\nLa fecha es %02d/%02d/%d", fSuma.dia, fSuma.mes, fSuma.anio);


    return 0;
}
