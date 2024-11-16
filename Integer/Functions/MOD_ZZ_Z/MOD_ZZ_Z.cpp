#include "MOD_ZZ_Z.h"

// Выполнил Пьянков Михаил 3384

Integer MOD_ZZ_Z(Integer firstNumber, Integer secondNumber)
{
    Integer quotient =
        DIV_ZZ_Z(firstNumber,
                 secondNumber);  // Неполное частное от деления двух целых чисел
    Integer mod = SUB_ZZ_Z(
        firstNumber,
        MUL_ZZ_Z(secondNumber,
                 quotient));  // Вычитая из первого числа произведение -
    // - неполного частного двух целых чисел получим остаток: z1 = q * z2 + r, r
    // = z1 - q * z2
    return mod;
}

Integer MOD_ZZ_Z_Interactive()
{
    Integer firstNumber =
        NumberInput::readInteger("Введите первое целое число: ");
    Integer secondNumber =
        NumberInput::readInteger("Введите второе целое число: ");
    return MOD_ZZ_Z(firstNumber, secondNumber);
}
