#include "MUL_ND_N.h"

NaturalNumbers MUL_ND_N(NaturalNumbers number, size_t digit)
{
    if (digit == 1) return number;
    if (digit == 0) return NaturalNumbers(0);

    std::vector<size_t> oldDigits = number.getDigits();
    std::vector<size_t> newDigits(oldDigits.size() + 1, 0);  // Увеличиваем размер на 1 и инициализируем нулями

    size_t carry = 0;
    for (int i = oldDigits.size() - 1; i >= 0; i--)
    {
        size_t tmpResult = oldDigits[i] * digit + carry;
        newDigits[i + 1] = tmpResult % 10;
        carry = tmpResult / 10;
    }

    newDigits[0] = carry;  // Записываем последний перенос

    // Убираем ведущие нули
    while (newDigits.size() > 1 && newDigits[0] == 0)
    {
        newDigits.erase(newDigits.begin());
    }

    NaturalNumbers newNumber;
    newNumber.setDigits(newDigits);
    return newNumber;
}
