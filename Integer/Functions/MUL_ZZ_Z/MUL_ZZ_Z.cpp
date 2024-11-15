#include "MUL_ZZ_Z.h"

Integer MUL_ZZ_Z(Integer firstNumber, Integer secondNumber){
    if (POZ_Z_D(firstNumber) == 0 || POZ_Z_D(secondNumber) == 0){
        return Integer(0);
    }

    Integer absNumberFirst = TRANS_N_Z(ABS_Z_N(firstNumber));
    Integer absNumberSecond = TRANS_N_Z(ABS_Z_N(secondNumber));

    NaturalNumbers firstNumberNaturalForm;
    firstNumberNaturalForm = TRANS_Z_N(absNumberFirst);

    NaturalNumbers secondNumberNaturalForm;
    secondNumberNaturalForm = TRANS_Z_N(absNumberSecond);

    NaturalNumbers natResult = MUL_NN_N(firstNumberNaturalForm, secondNumberNaturalForm);

    Integer result;
    result = TRANS_N_Z(natResult);
    result.setSign(Positive);

    if ((POZ_Z_D(firstNumber) == 2 && POZ_Z_D(secondNumber) == 1) ||
        (POZ_Z_D(firstNumber) == 1 && POZ_Z_D(secondNumber) == 2))
    {
        result.setSign(Negative);
    }

    return result;
}
