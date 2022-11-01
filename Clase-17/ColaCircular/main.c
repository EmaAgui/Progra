
#include "Cola.h"

int main()
{
    Cola cola;
    int vNum[] = {1,2,3,4,5,6,7,8,9};
    int i, ce, num;

    ce = sizeof(vNum) / sizeof(*vNum);

    crearCola(&cola);

    for(i = 0; i < ce; i++)
        ponerEnCola(&cola, vNum + i, sizeof(*vNum));

    while(!colaVacia(&cola))
    {
        sacarDeCola(&cola, &num, sizeof(num));
        printf("%d ", num);
    }
    return 0;
}
