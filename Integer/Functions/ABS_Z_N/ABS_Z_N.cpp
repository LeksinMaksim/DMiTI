#include "ABS_Z_N.h"

NaturalNumbers ABS_Z_N(Integer number)
{
    NaturalNumbers result;
    result.setDigits(number.getDigits());
    return result;
}

NaturalNumbers ABS_Z_N_Interactive()
{
    Integer number = NumberInput::readInteger("Введите целое число: ");
    return ABS_Z_N(number);
}
