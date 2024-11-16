#include "TRANS_Z_N.h"

// Выполнил Пьянков Михаил 3384

NaturalNumbers TRANS_Z_N(Integer value)
{
    if(value.getSign() == Negative) // Проверка на неотрицательность целого числа
        return NaturalNumbers(0);
    NaturalNumbers natural = NaturalNumbers(0);
    natural.setDigits(value.getDigits()); // Установка массива цифр для натурального числа, основанного на целом
    return natural;
}