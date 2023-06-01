#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
    Desarrollar una funci�n que devuelva el valor num�rico de una cadena de
    caracteres (asumiendo que los caracteres representan d�gitos).
**/

int sumaValorCadena(const char *cadena);

int main()
{
    char cad[] = "Hola";
    printf("La suma es: %d", sumaValorCadena(cad));

    return 0;
}



int sumaValorCadena(const char *cadena)
{
    int tam = strlen(cadena);
    int suma = 0;
    char *ini = cadena;

    for(int i = 0; i < tam; i++)
    {
        suma += (*ini);
        ini++;
    }

    return suma;
}
