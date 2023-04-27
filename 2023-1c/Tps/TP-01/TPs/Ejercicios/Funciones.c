#include "Funciones.h"



int esPalindromo(const char *palabra)
{
    const char *ini, *fin;
    int tam = strlen(palabra);

    ini = palabra;
    fin = palabra + tam - 1;

    while(ini < fin)
    {
        if(toupper(*ini) == toupper(*fin))
        {
            ini++;
            fin--;

        }
        else
        {
            return 0;
        }
    }
    return 1;
}


void mostrarVector(int *vec, int ce)
{
    for(int i = 0; i < ce; i++)
    {
        printf("[%d] ", *vec);
    }
}


void eliminaUnaPosicion(int *vec, int *ce, int dato)
{
    int i = 0;

    while(*vec != dato && i < *ce)
    {
        i++;
        vec++;
    }

    int *sig;

    sig = vec;

    if(i <= *ce)
    {
        while(i <= *ce)
        {
            sig++;
            *vec = *sig;
            vec++;
            i++;
        }
        (*ce)--;
    }
}


int sumaPrimerosNumNatPares(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        if(i%2 == 0)
            sum += i;
    }

    return sum;
}


int sumaPrimerosNumNat(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}


void cociente(int a, int b)
{
    if(b == 0)
    {
        printf("NO se puede dividir por cero.");
        return;
    }

    printf("La división es: %d", a/b);
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


double senx(double x)
{
    double error, res = 0, res2= 0, i = 1, exp = 1;

    if(x == 0)
        return 0;

    do{
        res += ((pow(x, exp) / fact(exp)) * i);
        i *= -1;
        exp+=2;
        res2 += ((pow(x, exp) / fact(exp)) * i);
        error = res2 - res;
    }while(error > TOL || error < TOL);

    return res;
}


int esFibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;

    while (c < n) /// mientras el numero siguiente sea menor que el numero que se busca
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c == n? 1:0;
}


double exponente(double x)
{
    double error, res = 1, res2;
    int i = 1;
    do
    {
        res += pow(x, i) / factorial(i);
        i++;
        res2 = res + pow(x, i) / factorial(i);
        error = res2 - res;
    }while(error > TOL);

    return res;
}


double factorial(int numero)
{
    double resultado = 1;

    for(int i = 1; i <= numero; i++)
        resultado *= i;

    return resultado;
}


double fact(int num)
{
    double res = 1;
    if(num == 0)
        return 1;

    while(num > 0)
    {
        res *= num;
        num--;
    }
    return res;
}


int combinatoria(int m, int n)
{
    return m >= n && n >= 0? (factorial(m) / (factorial(n) * factorial(m - n))) : -50;
}
