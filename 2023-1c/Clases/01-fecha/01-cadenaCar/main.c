#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Hacer Normalizar
**/
char *myStrcat(char *cad1, const char *cad2);

int main()
{
    char cad1[] = "Hola ";
    char cad2[50] = "mundo!";



    printf("%s\n", strcat(cad1, cad2));
    printf("%s\n", cad2);

    return 0;
}


char *myStrcat(char *cad1, const char *cad2)
{
    char *ini = cad1;

    while(*cad1 != '\0')
        cad1++;
    while(*cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }
    *cad1 = '\0';

    return ini;
}
