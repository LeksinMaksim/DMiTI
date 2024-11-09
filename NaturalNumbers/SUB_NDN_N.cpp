#include "SUB_NDN_N.h"

NaturalNumbers SUB_NDN_N(NaturalNumbers first, NaturalNumbers second, size_t multiplier)
{
    second = multNaturalNumberToDigit(second, multiplier);
    if(compareNaturalNaturalNumbers(first, second) == 1)
        return NaturalNumbers(0);
    return SUB_NN_N(first, second);
}