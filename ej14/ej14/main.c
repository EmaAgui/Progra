#include "ej14.h"

int main()
{
    t_fecha fecha;

    printf("\nIngresa una fecha a validar(dd/mm/aaaa) :");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    while(!(EsFechaValida(fecha)))
    {
        puts("\n Fecha invalida, Ingrese una fecha de nuevo(DD/MM/AAAA): ");
        fflush(stdin);
        scanf("%d/%d/%d",&fecha.dia, &fecha.mes, &fecha.anio);
    }

    printf("\nFecha valida");


    return 0;
}
