#ifndef DIV_PP_P_HEADER
#define DIV_PP_P_HEADER

#include "../../../Rationals/Functions/DIV_QQ_Q/DIV_QQ_Q.h"
#include "../DEG_P_N/DEG_P_N.h"
#include "../MUL_Pxk_P/MUL_Pxk_P.h"
#include "../MUL_PQ_P/MUL_PQ_P.h"
#include "../SUB_PP_P/SUB_PP_P.h"
#include "../ADD_PP_P/ADD_PP_P.h"

#include "../../Source/Polynomials.h"

std::pair<Polynomials, Polynomials> DIV_PP_P(Polynomials first, Polynomials second);

#endif 
