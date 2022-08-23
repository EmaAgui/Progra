#include "Funciones.h"


int main()
{
//    Fecha f1 = ingresarFecha();
    Fecha f1 = {31, 03, 2021};

    if(esFechaValida(&f1))
        printf("%02d/%02d/%d es formalmente Corecta", f1.dia, f1.mes, f1.anio);
    else
        printf("%02d/%02d/%d es formalmente Incorrecta", f1.dia, f1.mes, f1.anio);

    return 0;
}
