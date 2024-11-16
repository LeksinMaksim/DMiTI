#include "DER_P_P.h"

// Выполнил Пьянков Михаил 3384

Polynomials DER_P_P(Polynomials polinom)
{
    std::vector<Elem*> elems = polinom.getElems();
    std::vector<Elem*> newElems;
    for (size_t i = 0; i < elems.size(); i++)
    {
        // В каждом  мономе произведём следущие операции: a * x^b := (a * b) *
        // x^(b - 1)
        Integer numinator = elems[i]->getNodeMultiplier().getNumerator();
        Integer degree = elems[i]->getNodeDegree();
        if (!degree.getStrReference().compare(0, 1, "0")) continue;
        numinator = MUL_ZZ_Z(
            numinator, degree);  // считаем новый числитель нового коэффициента
        Rationals multiplier = {
            numinator, elems[i]->getNodeMultiplier().getDenominator()
        };  // считаем новый коэффициент
        degree = SUB_ZZ_Z(degree, Integer("1"));  // считаем новую степень
        newElems.push_back(new Elem(
            multiplier,
            degree));  // добавляем новый моном в вектор моновом новго полинома
    }
    polinom.setElems(newElems);  // устанавливаем новый вектор мономов
    return polinom;
}

Polynomials DER_P_P_Interactive()
{
    Polynomials polinom = NumberInput::readPolynomial("Введите полином: ");
    return DER_P_P(polinom);
}
