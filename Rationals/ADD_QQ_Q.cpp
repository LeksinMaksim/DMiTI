#include "ADD_QQ_Q.h"

Rationals ADD_QQ_Q(Rationals first, Rationals second)
{
    NaturalNumbers denominator = LCM_NN_N(first.getDenominator(), second.getDenominator());
    Integer numinator = ADD_ZZ_Z(MUL_ZZ_Z(first.getNumerator(), TRANS_N_Z(second.getDenominator())), MUL_ZZ_Z(second.getNumerator(), TRANS_N_Z(first.getDenominator())));
    return Rationals(numinator, denominator);
}