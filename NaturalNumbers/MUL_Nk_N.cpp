#include "MUL_Nk_N.h"

NaturalNumbers MUL_Nk_N(NaturalNumbers number, size_t k){
    if (!NZER_N_B(number)){
        return NaturalNumbers(0);
    }
    std::vector<size_t> currentDigits = number.getDigits();
    for (size_t i = 0; i < k; ++i){
        currentDigits.push_back(0);
    }
    NaturalNumbers result;
    result.setDigits(currentDigits);
    return result;
}
