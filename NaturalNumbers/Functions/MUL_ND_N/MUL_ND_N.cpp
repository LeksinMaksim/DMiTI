#include "MUL_ND_N.h"

NaturalNumbers MUL_ND_N(NaturalNumbers number, size_t digit)
{
    if (digit == 1) return number;
    if (digit == 0) return NaturalNumbers(0);
    NaturalNumbers newNumber = NaturalNumbers(0);
    std::vector<size_t> oldDigits = number.getDigits();
    std::vector<size_t> newDigits;
    newDigits.resize(oldDigits.size() +
                     (digit * oldDigits.at(0) >= 10 ? 1 : 0));
    size_t indexNewNumber = newDigits.size() - 1;
    size_t tmpResult = 0;
    for (int i = oldDigits.size() - 1; i >= 0; i--)
    {
        tmpResult = oldDigits[i] * digit;
        newDigits.at(indexNewNumber) += tmpResult % 10;
        if (tmpResult >= 10 && indexNewNumber >= 1)
        {
            newDigits.at(indexNewNumber - 1) += tmpResult / 10;
        }
        if (newDigits.at(indexNewNumber) >= 10 && indexNewNumber >= 1)
        {
            newDigits.at(indexNewNumber - 1) +=
                newDigits.at(indexNewNumber) / 10;
            newDigits.at(indexNewNumber) %= 10;
        }
        indexNewNumber -= 1;
    }
    newNumber.setDigits(newDigits);
    return newNumber;
}

NaturalNumbers MUL_ND_N_Interactive()
{
    NaturalNumbers number =
        NumberInput::readNaturalNumber("Введите натуральное число: ");
    size_t digit;
    std::cout << "Введите цифру: ";
    std::cin >> digit;
    return MUL_ND_N(number, digit);
}
