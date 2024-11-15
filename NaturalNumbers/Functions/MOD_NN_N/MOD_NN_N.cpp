#include "MOD_NN_N.h"

NaturalNumbers MOD_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
    NaturalNumbers quotient = DIV_NN_N(firstNumber, secondNumber);
    NaturalNumbers product = MUL_NN_N(secondNumber, quotient);
    NaturalNumbers remainder = SUB_NN_N(firstNumber, product);
    return remainder;
}
