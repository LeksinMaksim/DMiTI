#include "GCF_PP_P.h"

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
