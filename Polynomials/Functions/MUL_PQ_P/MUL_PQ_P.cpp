#include "MUL_PQ_P.h"

Polynomials MUL_PQ_P(Polynomials poly, Rationals r)
{
    size_t counter = poly.getSize();  // разм
    for (size_t i = 0; i < counter; i++)
    {
        Rationals multer = poly.getElems()[i]->getNodeMultiplier();
        poly.getElems()[i]->setNodeMultiplie(RED_Q_Q(MUL_QQ_Q(multer, r)));
    }
    return poly;
}

Polynomials MUL_PQ_P_Interactive()
{
    Polynomials poly = NumberInput::readPolynomial("Введите полином: ");
    Rationals r = NumberInput::readRational();
    return MUL_PQ_P(poly, r);
}
