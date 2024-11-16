#include "DEG_P_N.h"

Integer DEG_P_N(Polynomials pol)
{
    return pol.getMaxDegree();  // Получаем максимальную степень в полиноме
}

Integer DEG_P_N_Interactive()
{
    Polynomials pol = NumberInput::readPolynomial("Введите полином: ");
    return DEG_P_N(pol);
}
