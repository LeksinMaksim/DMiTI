#include "FAC_P_Q.h"

// Выполнил Пьянков Михаил 3384
// Идея: P(x) = (a_1 / b_1)*x^1 + (a_2 / b_2)*x^2 + ... + (a_n / b_n)*x^n
// Возьмём НОД(a_1, a_2, ... , a_n) = A и НОД(b_1, b_2, ... , b_n) = B
// Если A и B не равны 1, то имеет смысл разделить множитель каждого монома многочлена на дробь A/B
// Или числитель разделить на A, а знаменатель разделить на B
Polynomials FAC_P_Q(Polynomials polinom)
{
    std::vector<Elem*>elems = polinom.getElems(); // Получаем мономы полинома
    NaturalNumbers gcfNuminator = NaturalNumbers(TRANS_Z_N(ABS_Z_N(elems[0]->getNodeMultiplier().getNumerator()))); // Инициализируем НОД числителей
    NaturalNumbers gcfDenuminator = NaturalNumbers(elems[0]->getNodeMultiplier().getDenominator()); // Инициализируем НОД знаменателей
    for(size_t i = 1; i < elems.size(); i++)
    {
        gcfNuminator = GCF_NN_N(gcfNuminator, TRANS_Z_N(ABS_Z_N(elems[i]->getNodeMultiplier().getNumerator()))); // Обновляем НОД числителя
        gcfDenuminator = GCF_NN_N(gcfDenuminator, elems[i]->getNodeMultiplier().getDenominator()); // Обновляем НОД знаменателя
        if(!gcfNuminator.getStrReference().compare(0, 1, "1") && !gcfDenuminator.getStrReference().compare(0, 1, "1")) // Проверяем что оба НОД не равны 1
            return polinom; // Если это так, то можно прекратить работу программы, потому что нельзя вынести общий множитель у всех мономов
    }
    Integer gcfNuminator = TRANS_N_Z(gcfNuminator);
    Integer gcfDenuminator = TRANS_N_Z(gcfDenuminator);
    for(size_t i = 0; i < elems.size(); i++)
    {
        Integer numinator = elems[i]->getNodeMultiplier().getNumerator();
        Integer denuminator = TRANS_N_Z(elems[i]->getNodeMultiplier().getDenominator());
        numinator = DIV_ZZ_Z(numinator, gcfNuminator); // Производим деление числителя на НОД числителей
        denuminator = DIV_ZZ_Z(denuminator, gcfDenuminator); // Производим деление знаменателя на НОД знаменателей
        Rationals newMultiplier = Rationals(numinator, TRANS_Z_N(denuminator)); // Создаём новый множитель монома
        elems[i]->setNodeMultiplie(newMultiplier); // Присваиваем его моному
    }
    polinom.setElems(elems); // Присваиваем полиному новые мономы
    return polinom;
}