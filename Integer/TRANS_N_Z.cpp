#include "TRANS_N_Z.h"
Integer TRANS_N_Z(NaturalNumbers& nnumber){
    Integer znumber;
    znumber.setDigits(nnumber.getDigits());    //Создаем целое число и копируем в его вектор вектор натурального
    znumber.setSign(Positive);                 // Знак устанавливаем "+"
    return znumber;
}
