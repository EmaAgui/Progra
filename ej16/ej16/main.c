#include "ej16.h"

int main()
{
    int n;
    t_fecha fecha, fechaMn;
    fecha=Cargar();

    printf("\nINGRESE LA CANTIDAD DE DIAS QUE DESEA SUMARLE A LA FECHA: ");
    scanf("%d",&n);

    fechaMn=Ndias(fecha, n);
    printf("La fecha ");


    mostrarFecha(fecha);

    printf("mas %d dias resulta en la fecha ",n);

    mostrarFecha(fechaMn);


    return 0;
}

