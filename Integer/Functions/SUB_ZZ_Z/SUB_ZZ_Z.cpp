#include "SUB_ZZ_Z.h"

Integer SUB_ZZ_Z(Integer firstNumber, Integer secondNumber) {
    size_t firstNumberSign = POZ_Z_D(firstNumber);
    size_t secondNumberSign = POZ_Z_D(secondNumber);
    if (firstNumberSign == 0) return secondNumberSign == 0 ? Integer(0) : MUL_ZM_Z(secondNumber);
    if (secondNumberSign == 0) return firstNumber;
	NaturalNumbers firstNumberNaturalForm = NaturalNumbers(0);
	firstNumberNaturalForm.setDigits(firstNumber.getDigits());
	NaturalNumbers secondNumberNaturalForm = NaturalNumbers(0);
	secondNumberNaturalForm.setDigits(secondNumber.getDigits());
	NaturalNumbers resultNaturalForm;
    size_t compareSign = COM_NN_D(firstNumberNaturalForm, secondNumberNaturalForm);
    bool isTwoPositive = firstNumberSign == 2 && secondNumberSign == 2;
    if (firstNumberSign == secondNumberSign) {
        Integer resultInteger(((compareSign == 2 && isTwoPositive) || (compareSign == 1 && !isTwoPositive)) ? 1 : -1);
        resultNaturalForm = (((compareSign == 2 && isTwoPositive) || (compareSign == 1 && !isTwoPositive))) 
                            ? SUB_NN_N(firstNumberNaturalForm, secondNumberNaturalForm)
                            : SUB_NN_N(secondNumberNaturalForm, firstNumberNaturalForm);
        resultInteger.setDigits(resultNaturalForm.getDigits());
        return resultInteger;
    } 
    resultNaturalForm = ADD_NN_N(firstNumberNaturalForm, secondNumberNaturalForm);
    Integer resultInteger(firstNumberSign == 2 ? 1 : -1);
    resultInteger.setDigits(resultNaturalForm.getDigits());
    return resultInteger;
}
