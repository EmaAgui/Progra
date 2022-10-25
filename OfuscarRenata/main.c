#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
int main()
{
    FILE *pArch;
    Pila pila;

    if(!abrirArchivo(&pArch, "Archivo.txt", "rt"))
        return -10;
    
    crearPila(&pila);

    ofuscar(pArch, &pila);
    
    return 0;
}
