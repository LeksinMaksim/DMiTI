#include "GCF_PP_P.h"

Polynomials GCF_PP_P_Interactive()
{
    Polynomials poly1 = NumberInput::readPolynomial("Введите первый полином: ");
    Polynomials poly2 = NumberInput::readPolynomial("Введите второй полином: ");
    return GCF_PP_P(poly1, poly2);
}


Polynomials GCF_PP_P(Polynomials a, Polynomials b){
    
    while ((a.getSize() != 0 && b.getSize() != 0) && (a.getStrReference().compare(0,1,"0")) && (b.getStrReference().compare(0,1,"0"))){
        if (a.getMaxDegree() > b.getMaxDegree())
        {
            a = DIV_PP_P(a,b).second;
        }
        else
        {
            b = DIV_PP_P(b,a).second;
        }
    }
    return a;
}
