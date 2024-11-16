#include "ADD_QQ_Q.h"

#include <cstdlib>

// Выполнил Пьянков Михаил 3384

Rationals ADD_QQ_Q(Rationals first, Rationals second)
{
    // Заметим, что если знаменатели имеют общий делитель, то сумму дробей a/b +
    // c/d = (a*d + c*b) / (b * d) можно записать, как: : n * (a * d/n + c *
    // b/n) / (b * d), понятно, что n - НОД(b, d) Очевидно, что НОД(b, d) / (b *
    // d) = 1 / НОК(b, d), таким образом: a/b + c/d = (a * (НОК(b, d) / b)) + (b
    // * НОК(b, d) / d)) / (НОК(b, d))
    NaturalNumbers denominator = LCM_NN_N(
        first.getDenominator(),
        second.getDenominator());  // Вычислим НОК знаменателей двух дробей
    Integer numinator =
        ADD_ZZ_Z(MUL_ZZ_Z(first.getNumerator(),
                          DIV_ZZ_Z(TRANS_N_Z(denominator),
                                   TRANS_N_Z(first.getDenominator()))),
                 MUL_ZZ_Z(second.getNumerator(),
                          DIV_ZZ_Z(TRANS_N_Z(denominator),
                                   TRANS_N_Z(second.getDenominator()))));
    // считаем числитель дроби согласно формуле для a/b + c/d в формулах выше
    return Rationals(numinator, denominator);
}

Rationals ADD_QQ_Q_Interactive()
{
    Rationals first = NumberInput::readRational();
    Rationals second = NumberInput::readRational();
    return ADD_QQ_Q(first, second);
}
