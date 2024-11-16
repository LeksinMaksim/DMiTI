#include "GCF_NN_N.h"

NaturalNumbers GCF_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    NaturalNumbers numberOne = firstNumber;
    NaturalNumbers numberSecond = secondNumber;

    while (true)
    {
        if (!NZER_N_B(numberSecond)) return numberOne;
        if (!NZER_N_B(numberOne)) return numberSecond;
        size_t compareResult = COM_NN_D(numberOne, numberSecond);
        if (compareResult == 2)
        {
            numberOne = MOD_NN_N(numberOne, numberSecond);
        }
        else if (compareResult == 1)
        {
            numberSecond = MOD_NN_N(numberSecond, numberOne);
        }
        if (compareResult == 0) return numberOne;
    }
}

NaturalNumbers GCF_NN_N_Interactive()
{
    NaturalNumbers firstNumber =
        NumberInput::readNaturalNumber("Введите первое натуральное число: ");
    NaturalNumbers secondNumber =
        NumberInput::readNaturalNumber("Введите второе натуральное число: ");
    return GCF_NN_N(firstNumber, secondNumber);
}
