#include "TRANS_N_Z.h"

Integer TRANS_N_Z(NaturalNumbers naturalNumber)
{
    Integer znumber;
    znumber.setDigits(naturalNumber.getDigits());
    znumber.setSign(Positive);
    return znumber;
}

Integer TRANS_N_Z_Interactive()
{
    NaturalNumbers naturalNumber =
        NumberInput::readNaturalNumber("Введите натуральное число: ");
    return TRANS_N_Z(naturalNumber);
}
