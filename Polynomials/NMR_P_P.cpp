#include "NMR_P_P.h"

Polynomials NMR_P_P(Polynomials polinom)
{
    Polynomials gcf = GFC_PP_P(polinom, DER_P_P(polinom)); // Найдём НОД исходного полинома и его производной
    Polynomials result = DIV_PP_P(polinom, gcf); // поделим исходный полином на НОД
    return result;
}