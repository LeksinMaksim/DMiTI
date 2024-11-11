#include "Polynomials.h"

int main()
{
    Polynomials a = Polynomials();
    a.insertElem(Rationals(-5), Integer(2));
    a.insertElem(Rationals(2), Integer(6));
    a.insertElem(Rationals(1), Integer(1));
    a.insertElem(Rationals(-3), Integer(4));
    a.insertElem(Rationals(1), Integer(3));
    a.insertElem(Rationals(1), Integer(5));
    std::cout<<a.getStrReference()<<std::endl;
    std::cout<<a.getMaxDegree().getStrReference()<<std::endl;
    std::cout<<a.getSize()<<std::endl;

    Polynomials b = Polynomials("1x^2+1/2x^1+1/3x^3-3/6x^4+1/3x^0");
    std::cout<<b.getStrReference()<<std::endl;
    std::cout<<b.getMaxDegree().getStrReference()<<std::endl;
    std::cout<<b.getSize()<<std::endl;
}