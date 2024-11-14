#include "MOD_ZZ_Z.h"

// Выполнил Пьянков Михаил 3384

Integer MOD_ZZ_Z(Integer first, Integer second)
{
    Integer quotient = DIV_ZZ_Z(first, second); // Неполное частное от деления двух целых чисел
    Integer mod = SUB_ZZ_Z(first, MUL_ZZ_Z(second, quotient)); // Вычитая из первого числа произведение - 
    // - неполного частного двух целых чисел получим остаток: z1 = q * z2 + r, r = z1 - q * z2
    return mod;
}