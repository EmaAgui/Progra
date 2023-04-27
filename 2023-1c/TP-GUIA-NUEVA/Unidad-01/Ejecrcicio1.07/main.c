#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
    Desarrollar una función que devuelva el valor numérico de una cadena de
    caracteres (asumiendo que los caracteres representan dígitos).
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
