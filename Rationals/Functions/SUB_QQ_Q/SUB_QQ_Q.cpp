#include "SUB_QQ_Q.h"

Rationals SUB_QQ_Q(Rationals firstNumber, Rationals secondNumber){
    Rationals result = Rationals(1);
    // Приведем дроби к одному знаменателю и вычтем числители 
    NaturalNumbers lcmDenominators = LCM_NN_N(firstNumber.getDenominator(), secondNumber.getDenominator()); // Находим НОК знаменателей
    NaturalNumbers firstMultiplier = DIV_NN_N(lcmDenominators, firstNumber.getDenominator()); // Находим множитель для первой дроби
    NaturalNumbers secondMultiplier = DIV_NN_N(lcmDenominators, secondNumber.getDenominator()); // Находим множитель для второй дроби
    firstNumber.setNumerator(MUL_ZZ_Z(TRANS_N_Z(firstMultiplier), firstNumber.getNumerator())); // Умножаем числитель первой дроби для приведения к общему знаменателю
    secondNumber.setNumerator(MUL_ZZ_Z(TRANS_N_Z(secondMultiplier), secondNumber.getNumerator())); // Умножаем числитель второй дроби для приведения к общему знаменателю
    
    Integer resultNumerator = SUB_ZZ_Z(firstNumber.getNumerator(), secondNumber.getNumerator()); // Вычитаем числители

    result.setNumerator(resultNumerator); // устанавливаем числитель результата 
    result.setDenominator(lcmDenominators); // знаменатель результата вычитания - НОК знаменателей

    result = RED_Q_Q(result); // сокращаем дробь
    return result;
}
