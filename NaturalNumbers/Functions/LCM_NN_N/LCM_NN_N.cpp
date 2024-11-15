#include "LCM_NN_N.h"

NaturalNumbers LCM_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
    NaturalNumbers nod = GCF_NN_N(firstNumber, secondNumber);
    NaturalNumbers multiplication = MUL_NN_N(firstNumber, secondNumber);
    return DIV_NN_N(multiplication, nod); 
}
