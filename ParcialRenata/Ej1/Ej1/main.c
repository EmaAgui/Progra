#include "Lista.h"
#include "Prototipos.h"

int main()
{
    t_lista lista;
    if(!crearLotePrueba())
    {
        return -1;
    }

    cargarLista(&lista);
    mostrarLista(&lista,mostrarTransferencias);
    FILE *pfBin=fopen("Cuentas.dat","r+b");
    if(!pfBin)
    {
        return -2;
    }
    printf("\nArch Bin Antes de actualizar");
    mostrarArchivoBinario();
    printf("\nArch Bin Despues de actualizar");
    actualizarArchivoCuentas(pfBin,&lista);
    mostrarArchivoBinario();

    incriptarArch();

    fclose(pfBin);

    return 0;
}
