#include "SUB_PP_P.h"

Polynomials SUB_PP_P(Polynomials first, Polynomials second)
{
    std::vector<Elem*>firstElems = first.getElems();
    std::vector<Elem*>secondElems = second.getElems();
    std::vector<Elem*>resultElems;
    size_t i = 0;
    size_t j = 0;
    while (i < firstElems.size() && j < secondElems.size())
    {
        if(firstElems[i]->getNodeDegree() > secondElems[j]->getNodeDegree())
        {
            Rationals multiplier = secondElems[j]->getNodeMultiplier();
            multiplier.setSign(Negative);
            Elem* newElem = new Elem(multiplier, secondElems[j]->getNodeDegree());
            resultElems.push_back(newElem);
            j++;
        }
        else if(firstElems[i]->getNodeDegree() == secondElems[j]->getNodeDegree())
        {
            Rationals multiplier = SUB_QQ_Q(firstElems[i]->getNodeMultiplier(), secondElems[j]->getNodeMultiplier());
            Elem* newElem = new Elem(multiplier, firstElems[i]->getNodeDegree());
            resultElems.push_back(newElem);
            i++;
            j++;
        }
        else
        {
            resultElems.push_back(firstElems[i]);
            i++;
        }
    }
    while(i < firstElems.size())
    {
        resultElems.push_back(firstElems[i]);
        i++;
    }
    while(j < secondElems.size())
    {
        Rationals multiplier = secondElems[j]->getNodeMultiplier();
        multiplier.setSign(Negative);
        Elem* newElem = new Elem(multiplier, secondElems[j]->getNodeDegree());
        resultElems.push_back(newElem);
        j++;
    }
    Polynomials resultPolinom = Polynomials();
    resultPolinom.setElems(resultElems);
    return resultPolinom;
}