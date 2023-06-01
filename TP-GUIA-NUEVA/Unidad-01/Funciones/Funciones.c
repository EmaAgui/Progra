#include "Funciones.h"


void mostrarVectorInt(int * vec, int ce)
{
    for(int i = 0; i < ce; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n");
}
