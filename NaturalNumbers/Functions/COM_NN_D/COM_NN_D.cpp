#include "COM_NN_D.h"

#include <cstddef>

size_t COM_NN_D(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    int resultOfCompare = firstNumber.getSize() - secondNumber.getSize();
    if (resultOfCompare == 0)
    {
        for (size_t i = 0; i < firstNumber.getSize(); i++)
        {
            if (firstNumber.getDigit(i).second ==
                secondNumber.getDigit(i).second)
                continue;
            return firstNumber.getDigit(i).second >
                           secondNumber.getDigit(i).second
                       ? 2
                       : 1;
        }
        return 0;
    };
    return resultOfCompare > 0 ? 2 : 1;
}

size_t COM_NN_D_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натуральное число: ");
    return COM_NN_D(firstNumber, secondNumber);
}
