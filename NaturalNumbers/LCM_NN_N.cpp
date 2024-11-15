#include "LCM_NN_N.h"

// Выполнил Пьянков Михаил 3384

NaturalNumbers LCM_NN_N(NaturalNumbers first, NaturalNumbers second)
{
    NaturalNumbers NOD = GCF_NN_N(first, second); // Вычисление НОД двух чисел
    NaturalNumbers multiplication = MUL_NN_N(first, second); // Вычисление произведения двух чисел
    return DIV_NN_N(multiplication, NOD); // Деление произведения на НОД по формуле НОК через НОД
}