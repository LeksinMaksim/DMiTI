#include "SUB_NDN_N.h"

NaturalNumbers SUB_NDN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber, size_t multiplier)
{
    if(multiplier < 0 || multiplier > 9) 
        return NaturalNumbers(0);
    secondNumber = MUL_ND_N(secondNumber, multiplier); 
    if(COM_NN_D(firstNumber, secondNumber) == 1) 
        return NaturalNumbers(0);
    return SUB_NN_N(firstNumber, secondNumber);
}
