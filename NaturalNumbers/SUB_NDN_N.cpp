#include "SUB_NDN_N.h"

// Выполнил Пьянков Михаил 3384

NaturalNumbers SUB_NDN_N(NaturalNumbers first, NaturalNumbers second, size_t multiplier)
{
    if(multiplier < 0 || multiplier > 9) // Проверка, что множитель - цифра
        return NaturalNumbers(0);
    second = MUL_ND_N(second, multiplier); // Умножение второго числа на цифру
    if(COM_NN_D(first, second) == 1) // Проверка, на неотрицательный случай
        return NaturalNumbers(0);
    return SUB_NN_N(first, second);
}