#include "Funciones.h"


int main()
{
//    Fecha f1 = ingresarFecha();
    Fecha f2;

    f2.dia = 31;
    f2.mes = 2;
    f2.anio = 1601;

    if(esFechaValida(&f2))
        printf("%02d/%02d/%d es formalmente Corecta", f2.dia, f2.mes, f2.anio);
    else
        printf("%02d/%02d/%d es Incorrecta", f2.dia, f2.mes, f2.anio);

    return 0;
}
