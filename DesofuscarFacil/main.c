#include <stdio.h>
#include <stdlib.h>

#define esMayus(x) ( x >= 'A' && x <= 'Z')
#define esMinus(x) ( x >= 'a' && x <= 'z')
#define esLetra(x) (esMayus(x) || esMinus(x))

void desofuscar(char *cad, char *cadCorrec, int desp);


int main()
{
    char correcion[]={"acefhijklo"};
    int offset = 3;
    char linea[] = "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA";

    printf("ofuscado %s", linea);

    esLetra('2')? printf("esLetra"): printf("no es letra");

    return 0;
}

void desofuscar(char *cad, char *cadCorrec, int desp)
{
    int carac;
    while(*cad)
    {
        if(esLetra(*cad))
        {
            carac = 0;
            while (*cad)
            {
                /* code */
            }
            
        }
    }
}
