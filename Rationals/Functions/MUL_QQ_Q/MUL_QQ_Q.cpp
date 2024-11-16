#include "MUL_QQ_Q.h"
Rationals MUL_QQ_Q(Rationals firstFraction, Rationals secondFraction)
{
    Integer firstFractionNumerator = firstFraction.getNumerator();
    Integer secondFractionNumerator = secondFraction.getNumerator();
    NaturalNumbers firstFractionDenominator = firstFraction.getDenominator();
    NaturalNumbers secondFractionDenominator = secondFraction.getDenominator();

    Integer resultNumerator =
        MUL_ZZ_Z(firstFractionNumerator, secondFractionNumerator);
    NaturalNumbers resultDenominator =
        MUL_NN_N(firstFractionDenominator, secondFractionDenominator);

    firstFraction.setNumerator(resultNumerator);
    firstFraction.setDenominator(resultDenominator);
    return firstFraction;
}

Rationals MUL_QQ_Q_Interactive()
{
    Rationals firstFraction = NumberInput::readRational();
    Rationals secondFraction = NumberInput::readRational();
    return MUL_QQ_Q(firstFraction, secondFraction);
}
