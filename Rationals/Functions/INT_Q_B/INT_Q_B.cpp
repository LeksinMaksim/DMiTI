#include "INT_Q_B.h"

bool INT_Q_B(Rationals fraction)
{
    fraction = RED_Q_Q(fraction);
    NaturalNumbers numeratorNaturalForm = NaturalNumbers(0);
    numeratorNaturalForm = ABS_Z_N(fraction.getNumerator());
    size_t resultOfCompare =
        COM_NN_D(numeratorNaturalForm, fraction.getDenominator());
    if (resultOfCompare == 0) return true;
    if (resultOfCompare == 1) return false;
    NaturalNumbers modNumeratorOfDenominator =
        MOD_NN_N(numeratorNaturalForm, fraction.getDenominator());
    return COM_NN_D(modNumeratorOfDenominator, NaturalNumbers(0)) == 0 ? true
                                                                       : false;
}

bool INT_Q_B_Interactive()
{
    Rationals fraction = NumberInput::readRational();
    return INT_Q_B(fraction);
}
