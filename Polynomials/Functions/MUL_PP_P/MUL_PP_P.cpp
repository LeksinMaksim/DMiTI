#include "MUL_PP_P.h"

Polynomials MUL_PP_P(Polynomials poly1, Polynomials poly2) {
    Polynomials result; // Результат умножения

    // Перебираем элементы первого многочлена
    for (auto elem1 : poly1.getElems()) {
        Polynomials tempResult; // Временный результат для текущего элемента

        // Перебираем элементы второго многочлена
        for (auto elem2 : poly2.getElems()) {
            // Умножаем коэффициенты текущих элементов
            Rationals newCoefficient = MUL_QQ_Q(
                elem1->getNodeMultiplier(),
                elem2->getNodeMultiplier()
            );

            // Складываем степени текущих элементов
            Integer newDegree = ADD_ZZ_Z(
                elem1->getNodeDegree(),
                elem2->getNodeDegree()
            );

            // Создаем новый одночлен и добавляем его в временный результат
            Polynomials singleTerm;
            singleTerm.insertElem(newCoefficient, newDegree);
            tempResult = ADD_PP_P(tempResult, singleTerm);
        }

        // Добавляем временный результат в итоговый результат
        result = ADD_PP_P(result, tempResult);
    }

    return result;
}
