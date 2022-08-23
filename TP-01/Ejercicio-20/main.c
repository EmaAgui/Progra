#include <stdio.h>
#include <stdlib.h>


int multiplicacionRusa(int n, int m);


int main()
{
    printf("\nLa multiplicacion de los numeros es: %d", multiplicacionRusa(35, 8));
    return 0;
}


int multiplicacionRusa(int num1, int num2)
{
    int mult = 0;

    while(num1 != 1)
    {
        if (num1 % 2 == 1)
            mult += num2;

       num1 = num1 / 2;
       num2 = num2* 2;
    }


    return mult + num2;
}

