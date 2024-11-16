#include "DIV_PP_P.h"

// Выполнил Пьянков Михаил 3384

std::pair<Polynomials, Polynomials> DIV_PP_P(Polynomials first, Polynomials second)
{
    Polynomials div = Polynomials();
    size_t i = 0;
    while(i < 200 && (first.getElems().back()->getNodeDegree() > second.getElems().back()->getNodeDegree()) || (first.getElems().back()->getNodeDegree() == second.getElems().back()->getNodeDegree()))
    {

        Rationals multiplier = DIV_QQ_Q(first.getElems().back()->getNodeMultiplier(), second.getElems().back()->getNodeMultiplier());
        Polynomials temp = MUL_PQ_P(second, multiplier);
        Integer degree = SUB_ZZ_Z(first.getElems().back()->getNodeDegree(), second.getElems().back()->getNodeDegree());
        

        temp = MUL_Pxk_P(temp, Elem(Rationals(1), degree));

        div.insertElem(multiplier, degree);
        first = SUB_PP_P(first, temp);
        
        if(first.getMaxDegree()==Integer(0) || first.getStrReference().compare(0,1,"0"))
            
            break;
        i++;
        
        
    }
    return {div, first};
}