#include "NZER_N_B.h"

bool isNotZero(NaturalNumbers number)
{
    if (number.getSize() == 1 && number.getDigit(0) == 0)
        return false;
    return true;
}
