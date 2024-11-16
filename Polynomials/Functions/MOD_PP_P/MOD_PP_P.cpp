#include "MOD_PP_P.h"

Polynomials MOD_PP_P(Polynomials polyFirst, Polynomials polySecond)
{
    Polynomials polyResult = Polynomials();
    polyResult.setElems(DIV_PP_P(polyFirst, polySecond).second.getElems());
    return polyResult;
}

Polynomials MOD_PP_P_Interactive()
{
    Polynomials polyFirst =
        NumberInput::readPolynomial("Введите первый полином: ");
    Polynomials polySecond =
        NumberInput::readPolynomial("Введите второй полином: ");
    return MOD_PP_P(polyFirst, polySecond);
}
