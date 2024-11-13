#include "SUB_NDN_N.h"

NaturalNumbers SUB_NDN_N(NaturalNumbers first, NaturalNumbers second, size_t multiplier)
{
    second = multNaturalNumberToDigit(second, multiplier);
    if(multiplier < 0 || multiplier > 9)
        return NaturalNumbers(0);
    if(compareNaturalNaturalNumbers(first, second) == 1)
        return NaturalNumbers(0);
    return SUB_NN_N(first, second);
}