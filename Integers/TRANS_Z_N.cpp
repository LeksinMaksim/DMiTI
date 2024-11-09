#include "TRANS_Z_N.h"

NaturalNumbers TRANS_Z_N(Integer value)
{
    if(value.getSign() == Negative)
        return NaturalNumbers(0);
    NaturalNumbers natural = NaturalNumbers(0);
    natural.setDigits(value.getDigits());
    return natural;
}