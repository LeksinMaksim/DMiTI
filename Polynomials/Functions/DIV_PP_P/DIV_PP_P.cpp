#include "DIV_PP_P.h"

// Выполнил Пьянков Михаил 3384

std::pair<Polynomials, Polynomials> DIV_PP_P(Polynomials first,
                                             Polynomials second)
{
    Polynomials div = Polynomials();
    size_t i = 0;
    // Будем вычитать из исходного полинома делитель, домноженный на x^k и r
    // пока степень исходного полинома не сравняется с делителем
    while (i < 1000 && (first.getElems().back()->getNodeDegree() >
                        second.getElems().back()->getNodeDegree()) ||
           (first.getElems().back()->getNodeDegree() ==
            second.getElems().back()->getNodeDegree()))
    {
        Rationals multiplier = DIV_QQ_Q(
            first.getElems().back()->getNodeMultiplier(),
            second.getElems()
                .back()
                ->getNodeMultiplier());  // Зададим такой множитель, чтобы при
                                         // вычитании слагаемое занулялось
        Polynomials temp = MUL_PQ_P(
            second, multiplier);  // Домножим делитель на этот множитель
        Integer degree = SUB_ZZ_Z(
            first.getElems().back()->getNodeDegree(),
            second.getElems()
                .back()
                ->getNodeDegree());  // Вычислим k для домножения на x^k
        temp = MUL_Pxk_P(
            temp, Elem(Rationals(1), degree));  // Домножим делимое на x^k
        div.insertElem(multiplier, degree);  // Добавим моном частного в частное
        first = SUB_PP_P(first, temp);  // Вычтем из делимого делитель
        if (!first.getStrReference().compare(
                0, 1, "0"))  // Проверим, остаток на пустоту
            break;
        i++;
    }
    return { div, first };
}

Polynomials DIV_PP_P_Interactive()
{
    Polynomials first = NumberInput::readPolynomial("Введите первый полином: ");
    Polynomials second =
        NumberInput::readPolynomial("Введите второй полином: ");

    Polynomials result = Polynomials();
    result.setElems(DIV_PP_P(first, second).first.getElems());

    return result;
}
