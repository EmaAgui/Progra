#include "Funciones.h"


int main()
{
    Fecha f1 = {31, 03, 2022};

    Fecha fResta = restarNDias(&f1, 60);

    printf("La fecha es %02d/%02d/%d", fResta.dia, fResta.mes, fResta.anio);

    return 0;
}
