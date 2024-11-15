#include "DEG_P_N.h"
Integer DEG_P_N(Polynomials pol)
{
    return pol.getElems()[0]->getNodeDegree();
}