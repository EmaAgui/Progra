#include <iostream>
#include "../Fecha/Fecha.h"
#include "../Fecha/FechaInvalidaException.h"

using namespace std;


int main()
{
//    ///Change the console encoding to 1252(ansi)
//    system("chcp 1252 > nul");

    ///Fecha(20, 8, 2022) objeto temporal
    Fecha fDefault;
    Fecha f(20, 8, 2022);
    const Fecha f2(10, 9, 2022);

    Fecha fSuma = f + 180; ///operadores es un metodo, f es el objeto llamador, 180 es el parametro

    Fecha f3 = f++;///postincremento devuelve la fecha antes de incrementarla
    Fecha f4 = ++f; ///preincremento devuelve la misma fecha despues de incrementarla


    cout <<"f:  " << f << endl; ///22/8/2022

    cout <<"f3: " << f3 << endl; ///20/8/2022

    cout <<"f4: " << f4 << endl;  ///22/8/2022

    int difDias =  f - f2;
    cout << "Diferencia de dias: " << difDias << endl; ///-10

    Fecha fResta;
    try
    {
        fResta = f - 180;
    }
    catch(const FechaInvalidaException &e)
    {
        cerr << e.getMensaje() << endl; ///cerr imprime mensaje error en rojo
        return FECHA_INVALIDA;
    }


    cout <<"Fecha resta: " << fResta << endl;

    // mostrar f

    cout << "Fecha: " << f << endl;

    ///TODO cin
    int d, m, a;
    char barra;
    cout << "Ingrese una fecha: " << endl;
    cin >> d >> barra >> m >> barra >> a;

    cout << "Fecha Ingresada: " << d << "/" << m << "/" << a << endl;

    /**
     * cout << "Ingrese una fecha: " << endl;
     * cin >> f;
     * cout << "Fecha Ingresada: " << f << endl;
    **/
    return 0;
}
