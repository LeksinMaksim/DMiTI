#include "LCM_NN_N.h"

NaturalNumbers LCM_NN_N(NaturalNumbers first, NaturalNumbers second)
{
    NaturalNumbers NOD = LCM_NN_N(first, second);
    NaturalNumbers multiplication = MUL_NN_N(first, second);
    return DIV_NN_N(NOD, multiplication);
}