#ifndef CTYPEH_H_INCLUDED
#define CTYPEH_H_INCLUDED


#define ES_MAYUSCULA(C) (C >= 'A' && C <= 'Z')
#define ES_MINUSCULA(C) (C >= 'a' && C <= 'z')
#define ES_LETRA(C) (ES_MAYUSCULA(C) || ES_MINUSCULA(C))


/**
*    Convierte un caracter, en un parametro entero ch, a minuscula.
**/
int miTolower(int ch);


/**
*    Convierte un caracter, en un parametro entero ch, a mayuscula.
**/
int miToupper(int ch);


#endif // CTYPEH_H_INCLUDED
