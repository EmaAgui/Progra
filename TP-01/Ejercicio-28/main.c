#include <stdio.h>
#include <stdlib.h>


int devuelveSumaDeAscii(char cadena[], int cantElem);


int main()
{
    char cadena[] = "casa";
    int cantElem = sizeof(cadena) / sizeof(cadena[0]);

    printf("%d", devuelveSumaDeAscii(cadena, cantElem));

    return 0;
}

int devuelveSumaDeAscii(char cadena[], int cantElem)
{
    int i, suma = 0;

    for(i = 0; i < cantElem; i++)
    {
        suma += cadena[i];
    }
    return suma;
}
