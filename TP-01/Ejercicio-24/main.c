#include <stdio.h>
#include <stdlib.h>

void elimElemSegunPos(int *vec, int pos, int *ce);
void mostrarVector(int *vec, int *ce);
void eliminarPrimeraAparicion(int *vec, int dato, int *ce);
void elimTodAparElem(int *vec, int dato, int *ce);

int main()
{
    int vec[] = {1, 5, 8, 5};
    int cantElem = sizeof(vec) / sizeof(vec[0]);

    mostrarVector(vec, &cantElem);

//    elimElemSegunPos(vec, 2, &cantElem);
//
//    printf("\n\n%d\n", cantElem);
//    mostrarVector(vec, cantElem);

    printf("\n\nElimina");
    elimTodAparElem(vec, 5, &cantElem);
    mostrarVector(vec, &cantElem);


    return 0;
}


void elimTodAparElem(int *vec, int dato, int *ce)
{
    int i=1, *pVecSig, eliminados = 0;

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


void eliminarPrimeraAparicion(int *vec, int dato, int *ce)
{
    int i = 0;

    while(*vec != dato && i < *ce)
    {
        i++;
        vec++;
    }

    int *sig;

    sig = vec;

    if(i <= *ce)
    {
        while(i <= *ce)
        {
            sig++;
            *vec = *sig;
            vec++;
            i++;
        }
        (*ce)--;
    }
}


void mostrarVector(int *vec, int *ce)
{
    int i;
    for(i = 0; i < *ce; i++, vec++)
    {
        printf("\n%d", *vec);
    }
}


void elimElemSegunPos(int *vec, int pos, int *ce)
{
    int *sig;

    vec += pos - 1;
    sig = vec;

    if(pos <= *ce)
    {
        while(pos <= *ce)
        {
            sig++;
            *vec = *sig;
            vec++;
            pos++;
        }
    }

    int cantElem = (int)sizeof(vec) / sizeof(int);

    *ce = cantElem + 1;
}
