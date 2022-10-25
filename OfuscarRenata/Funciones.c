#include "Funciones.h"

void ofuscar(FILE *pArch, Pila *pila)
{
    FILE * pOfu = fopen("Ofuscado.txt", "wt");

    if(!pOfu)
    {
        printf ("ERROR");
        return;
    }

    char linea[2200];
    while (fgets(linea, 2000, pArch))
    {
        ofuscarLinea(linea, pila);
        fprintf(pOfu, "%s", linea);
    }
    
}


void ofuscarLinea(char *cad, Pila *pila)
{
    char *ini = cad;
    int pos = 0;
    while (*cad)
    {
        while(ES_LETRA(*cad))
        {
            pos++;
            cad++;
        }
        if(pos != 0)
            apilar(pila, &pos, sizeof(pos));
        pos = 0;
        cad++;
    }
    cad = ini;

    while (*cad)
    {
        if(ES_LETRA(*cad))
        {
            desapilar(pila, &pos, sizeof(pos));
            while (ES_LETRA(*cad))
            {
                correrCaracter(cad, pos * - 1);
                vocalCorrecta(cad);
                cad++;
            }
            
        }
        else
        {
            cad++;
        }
    }   
}


void correrCaracter(char *carac, int desv)
{
    char cad[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char *posCar;
    posCar = myStrchr(cad, *carac);
    desv = desv % ((int)(myStrlen(cad)));

    if(posCar != NULL)
    {
        posCar += desv;
        if(posCar < cad)
        {
            desv = cad - posCar;
            posCar = cad + myStrlen(cad) - desv;
        }
        if(posCar > (cad + myStrlen(cad) - 1))
        {
            desv = posCar - (cad + myStrlen(cad) - 1);
            posCar = cad + desv + 1;
        }
        *carac = *posCar;
    }

}


void vocalCorrecta(char *cad)
{
    if(*cad == 'a' || *cad == 'A')
        *cad = '5';
    if(*cad == 'e' || *cad == 'E')
        *cad = '4';
    if(*cad == 'i' || *cad == 'I')
        *cad = '3';
    if(*cad == 'o' || *cad == 'O')
        *cad = '2';
    if(*cad == 'u' || *cad == 'U')
        *cad = '1';
}


int abrirArchivo(FILE **pArch, const char *nombre, const char *modo)
{
    *pArch = fopen(nombre, modo);

    if(*pArch == NULL)
        return 0;
    
    return 1;
}


void crearPila(Pila *pp)
{
    *pp = NULL;
}


int apilar(Pila *pp, const void *dato, unsigned tamBytes)
{
    tNodo *poner = malloc(sizeof(tNodo));
    if(poner == NULL)
        return 0;
    
    poner->info = malloc(tamBytes);
    if(poner->info == NULL)
    {
        free(poner);
        return 0;
    }

    memcpy(poner->info, dato, tamBytes);
    poner->tamBytes = tamBytes;
    poner->sig = *pp;
    *pp = poner;

    return 1;
}


int desapilar(Pila *pp, void *dato, unsigned tamBytes)
{
    tNodo *sacar = *pp;
    if(sacar == NULL)
        return 0;
    
    *pp = sacar->sig;

    memcpy(dato, sacar->info, minimo(tamBytes, sacar->tamBytes));
    free(sacar->info);
    free(sacar);

    return 1;
}


int pilaVacia(const Pila *pp)
{
    return *pp == NULL;
}


int pilaLlena(const Pila *pp, unsigned tamBytes)
{
    tNodo *nue = malloc(sizeof(tNodo));
    void *info = malloc(tamBytes);

    free(nue);
    free(info);

    return nue == NULL || info == NULL;
}


void vaciarPila(Pila *pp, unsigned tamBytes)
{
    while (*pp)
    {
        tNodo *elim = *pp;
        *pp = elim->sig;

        free(elim->info);
        free(elim);
    }
    
}


char *myStrchr(char *cad, int c)
{
    while (*cad)
    {
        if(*cad == c)
            return cad;
        cad++;
    }
    return NULL;
}


int myStrlen(char *cad)
{
    int cont = 0;

    while (*cad)
    {
        cont++;
        cad++;
    }

    return cont;    
}