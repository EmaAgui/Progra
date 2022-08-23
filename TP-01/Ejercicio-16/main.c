#include "Funciones.h"


int main()
{
    Fecha f1 = {31, 03, 2022};
    Fecha fSuma = sumarNDias(&f1, 60);

    printf("La fecha es %02d/%02d/%d", fSuma.dia, fSuma.mes, fSuma.anio);

    return 0;
}
