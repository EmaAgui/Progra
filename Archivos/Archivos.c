#include "Archivos.h"


int abrirArchivo(FILE **pArch, const char *nomArch, const char *modo)
{
    *pArch = fopen(nomArch, modo);
    if (!pArch)
        return 0;
    return 1;
}


void mostrarArchivoGenericoBin(const char *nomArch, unsigned tamBytes, void imprimir(const void *dato))
{
    void *dato = malloc(tamBytes);

    if(!dato)
        return;

    FILE *pArch = fopen(nomArch, "rb");

    fread(dato, tamBytes, 1, pArch);

    imprimir(NULL);
    while (!feof(pArch))
    {
        imprimir(dato);
        fread(dato, tamBytes, 1, pArch);
    }

    free(dato);
    fclose(pArch);
}
