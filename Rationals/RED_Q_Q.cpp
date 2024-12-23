#include "RED_Q_Q.h"
#include <iostream>

Rationals RED_Q_Q(Rationals number){
    // Создаём переменные для числителя и знаменателя
    Integer numerator = number.getNumerator();
    NaturalNumbers denominator = number.getDenominator();

    NaturalNumbers naturalNumerator = TRANS_Z_N(ABS_Z_N(numerator)); // Создаём натуральную версию числителя 
    NaturalNumbers biggestDivider = GCF_NN_N(naturalNumerator, denominator); // Находим наибольший делитель числителя и знаменателя
    
    // Сокращаем делитель и знаменатель на их НОД
    naturalNumerator = DIV_NN_N(naturalNumerator, biggestDivider);
    denominator = DIV_NN_N(denominator, biggestDivider); 

    //Записываем результат в новую переменную
    Rationals result;
    result.setNumerator(TRANS_N_Z(naturalNumerator));
    result.setSign(numerator.getSign());
	result.setDenominator(denominator);
    
    return result;
}