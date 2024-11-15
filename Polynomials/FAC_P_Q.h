#ifndef __FAC_P_Q__
#define __FAC_P_Q__

#include "../NaturalNumbers/GCF_NN_N.h"
#include "../Integers/DIV_ZZ_Z.h"
#include "../Integers/TRANS_Z_N.h"
#include "../Integers/TRANS_N_Z.h"
#include "../Integers/ABS_Z_N.h"

#include "Polynomials.h"
#include <iostream>

std::pair<Rationals, Polynomials> FAC_P_Q(Polynomials polinom);

#endif //__FAC_P_Q__