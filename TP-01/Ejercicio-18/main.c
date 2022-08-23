#include "Funciones.h"


int main()
{
    Fecha f1 = {31, 3, 2022};
    Fecha f2 = {23, 8, 2022};

    printf("La Diferencia Entre dias es: %d", diferenciaDeDiasEntreFechas(&f1, &f2));

    return 0;
}
