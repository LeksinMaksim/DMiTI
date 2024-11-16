#ifndef SUB_QQ_Q_HEADER
#define SUB_QQ_Q_HEADER

#include <iostream>

#include "../../../Integer/Functions/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "../../../Integer/Functions/SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "../../../Integer/Functions/TRANS_N_Z/TRANS_N_Z.h"
#include "../../../NaturalNumbers/Functions/DIV_NN_N/DIV_NN_N.h"
#include "../../../NaturalNumbers/Functions/LCM_NN_N/LCM_NN_N.h"
#include "../../../build/NumberInput.h"
#include "../../Source/Rationals.h"
#include "../RED_Q_Q/RED_Q_Q.h"

Rationals SUB_QQ_Q(Rationals firstNumber, Rationals secondNumber);

Rationals SUB_QQ_Q_Interactive();

#endif
