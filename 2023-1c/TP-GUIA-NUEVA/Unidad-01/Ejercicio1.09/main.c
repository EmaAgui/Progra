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

char * normalizarCad(char* cadena);
void normalizarCadena(char* cadena);



int main()
{
    char cad[] = "    holas  como EsTas, TODO biEN?    ";

    //printf("Cant: %d\n", cuentaPalabras(cad, "hola"));

    //printf("\nCad:%s \nCad Normalizada:%s",cad, normalizarCad(cad));

    printf("\nCad:%s",cad);
    normalizarCadena(cad);
    printf("\nCad Normalizada:%s",cad);

    return 0;
}



void normalizarCadena(char* cadena)
{
    char *ini = cadena;
    int mayus = 1, tam;

    while(*cadena == ' ')
        cadena++;

    ini = cadena;

    tam = strlen(cadena);

    while(tam > 0 && *(cadena + tam - 1) == ' ')
        tam--;
    *(cadena + tam) = '\0';

    ini = cadena;

    while(*ini != '\0')
    {
        if(*ini == ' ')
        {
            mayus = 1;
            while(*(ini+1) == ' ')
                ini++;
        }
        else
        {
            if(mayus)
            {
                *ini = toupper(*ini);
                mayus = 0;
            }
            else
            {
                *ini = tolower(*ini);
            }
        }
        ini++;
    }
}



char * normalizarCad(char* cadena)
{
    char *cadNormalizada = malloc((strlen(cadena) + 1) * sizeof(char));
    int cant = 0;


    while(*cadena == ' ')
        cadena++;

    *cadNormalizada = toupper(*cadena);

    while(*cadena != '\0')
    {
        printf("%c", *cadNormalizada );
        cadena++;
        if(*cadena == ' ')
        {
            *cadNormalizada = *cadena;
            while(*cadena == ' ')
                cadena++;
            printf("%c", *cadNormalizada );
        }
        cadNormalizada++;
        *cadNormalizada = *cadena;
        cant++;
    }

    cadNormalizada -= cant;

    return cadNormalizada;
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
