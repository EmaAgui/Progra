#include "ej15.h"
//31 d�as: Enero, marzo, mayo, julio, agosto, octubre y diciembre
//30 d�as: Abril, junio, septiembre y noviembre


int main()
{

    t_fecha fecha, fechasum;

    fecha=CargaFecha();
    fechasum= ProxDia(fecha);
    printf("\nLa fecha siguiente del %d/%d/%d que ingreso es ", fecha.dia, fecha.mes, fecha.anio);
    mostrarFecha(fechasum);

    return 0;

}
