#ifndef __DIV_PP_P__
#define __DIV_PP_P__

#include "../Rationals/DIV_QQ_Q.h"
#include "DEG_P_N.h"
#include "MUL_Pxk_P.h"
#include "MUL_PQ_P.h"
#include "SUB_PP_P.h"
#include "ADD_PP_P.h"

#include "Polynomials.h"

std::pair<Polynomials, Polynomials> DIV_PP_P(Polynomials first, Polynomials second);

#endif //__DIV_PP_P__