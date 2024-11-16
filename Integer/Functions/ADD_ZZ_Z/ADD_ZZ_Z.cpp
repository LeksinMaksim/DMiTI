#include "ADD_ZZ_Z.h"

Integer ADD_ZZ_Z(Integer firstNumber, Integer secondNumber)
{
    Integer result;
    result.setSign(firstNumber.getSign());
    NaturalNumbers firstNatural = NaturalNumbers();
    NaturalNumbers secondNatural = NaturalNumbers();
    NaturalNumbers resultNatural = NaturalNumbers();
    firstNatural.setDigits(firstNumber.getDigits());
    secondNatural.setDigits(secondNumber.getDigits());
    if (firstNumber.getSign() == secondNumber.getSign())
        result.setDigits(ADD_NN_N(firstNatural, secondNatural).getDigits());
    else
    {
        if (COM_NN_D(firstNatural, secondNatural) == 2)
            result.setDigits(SUB_NN_N(firstNatural, secondNatural).getDigits());
        else
        {
            result.setDigits(SUB_NN_N(secondNatural, firstNatural).getDigits());
            resultNatural.setDigits(result.getDigits());
            if (!NZER_N_B(resultNatural))
            {
                result.setSign(NullStatus);
            }
            else
            {
                result.setSign(secondNumber.getSign());
            }
        }
    }
    return result;
}

Integer ADD_ZZ_Z_Interactive()
{
    Integer firstNumber =
        NumberInput::readInteger("Введите первое целое число: ");
    Integer secondNumber =
        NumberInput::readInteger("Введите второе целое число: ");
    return ADD_ZZ_Z(firstNumber, secondNumber);
}
