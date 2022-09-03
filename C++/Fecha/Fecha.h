#ifndef FECHA_H
#define FECHA_H

///La fecha base es 1/1/1601

#define ANIO_BASE 1601
#define FECHA_INVALIDA 1


class Fecha
{
private:
    int diaRel;

    static const int cdm[13]; ///Static solo se inicia una sola vez
    static const int acumDiasMes[14];
    static const int acumDiasMesBisiesto[14];

    static inline bool esBisiesto(int anio) { return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0); }; ///inline es tipo define

 ///Metodo static no trabaja con los campos de la clase, solo con los parametros, no necesita un objeto para ser invocado.
/// Si trabaja solo con los parametros del metodo es static

    static inline int cantDiasMes(int mes, int anio) { return mes == 2 && esBisiesto(anio)? 29 : cdm[mes]; };

    static inline bool esFechaValida(int dia, int mes, int anio)
        { return anio >= ANIO_BASE && mes >= 1 && mes <= 12 && dia >= 1 && dia <= cantDiasMes(mes, anio); };

    static inline int diaDelAnio(int dia, int mes, int anio)
        {return (esBisiesto(anio)? acumDiasMesBisiesto[mes] : acumDiasMes[mes]) + dia; };

    static int dmaADiaRel(int dia, int mes, int anio);
    static void diaRelADma(int diaRel, int *dia, int *mes, int *anio);
    static void diaDelAnioADiaMes(int diaDelAnio, int anio, int *dia, int *mes);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    Fecha sumarDias(int dias) const; ///const al final la funcion no modifica el objeto que la llame
    Fecha restarDias(int dias) const;
    int diferenciaDias(Fecha fecha) const; ///const para que no modifique a la variable
    int diaDeLaSemana() const;
    void incrementarDia();
    void getDma(int *dia, int *mes, int *anio) const;


};


#endif // FECHA_H
