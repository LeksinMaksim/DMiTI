#include "TRANS_N_Z.h"

Integer TRANS_N_Z(NaturalNumbers naturalNumber){
    Integer znumber;
    znumber.setDigits(naturalNumber.getDigits());    
    znumber.setSign(Positive);
    return znumber;
}
