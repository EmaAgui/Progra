#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *pc, c = 'm';
    int *px, x = 4, y, e=3, *pe;
    float *pz, z = 7.8;

    px = &x;
    pz = &z;
    pc = &c;
    pe=&e;

    /**Aritmetica de punteros**/
    printf("\nAntes:%d",*pe);
    *pe+=3;
    printf("\nDespues:%d\n",*pe);



    y = *px;
    printf("\n%d", y);

    printf("\nsizeof px %d\n", sizeof(px));
    printf("sizeof x %d\n", sizeof(x));
    printf("%p\n", px);
    printf("%p\n", &x);
    printf("%d\n\n", *px);

    printf("sizeof pz %d\n", sizeof(pz));
    printf("sizeof z %d\n", sizeof(z));
    printf("Dir: %p\n", pz);
    printf("Dir: %p\n", &z);
    printf("Contenido: %.2f\n", *pz);
    printf("contenido: %.2f\n\n", z);

    printf("sizeof pc %d\n", sizeof(pc));
    printf("sizeof c %d\n", sizeof(c));
    printf("%p\n", pc);
    printf("%p\n", &c);
    printf("%c\n", *pc);

    return 0;
}


