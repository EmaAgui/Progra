#include <stdio.h>
#include <stdlib.h>


void elimTodAparElem(int *vec, int dato, int *ce);
void mostrarVector(int *vec, int ce);


int main()
{
    int vec[] = {1, 5, 8, 5};
    int cantElem = sizeof(vec) / sizeof(vec[0]);
    int dato = 5;

    printf("\nAntes de Eliminar: ");
    mostrarVector(vec, cantElem);


    printf("\nDespues de Eliminar %d: ", dato);
    elimTodAparElem(vec, dato, &cantElem);
    mostrarVector(vec, cantElem);

    return 0;
}


void elimTodAparElem(int *vec, int dato, int *ce)
{
    int i=1, *pVecSig, eliminados=0;

    while(*vec != dato && i <= *ce)
    {
       i++;
       vec++;
    }

    pVecSig = vec + 1;

    if(i <= *ce)
    {
        eliminados++;
        while(i < *ce)
        {
          if(*pVecSig  != dato)
          {
              *vec = *pVecSig;
              vec++;
          }
          else
          {
              eliminados++;
          }

          i++;
          pVecSig++;
        }

        (*ce) -= eliminados;
    }
}


void mostrarVector(int *vec, int ce)
{
    int i;
    for(i = 0; i < ce; i++, vec++)
    {
        printf("\n%d", *vec);
    }
}

