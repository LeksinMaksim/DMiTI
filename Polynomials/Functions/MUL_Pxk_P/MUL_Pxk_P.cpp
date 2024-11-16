#include "MUL_Pxk_P.h"

Polynomials MUL_Pxk_P(Polynomials polynom, Elem pOne)
{
    Integer kDegree = pOne.getNodeDegree();
    if (!kDegree.getStrReference().compare(0, 1, "0")) return polynom;
    std::vector<Elem*> newPolynomElements = polynom.getElems();
    size_t countElements = polynom.getSize();
    for (size_t i = 0; i < countElements; i++)
    {
        Integer oldDegree = newPolynomElements[i]->getNodeDegree();
        newPolynomElements[i]->setNodeDegree(ADD_ZZ_Z(oldDegree, kDegree));
    }
    polynom.setElems(newPolynomElements);
    return polynom;
}

Polynomials MUL_Pxk_P_Interactive()
{
    Polynomials polynom = NumberInput::readPolynomial("Введите полином: ");

    Rationals multiplier = NumberInput::readRational();

    Integer degree = NumberInput::readInteger("Введите степень");

    Elem pOne(multiplier, degree);

    return MUL_Pxk_P(polynom, pOne);
}
