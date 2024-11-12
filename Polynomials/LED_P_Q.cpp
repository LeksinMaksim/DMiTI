#include "LED_P_Q.h"

Rationals LED_P_Q(Polynomials polinom)
{
    if(polinom.getSize() != 0)
        return polinom.getElems().back()->getNodeMultiplier();
    else
        return Rationals(0);
}