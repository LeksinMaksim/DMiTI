#ifndef DIV_NN_N_HEADER
#define DIV_NN_N_HEADER

#include "../../../build/NumberInput.h"
#include "../../Source/NaturalNumbers.h"
#include "../ADD_NN_N/ADD_NN_N.h"
#include "../COM_NN_D/COM_NN_D.h"
#include "../DIV_NN_Dk/DIV_NN_Dk.h"
#include "../MUL_NN_N/MUL_NN_N.h"
#include "../MUL_Nk_N/MUL_Nk_N.h"
#include "../SUB_NN_N/SUB_NN_N.h"

NaturalNumbers DIV_NN_N(NaturalNumbers firstNumber,
                        NaturalNumbers secondNumber);

NaturalNumbers DIV_NN_N_Interactive();

#endif
