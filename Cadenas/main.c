#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringH.h"
#include "CtypeH.h"

int main()
{
    ///string.h
    char cadena1[] = "Emanuel";
    char cadena2[10];

    printf("Strlen: %d", (int)miStrlen(cadena1));
    printf("\nStrcpy: %s", miStrncpy(cadena2, "Holaa", 5));
    printf("\nStrchr: %s", miStrchr(cadena2, 'a'));
    printf("\nStrcat: %s", miStrcat(cadena2, " como estas?"));

    if(miStrcmpi("Hola", "hola") == 0)
    {
        printf("\nSon iguales");
    }

    printf("\nStrstr %s", miStrstr("aaazbzabbaaaabbba", "abba"));



    ///ctype.h
    char cadena[] = "ESTO ES UNA CADENA DE PRUEBA 123";
    int i;

    for(i = 0; cadena[i]; i++)
        cadena[i] = miTolower(cadena[i]);
    printf("\n%s", cadena);

    char cadena3[] = "esto es una cadena de prueba 123";

    for(i = 0; cadena3[i]; i++)
        cadena3[i] = miToupper(cadena3[i]);
    printf("\n%s\n", cadena3);

    printf("\n%d", miStrncmp("abb", "abba", 4));

    return 0;
}
