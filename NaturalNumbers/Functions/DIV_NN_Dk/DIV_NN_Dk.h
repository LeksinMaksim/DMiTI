#ifndef DIV_NN_DK_HEADER
#define DIV_NN_DK_HEADER

#include "../../../build/NumberInput.h"
#include "../../Source/NaturalNumbers.h"
#include "../ADD_NN_N/ADD_NN_N.h"
#include "../COM_NN_D/COM_NN_D.h"
#include "../MUL_Nk_N/MUL_Nk_N.h"
#include "../NZER_N_B/NZER_N_B.h"
#include "../SUB_NN_N/SUB_NN_N.h"

NaturalNumbers DIV_NN_Dk(NaturalNumbers firstNumber,
                         NaturalNumbers secondNumber, size_t tenDegree);

NaturalNumbers DIV_NN_Dk_Interactive();

#endif
