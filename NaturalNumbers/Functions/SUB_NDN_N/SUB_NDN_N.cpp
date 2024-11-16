#include "SUB_NDN_N.h"

#include <cstddef>

NaturalNumbers SUB_NDN_N(NaturalNumbers firstNumber,
                         NaturalNumbers secondNumber, size_t multiplier)
{
    if (multiplier < 0 || multiplier > 9) return NaturalNumbers(0);
    secondNumber = MUL_ND_N(secondNumber, multiplier);
    if (COM_NN_D(firstNumber, secondNumber) == 1) return NaturalNumbers(0);
    return SUB_NN_N(firstNumber, secondNumber);
}

NaturalNumbers SUB_NDN_N_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натуральное число: ");
    size_t multiplier;
    std::cout << "Введите цифру: ";
    std::cin >> multiplier;
    return SUB_NDN_N(firstNumber, secondNumber, multiplier);
}
