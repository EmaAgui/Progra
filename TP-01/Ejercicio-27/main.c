#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int esPalindromo(char cad[], int cantElem);

int main()
{
    char cadena[] = "afa";

    int cantElem = sizeof(cadena) / sizeof(cadena[0]);

    printf("%d\n", cantElem);

    if(esPalindromo(cadena, cantElem))
        printf("\nEs palindromo");
    else
        printf("\nNo es palindromo");
    return 0;
}


int esPalindromo(char cad[], int cantElem)
{
    char *principio = cad, *fin = cad + cantElem - 2;

    while(principio < fin)
    {
        if((*principio) != (*fin))
            return 0;
        else
        {
            principio++;
            fin--;
        }
    }
    return 1;
}
