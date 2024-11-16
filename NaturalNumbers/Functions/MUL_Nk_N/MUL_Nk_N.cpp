#include "MUL_Nk_N.h"

#include <cstddef>

NaturalNumbers MUL_Nk_N(NaturalNumbers number, size_t k)
{
    if (!NZER_N_B(number))
    {
        return NaturalNumbers(0);
    }
    std::vector<size_t> currentDigits = number.getDigits();
    for (size_t i = 0; i < k; ++i)
    {
        currentDigits.push_back(0);
    }
    NaturalNumbers result;
    result.setDigits(currentDigits);
    return result;
}

NaturalNumbers MUL_Nk_N_Interactive()
{
    NaturalNumbers number =
        NumberInput::readNaturalNumber("Введите натуральное число: ");
    size_t k;
    while (true)
    {
        std::cout << "Введите положительное число: ";
        std::cin >> k;
        if (k >= 0)
        {
            break;
        }
        std::cout << "Ошибка: введите положительное число\n";
    }

    return MUL_Nk_N(number, k);
}
