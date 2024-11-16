#include "NZER_N_B.h"

bool NZER_N_B(NaturalNumbers number){
    if (number.getSize() == 0){
        return false;
    }
    if (number.getSize() == 1){
        StatusCode status = number.getDigit(0).first;
        size_t digit = number.getDigit(0).second;
        if (status == Successfull && digit == 0){
            return false;
        }
    }
    return true;
}
