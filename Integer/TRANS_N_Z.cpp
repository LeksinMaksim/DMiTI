#include "TRANS_N_Z.h"
Integer TRANS_N_Z(NaturalNumbers& nnumber){
    Integer znumber;
    znumber.setDigits(nnumber.getDigits());
    znumber.setSign(Positive);
    return znumber;
}