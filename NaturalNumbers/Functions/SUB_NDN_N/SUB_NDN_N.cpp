#include "SUB_NDN_N.h"

NaturalNumbers SUB_NDN_N(NaturalNumbers first, NaturalNumbers second, size_t multiplier){
    second = MUL_ND_N(second, multiplier);
    if(COM_NN_D(first, second) == 1)
        return NaturalNumbers(0);
    return SUB_NN_N(first, second);
}
