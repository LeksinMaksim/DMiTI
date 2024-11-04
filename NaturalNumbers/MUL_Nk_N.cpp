#include "MUL_Nk_N.h"

NaturalNumbers multiplyNaturalBy10K(NaturalNumbers number, size_t k)
{
    if (k == 0) return number;

    if (isNotZero(number) == false) return number;

    std::vector<size_t> digits = number.getDigits();

    for (size_t i = 0; i < k; i++)
        digits.push_back(0);

    NaturalNumbers result = 0;
    result.setDigits(digits);
    return result;
}
