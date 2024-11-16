#ifndef MUL_PP_P_HEADER
#define MUL_PP_P_HEADER

#include "../../../Integer/Functions/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "../../../Rationals/Functions/MUL_QQ_Q/MUL_QQ_Q.h"
#include "../../../build/NumberInput.h"
#include "../../Source/Polynomials.h"
#include "../ADD_PP_P/ADD_PP_P.h"

Polynomials MUL_PP_P(Polynomials poly1, Polynomials poly2);

Polynomials MUL_PP_P_Interactive();

#endif
