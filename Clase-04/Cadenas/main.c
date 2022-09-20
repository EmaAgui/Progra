#include "Cadena.h"

/**
    Hacer:
    strlen
    strcpy
    strchr(busca un caracter dentro de una cadena y retorna la pos de memoria
        si encotro o NULL): (char *s, int n) n por ascii
        ej hola mundo  busco la m y retorna la direccion de memoria
    strcat(concatena)
    memcpy***

    strlwr(cad) string
    tolower(*cad) ctype

    int strcmp(const char *s1, const char *s2);  > 0 si s1 > s2, 0 si s1 == s2
        anana sol

    strcmpi ignora mayusculas

    strstr busca una cadena dentro de otra cadena, devuelve inicio de c2 en c1 sino null
    strstr (c1, c2); la cadena 2 busca en cadena 1
    strncp


    hacer:
    strcmp
    strcmpi
    strstr
    strncpy
    strrcr
    strncmp

**/

int main()
{
    char *miCadena1 = "Hola mundo"; ///Constante no se puede modificar
    char miCadena2[TAM] = "Hola mundo";
    char miCadena3[] = {'H', 'o', 'l', 'a', '\0'}; ///Siempre poner el \0

    printf("miCadena1: %s", miCadena1);
    printf("\nmiCadena2: ");

    for(int i = 0; i < strlen(miCadena2); i++)
    {
        printf("%c ", *(miCadena2 + i));
    }

    printf("\nmiCadena3: %s", miCadena3);

    strcpy(miCadena3, "Chu");
    printf("\nmiCadena3: %s", miCadena3);
    strcpy(miCadena3, "Chau");
    printf("\nmiCadena3: %s", miCadena3);

    printf("\nmiCadena3 Cant: %d", (int)miStrlen(miCadena3));

    char *vr = miStrchr(miCadena2, 'm');
    printf("\n\n%s", vr); ///Imprime desde la m hasta el fin

    char palabra[10];

    printf("\nstrcpy %s", miStrcpy(palabra, "Hola"));

    char palabra2[10];

    printf("\n%s", miStrcat(palabra2, "Hola"));

    char s1[13] = "Hola a todos";
    char s2[3] = "la";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strstr(s1,s2) = %s\n", strstr( s1, s2 ) );

    if(miStrcmpi("Hola", "hola") == 0)
        printf("\nSon iguales");

    if(miStrcmpi("Hola", "hola") < 0)
        printf("\nEl primero es menor");

    if(miStrcmpi("Hola", "hola") > 0)
        printf("\nEl primero es mayor");

    printf("\n%d", miStrcmpi("Hola", "hola"));


    printf("\n\nSTRSTR");
    printf("\n%s", miStrstr("aasdddfsf","df"));

    printf("\n\nStrrchr");
    printf("\n%s", strrchr("sdasdas", 'a'));

    printf("\n\nStrrchr");
    printf("\n%s", miStrrchr("abbbaaabbbabbabb", 'a'));

    char des[12];
    char ori[12] = "sadas";
    printf("\n\nStrncpy");
    printf("\n%s", miStrncpy(des, ori, 3));

    printf("\n\nmiStrncmp %d", miStrncmp("des", "sdasdasd", 2));

    return 0;
}
