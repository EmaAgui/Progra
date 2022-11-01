#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define PAR(X) ((X=='0') || (X=='2')  ||(X=='4') || (X=='6') ||(X=='8'))
#define IMPAR(X) ((X=='1') || (X=='3')  ||(X=='5') || (X=='7') ||(X=='9'))
#define ES_NRO(x) ((x)>='0' && (x)<='9')



typedef struct
{
    int cta_origen;
    char titularO[25];
    int cta_destino;
    char titutarD[25];
    double cantidad;
}Transferencia;

typedef struct
{
    char cod_suc[5];
    char sucursal[25];
}Sucursal;

typedef struct
{
    int nro_cta;
    char cod_suc[5];
    char titular[25];
    double saldo;
}Cuenta;

int crearLotePrueba();
void cargarLista(t_lista* lista);
void trozarArchivoLV(Transferencia* mov,char* cadena);
int compararTransferencias(const void* t1, const void* t2);
void mostrarTransferencias(const void* t1);
void actualizarArchivoCuentas(FILE *pfBin, t_lista* lista);
void mostrarTransferencias(const void* t1);
void actualizarTransferencias(void* t1,const void*t2);
void mostrarArchivoBinario();
void incriptarArch();
void cambiarCaracteresPar(char *cad);
void cambiarCaracteresImpar(char *cad);
void ofuscarLinea(char *cad);
#endif // PROTOTIPOS_H_INCLUDED
