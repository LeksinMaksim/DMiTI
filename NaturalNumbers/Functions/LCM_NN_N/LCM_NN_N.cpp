#include "LCM_NN_N.h"

NaturalNumbers LCM_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    NaturalNumbers nod = GCF_NN_N(firstNumber, secondNumber);
    NaturalNumbers multiplication = MUL_NN_N(firstNumber, secondNumber);
    return DIV_NN_N(multiplication, nod);
}

NaturalNumbers LCM_NN_N_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натуральное число: ");
    return LCM_NN_N(firstNumber, secondNumber);
}
