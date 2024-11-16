#include "NMR_P_P.h"

Polynomials NMR_P_P(Polynomials polinom)
{
    Polynomials gcf = GCF_PP_P(polinom, DER_P_P(polinom)); // Найдём НОД исходного полинома и его производной
    Polynomials result = Polynomials();
    result.setElems(DIV_PP_P(polinom, gcf).first.getElems()); // поделим исходный полином на НОД
    return result;
}
