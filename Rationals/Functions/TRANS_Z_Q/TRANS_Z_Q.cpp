#include "TRANS_Z_Q.h"

Rationals TRANS_Z_Q(Integer number)
{
    return Rationals(number, NaturalNumbers(1));
}

Rationals TRANS_Z_Q_Interactive()
{
    Integer number = NumberInput::readInteger("Введите целое число: ");
    return TRANS_Z_Q(number);
}
