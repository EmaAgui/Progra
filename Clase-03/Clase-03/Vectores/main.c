#include <stdio.h>
#include <stdlib.h>
#define TAM 4

/**Vectores**/


void mostrarVec(int vec[], int cantElem);

void mostrarVec1(int *vec, int cantElem);
void inicializar(int *vec, int cantElemen);
int sumayPosiPares(int *vec, int cantElemen);
void intercambio(int *x, int *y);
int insertar1(int *vec, int tam, int ce);
int insertar(int *vec, int tam, int ce, int pos, int dato);


int main()
{
    int vec[] = {-1, 2, 3, 4};
    int vec1[TAM];
    int cantElem = sizeof(vec) / sizeof(int);
    int x=2, y=10;

    printf("\n%p", &vec);
    printf("\n%p", vec);
    printf("\n%p", &vec[0]);

    printf("\n");
    mostrarVec(vec,cantElem);
    printf("\n");
    mostrarVec1(vec,cantElem);

    inicializar(vec1,TAM);
    printf("\n");
    mostrarVec1(vec1,TAM);

    printf("\nSuma de los componentes del vector:%d", sumayPosiPares(vec,TAM));
    printf("\nx:%d y:%d ", x,y);
    intercambio(&x,&y);
    printf("\nx:%d y:%d ", x,y);

    printf("\nINTERCAMBIO");

    if(insertar(vec, cantElem, cantElem, 4, 10))
        mostrarVec1(vec, cantElem);
    else
        printf("\nError");

    return 0;
}


void mostrarVec(int vec[], int cantElem)
{
    int i;
    for(i = 0; i < cantElem; i++)
        printf("[%d] ", vec[i]);
}


void mostrarVec1(int *vec, int cantElem)
{
    int i;
    for(i = 0; i < cantElem; i++, vec++)
    {
        printf("[%d] ", *vec);
    }

}


void inicializar(int *vec, int cantElemen)
{
    int i;

    for(i=0; i<cantElemen; i++, vec++)
    {
        *vec=2*i;
    }
}


int sumayPosiPares(int *vec, int cantElemen)
{
    int i, suma=0;

    for(i=0; i<cantElemen; i++, vec++)
    {
        if(*vec%2==0 &&*vec+i>0)
        {
            suma+=*vec;
        }
    }

    return suma;
}


void intercambio(int *x, int *y)
{
    int aux;

    aux=*x;
    *x=*y;
    *y=aux;
}


int insertar1 (int *vec, int tam, int ce)
{
    int pos, dato, aux;


    do
    {
        printf("\nIngrese donde quiere insertar el elemento:");
        scanf("%d",&pos);
    }while(pos<=0 || pos>tam);

    vec += pos-1;
    printf("\nIngrese el dato que quiere insertar en la posicion%d :", pos);
    scanf("%d",&dato);

    while(pos <= ce)
    {
        aux = *vec;
        *vec = dato;
        dato = aux;

        vec++;
        pos++;
    }

    return ce >= 5? ce: ce + 1;
}


int insertar (int *vec, int tam, int ce, int pos, int dato)
{
    int aux;

    if(pos>tam)
        return 0;

    vec += pos-1;

    while(pos <= ce)
    {
        aux = *vec;
        *vec = dato;
        dato = aux;

        vec++;
        pos++;
    }

    return 1;
}
