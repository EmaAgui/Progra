#include <stdio.h>
#include <stdlib.h>


int sumaSucesiva(int num1, int num2);


int main()
{
    printf("La multiplicacion es %d ", sumaSucesiva(1, 5));

    return 0;
}


int sumaSucesiva(int num1, int num2)
{
    int i, sum = 0;
    if(num1 == 0 || num2 ==0)
        return sum;

    for(i = 0; i < num2; i++)
    {
        sum += num1;
    }
    return sum;
}
