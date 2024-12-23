#include "ADD_1N_N.h"

NaturalNumbers ADD_1N_N(NaturalNumbers number)
{
    std::vector<size_t> digits = number.getDigits();
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            number.setDigits(digits);
            return number;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    number.setDigits(digits);
    return number;
}

NaturalNumbers ADD_1N_N_Interactive()
{
    NaturalNumbers number =
        NumberInput::readNaturalNumber("Введите натуральное число: ");
    return ADD_1N_N(number);
}
