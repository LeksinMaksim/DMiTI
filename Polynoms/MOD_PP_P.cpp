#include "MOD_PP_P.h"

// Функция для нахождения остатка от деления многочленов
Polynomials MOD_PP_P(Polynomials dividend, Polynomials divisor) {
    Polynomials result;
    result.setElems(DIV_PP_P(dividend,divisor).second.getElems());
    return result;
}
