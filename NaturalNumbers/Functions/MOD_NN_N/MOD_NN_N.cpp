#include "MOD_NN_N.h"

NaturalNumbers MOD_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    NaturalNumbers quotient = DIV_NN_N(firstNumber, secondNumber);
    NaturalNumbers product = MUL_NN_N(secondNumber, quotient);
    NaturalNumbers remainder = SUB_NN_N(firstNumber, product);
    return remainder;
}

NaturalNumbers MOD_NN_N_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натурельное число: ");
    return MOD_NN_N(firstNumber, secondNumber);
}
