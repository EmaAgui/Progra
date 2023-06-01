#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
    Desarrollar una función que cuente el número de apariciones de una palabra dentro
de una cadena de texto. Para ello la función recibe como parámetros dos punteros a char.
El primero corresponde al texto, el segundo corresponde a la cadena buscada.
La función debe retornar el número de ocurrencias. Contemple las condiciones de borde
y haga un listado de éstas.
**/

void normalizarCadena(char* cadena);
int cuentaPalabras(char *cadena, char *palabraABuscar);

int main()
{
    char cad[] = "   hola    como EsTas,     TODO biEN?     ";

    //printf("Cant: %d\n", cuentaPalabras(cad, "hola"));

    //printf("\nCad:%s \nCad Normalizada:%s",cad, normalizarCad(cad));

    printf("\nCad:%s",cad);
    normalizarCadena(cad);
    printf("\nCad Normalizada:%s",cad);

    return 0;
}


void normalizarCadena(char *cad)
{
    char *lec;
    int mayus = 1;
    lec = cad;

    while(*lec == ' ')
        lec++;


    while(*lec != '\0')
    {
        if(*lec == ' ')
        {
            mayus = 1;
            while(*lec != '\0' && *(lec + 1) == ' ')
                lec++;
            *cad = *lec;
        }
        else
        {
            if(mayus)
            {
                *cad = toupper(*lec);
                mayus = 0;
            }
            else
                *cad = tolower(*lec);
        }
        cad++;
        lec++;
    }
    *cad = '\0';
}



int cuentaPalabras(char *cadena, char *palabraABuscar)
{
    char *iniCad, *iniPal;
    int cantPalabras = 0;
    iniCad = cadena;
    iniPal = palabraABuscar;

    while(*iniCad != '\0')
    {
        do{
            if(*iniCad == *iniPal)
            {
                iniCad++;
                iniPal++;
                if(*iniPal == '\0')
                {
                    cantPalabras++;
                    iniPal = palabraABuscar;
                }
            }else
            {
                iniPal = palabraABuscar;
            }
        }while(*iniCad == *iniPal);

        iniPal = palabraABuscar;
        iniCad++;
    }

    return cantPalabras;
}
