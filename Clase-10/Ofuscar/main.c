#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_ARCH "ofuscado.txt"
#define minuscula(x) (x >= 'a' && x <= 'z')
#define mayuscula(x) (x >= 'A' && x <= 'Z')

#define isalpha(x) (minuscula(x) || mayuscula(x))

/**
 *  1° leer el archivo fgets
 *  2° aislar palabras
 *  3° desplazar
 *  4° invertir
 *  5° mostrar
 *  6° grabar en un archivo de texto desofuscado
 **/
typedef struct
{
    char *ini;
    char *fin;
} Palabra;

void leerArchivo(FILE *pArch);
int abrirArchivo(FILE **pArch, const char *nombre, const char *modo);
char *invertirPalabra(char *palabra);
int posEnAbc(char c);
char *desofuscar(char *str, char *abc);
char *desplazar(char *palabra);


int main()
{
    FILE *pArch;
    char *h = malloc(200);

    strcpy(h, "bkusdgt");

    desplazar(h);
    invertirPalabra(h);

    printf("%s", h);



    if (!abrirArchivo(&pArch, NOM_ARCH, "rt"))
        return -10;

    free(h);
    return 0;
}


char *desplazar(char *palabra)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    int cantLetrasPal = (int)strlen(palabra);
    int pos;

    for(int i = 0; i < cantLetrasPal; i++, palabra++)
    {
        if(isalpha(*palabra) && (pos = posEnAbc(*palabra)) != -1)
        {
            *palabra = abc[pos - (i + 1)];
        }
    }

    return palabra;
}


int posEnAbc(char c)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    int pos = 0;
    while(pos < strlen(abc) && abc[pos] != c)
        pos++;

    return pos == strlen(abc)? -1 : pos;
}


char *invertirPalabra(char *palabra)
{
    char *iniPal = palabra;
    char *finPal, aux;

    while(*palabra) /// recorro hasta el fin de la palabra
        palabra++;

    finPal = --palabra; /// me quedo con el ultimo caracter

    while(iniPal < finPal)///Recorro hasta el medio de la palabra
    {
        aux = *iniPal;  /// guardo el caracter inicial
        *iniPal = *finPal;  /// copio el caracter final al inicial
        *finPal = aux;      /// copio el caracter inicial al final
        iniPal++;
        finPal--;
    }

    return palabra; /// devuelvo el puntero al final de la palabra
}




int abrirArchivo(FILE **pArch, const char *nombre, const char *modo)
{
    *pArch = fopen(nombre, modo);
    if (!pArch)
        return 0;

    return 1;
}
