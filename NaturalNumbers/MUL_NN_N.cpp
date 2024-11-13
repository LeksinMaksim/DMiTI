#include "MUL_NN_N.h"
#include "MUL_Nk_N.h"
#include "ADD_NN_N.h"
#include "MUL_ND_N.h"
NaturalNumbers MUL_NN_N(NaturalNumbers number1, NaturalNumbers number2) {
    NaturalNumbers result;  // Начальный результат — ноль

    // Получаем цифры второго числа (множителя) и его размер
    std::vector<size_t> digits2 = number2.getDigits();
    size_t size2 = number2.getSize();

    // Проходим по каждой цифре `number2` справа налево, начиная с младшего разряда
    for (size_t i = 0; i < size2; ++i) {
        size_t digit = digits2[size2 - 1 - i];  // Берём цифры с конца

        // Пропускаем нулевые цифры, так как они не влияют на произведение
        if (digit == 0) {
            continue;
        }

        // 1. Умножаем `number1` на текущую цифру `digit`
        NaturalNumbers partialProduct = MUL_ND_N(number1, digit);

        // 2. Сдвигаем частичное произведение на 10^i, чтобы учесть разряд цифры
        partialProduct = MUL_Nk_N(partialProduct, i);

        // 3. Добавляем сдвинутое частичное произведение к текущему результату
        result = ADD_NN_N(result, partialProduct);
    }

    return result;
}




