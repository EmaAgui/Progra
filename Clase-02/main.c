#include <stdio.h>
#include <stdlib.h>


#define CUADRADO x*x
#define CUADRA(x) x*x
#define CUBO(x) (CUADRA(x))*(x)
#define MAYOR(x, y) (x > y)? x : y
#define MENOR(x, y) if(x < y) \
                    printf("%d", x );\
                    else \
                    printf("%d", y)

#define ES_MAYUSCULA(c) (c >= 'A' &&  c <= 'Z')
#define ES_MINUSCULA(c) (c >= 'a' && c <= 'z')
#define ES_LETRA(c) ES_MAYUSCULA(c) || ES_MINUSCULA(c)
#define A_MAYUSCULA(c) (ES_MINUSCULA(c)? c - 32 : c)
#define A_MINUSCULA(c) (ES_MAYUSCULA(c)? c + 32 : c)
#define ES_VOCAL(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
#define ES_BLANCO(c) c == ' '


#define ABS(x) x > 0? x : x *(-1)
#define PARTE_ENTERA(x) (int)x
#define REDONDEO(x) (int)(x + 0.5)
#define ES_PAR(x) x % 2 == 0? 1 : 0
#define ES_IMPAR(x) x % 2 != 0? 1 : 0
#define ES_NUMERO(x) x >= 0 && x <= 9

#define ENTERO_A_CHAR(x) (char)x
#define CHAR_A_ENTERO(c) (int)c

int main()
{
    int x = 5, z, y = 2;
    z = CUADRADO;

    printf("CUADRADO %d\n", z);
    printf("CUADRADO %d\n", CUADRA(x));
    printf("CUBO %d\n", CUBO(x));

    printf("El mayor es: %d\n", MAYOR(x, y));
    MENOR(x, y);

    char c = 'g';
    if(ES_LETRA(c))
        printf("\nEs Letra");
    else
        printf("\nNo es Letra");

    if(ES_MINUSCULA(c))
        printf("\nEs Minuscula");
    else
        printf("\nNo es Minuscula");

    if(ES_MAYUSCULA(c))
        printf("\nEs Mayuscula");
    else
        printf("\nNo es Mayuscula");

    printf("\nA Mayuscula %c", A_MAYUSCULA(c));

    printf("\nValor Absoluto %d", ABS(5));
    printf("\nParte Entera %d", PARTE_ENTERA(5.5));
    printf("\nRedondeo %d", REDONDEO(5.5));

    printf("\nEntero a Char %c", ENTERO_A_CHAR(5));
    printf("\nChar a Entero %d", CHAR_A_ENTERO('{'));

    return 0;
}
