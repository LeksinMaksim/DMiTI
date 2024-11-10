#include "MUL_Nk_N.h"

#include "NZER_N_B.h"

NaturalNumbers MUL_Nk_N(NaturalNumbers& number, size_t k)
{
    // Если число равно 0, возвращаем 0
    if (!NZER_N_B(number))
    {
        return NaturalNumbers(0);
    }

    // Получаем текущие цифры числа
    std::vector<size_t> currentDigits = number.getDigits();

    // Добавляем k нулей в конец числа
    for (size_t i = 0; i < k; ++i)
    {
        currentDigits.push_back(0);
    }

    // Создаем новое число с обновленными цифрами
    NaturalNumbers result;
    result.setDigits(currentDigits);

    return result;
}
