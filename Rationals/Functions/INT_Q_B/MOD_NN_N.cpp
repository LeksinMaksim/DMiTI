#include "MOD_NN_N.h"

#include "subModules/DIV_NN_N.h"
#include "subModules/MUL_NN_N.h"
#include "subModules/SUB_NN_N.h"

NaturalNumbers MOD_NN_N(const NaturalNumbers& dividend, const NaturalNumbers& divisor)
{
    // Получаем неполное частное
    NaturalNumbers quotient = DIV_NN_N(dividend, divisor);

    // Умножаем делитель на частное
    NaturalNumbers product = MUL_NN_N(divisor, quotient);

    // Вычитаем произведение из делимого, получая остаток
    NaturalNumbers remainder = SUB_NN_N(dividend, product);

    return remainder;
}
