#include "NZER_N_B.h"

bool NZER_N_B(NaturalNumbers& number)
{
    if (number.getSize() == 0)
    {
        return false;
    }
    if (number.getSize() == 1)
    {
        auto [status, digit] = number.getDigit(0);
        if (status == Successfull && digit == 0)
        {
            return false;
        }
    }
    return true;
}

bool NZER_N_B_Interactive()
{
    NaturalNumbers number =
        NumberInput::readNaturalNumber("Введите натуральное число: ");
    return NZER_N_B(number);
}
