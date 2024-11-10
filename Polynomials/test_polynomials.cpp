#include "Polynomials.h"

int main()
{
    Polynomials a = Polynomials();
    a.insertElem(Rationals(-5), Integer(1));
    a.insertElem(Rationals(2), Integer(5));
    a.insertElem(Rationals(1), Integer(0));
    a.insertElem(Rationals(-3), Integer(3));
    a.insertElem(Rationals(1), Integer(2));
    std::cout<<a.getStrReference()<<std::endl;
    std::cout<<a.getMaxDegree().getStrReference()<<std::endl;
    std::cout<<a.getSize()<<std::endl;
    a.popElem(Integer(5));
    std::cout<<a.getStrReference()<<std::endl;
    std::cout<<a.getMaxDegree().getStrReference()<<std::endl;
    std::cout<<a.getSize()<<std::endl;
}