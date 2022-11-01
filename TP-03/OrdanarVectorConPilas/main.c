#include "Pila.h"

int main()
{
    int vec[] = {50, 5, 4, 40, 60, 80, 120, 20, 160, 500, 42, 0, 2};
    int cantElem = sizeof(vec) / sizeof(vec[0]);
    int elemPilaMay, val, elemPilaMen;
    Pila pMayores, pMenores;

    crearPila(&pMayores);
    crearPila(&pMenores);

    for (int i = 0; i < cantElem; i++)
    {
        ponerEnPila(&pMayores, vec + i,  sizeof(int));
        if(i < cantElem)
            val = *(vec + i + 1);
        else
            break;

        while (verTope(&pMayores, &elemPilaMay, sizeof(int)) && elemPilaMay < val)
        {
            sacarPila(&pMayores, &elemPilaMay, sizeof(int));
            ponerEnPila(&pMenores, &elemPilaMay, sizeof(int));
        }

        while (verTope(&pMenores, &elemPilaMen, sizeof(int)) && elemPilaMen > val)
        {
            sacarPila(&pMenores, &elemPilaMen, sizeof(int));
            ponerEnPila(&pMayores, &elemPilaMen, sizeof(int));
        }

    }
    int vecAux[cantElem];
    int i= 0;

    while(!pilaVacia(&pMenores))
    {
        sacarPila(&pMenores, &elemPilaMen, sizeof(int));
        ponerEnPila(&pMayores, &elemPilaMen, sizeof(int));
    }

    while(!pilaVacia(&pMayores))
    {
        sacarPila(&pMayores, vecAux + i, sizeof(int));
        i++;
    }

    for (int i = 0; i < cantElem; i++)
        printf("%d\n", vecAux[i]);


    return 0;
}

int compararInt(const void *dato1, const void *dato2)
{
    int d1 = *(int*)dato1;
    int d2 = *(int*)dato2;

    return d1 - d2;
}
