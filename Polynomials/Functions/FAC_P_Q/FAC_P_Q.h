#ifndef FAC_P_Q_HEADER
#define FAC_P_Q_HEADER

#include "../../../NaturalNumbers/Functions/GCF_NN_N/GCF_NN_N.h"
#include "../../../Integer/Functions/DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "../../../Integer/Functions/TRANS_Z_N/TRANS_Z_N.h"
#include "../../../Integer/Functions/TRANS_N_Z/TRANS_N_Z.h"
#include "../../../Integer/Functions/ABS_Z_N/ABS_Z_N.h"

#include "../../Source/Polynomials.h"
#include <iostream>

std::pair<Rationals, Polynomials> FAC_P_Q(Polynomials polinom);

#endif
