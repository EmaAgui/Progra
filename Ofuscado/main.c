#include "header.h"

int main()
{
    //crearLotePrueba();
    FILE* archivo;

    if(!desofuscarArchivo(archivo, "ofuscado.txt"))
        printf("Error al desofuscar el archivo");
    else
        printf("Archivo desofuscado correctamente");
    fclose(archivo);
    return 0;
}
