#include "MUL_NN_N.h"

NaturalNumbers MUL_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    NaturalNumbers result = NaturalNumbers(0);
    std::vector<size_t> secondNumberDigits = secondNumber.getDigits();
    size_t secondNumberSize = secondNumber.getSize();
    for (size_t i = 0; i < secondNumberSize; ++i)
    {
        size_t digit = secondNumberDigits[secondNumberSize - 1 - i];
        if (digit == 0) continue;
        NaturalNumbers partialProduct = MUL_ND_N(firstNumber, digit);
        partialProduct = MUL_Nk_N(partialProduct, i);
        result = ADD_NN_N(result, partialProduct);
    }
    return result;
}

NaturalNumbers MUL_NN_N_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натуральное число: ");
    return MUL_NN_N(firstNumber, secondNumber);
}
