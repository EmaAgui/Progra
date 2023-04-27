#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define TOL 0.01

double factorial(int numero);
int combinatoria(int m, int n);
double exponente(double x);
double fact(int num);
int esFibonacci(int n);
double senx(double x);
int sumaSucesiva(int num1, int num2);
void cociente(int a, int b);
int sumaPrimerosNumNat(int n);
int sumaPrimerosNumNatPares(int n);

void eliminaUnaPosicion(int *vec, int *ce, int dato);
void mostrarVector(int *vec, int ce);

int esPalindromo(const char *palabra);


#endif // FUNCIONES_H_INCLUDED
