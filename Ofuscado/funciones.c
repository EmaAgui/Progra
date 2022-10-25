#include "header.h"



bool desofuscarArchivo(FILE* archivo, char* nombreArchivo)
{
    archivo = fopen(nombreArchivo, "r+t");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return false;
    }
    FILE* archivoDesofuscado = fopen("desofuscado.txt", "w+t");
    if (archivoDesofuscado == NULL)
    {
        printf("Error al abrir el archivo");
        return false;
    }
    char cadena[2500];
    char linea[2500];
    fgets(cadena, 2500, archivo);
    while(!feof(archivo))
    {
        strcpy(linea, desofuscarLinea(cadena));
        invertirPalabra(linea);
        fprintf(archivoDesofuscado, "%s", linea);
        fgets(cadena, 2500, archivo);
    }
    fclose(archivoDesofuscado);
    return true;
}

char* desofuscarLinea(char* cadena)
{
    char* aux = cadena;
    char* inicio = cadena;
    int pos = 1;
    while (*cadena != '\0')
    {
        if(*cadena != ' ' && esLetraMinuscula(*cadena))
        {
            if(*cadena - pos < 'a')
                *cadena = 'z' - ('a' - (*cadena - pos)) + 1;
            else
                *cadena -= pos;
            *aux = *cadena;
            pos++;
        }
        else
        {
            pos = 1;
        }
        cadena++;
        aux++;
    }
    aux = inicio;
    return aux;
}

void invertirPalabra(char* cadena)
{
    char* inicio = cadena;
    char* fin = cadena;

    while(*cadena != '\0')
    {
        while(*cadena != ' ' && esLetra(*cadena))
        {
            cadena++;
        }
        fin = cadena - 1;
        while(inicio < fin || inicio == fin)
        {
            char aux = *inicio;
            *inicio = *fin;
            *fin = aux;
            inicio++;
            fin--;
        }
        inicio = cadena + 1;
        cadena++;
    }
}
