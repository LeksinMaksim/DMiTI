#ifndef SUB_NDN_N_HEADER
#define SUB_NDN_N_HEADER

#include "../../../build/NumberInput.h"
#include "../../Source/NaturalNumbers.h"
#include "../COM_NN_D/COM_NN_D.h"
#include "../MUL_ND_N/MUL_ND_N.h"
#include "../SUB_NN_N/SUB_NN_N.h"

NaturalNumbers SUB_NDN_N(NaturalNumbers firstNumber,
                         NaturalNumbers secondNumber, size_t multiplier);

NaturalNumbers SUB_NDN_N_Interactive();

#endif
