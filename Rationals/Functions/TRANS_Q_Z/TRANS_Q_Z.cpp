#include "TRANS_Q_Z.h"

Integer TRANS_Q_Z(Rationals rnumber)
{
    // NaturalNumbers one(1);
    Integer znumber;                   // Объявление целого
    znumber = rnumber.getNumerator();  // Получение числителя
    return znumber;
}

Integer TRANS_Q_Z_Interactive()
{
    Rationals rnumber = NumberInput::readRational();
    return TRANS_Q_Z(rnumber);
}
