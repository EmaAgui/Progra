#include <stdio.h>
#include <stdlib.h>


int obtenerParteEntera(float num);


int main()
{
    float num = 3.12525;

    printf("%d", obtenerParteEntera(num));

    return 0;
}


int obtenerParteEntera(float num)
{
    return num;
}

