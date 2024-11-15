#include "SUB_PP_P.h"

// Выполнил Пьянков Михаил 3384

Polynomials SUB_PP_P(Polynomials first, Polynomials second)
{
    std::vector<Elem*>firstElems = first.getElems();
    std::vector<Elem*>secondElems = second.getElems();
    std::vector<Elem*>resultElems;
    size_t i = 0;
    size_t j = 0;
    // Так как векторы мономов полиномов отсортированы в порядке возрастания степеней, то
    // Примени алгоритм слияния двух отсортированных массивов в один, со следующими модификациями:
    // Если степень очередного монома первого полинома меньше степени очередного монома второго полинома, то
    // добавляем его в новый вектор мономов без изменений
    // Если степень очередного монома первого полинома равна степени очередного мнонома второго полинома, то
    // инициализируем новый моном с коэффициентом равным разности коэффициентов первого и второго мнономо и соответствующей степенью
    // и добавляем его в новый вектор
    // Если степень очередного монома первого полинома больше степени очередного мнонома второго полинома, то
    // создаём новый моном из монома второго полинома, но с заменой знака и добавляем его в новый вектор
    std::cout<<"end0"<<std::endl;
    while (i < firstElems.size() && j < secondElems.size())
    {
        if(firstElems[i]->getNodeDegree() > secondElems[j]->getNodeDegree())
        {
            Rationals multiplier = secondElems[j]->getNodeMultiplier();
            if(multiplier.getSign() == Positive) // Смена знака
                multiplier.setSign(Negative);
            else
                multiplier.setSign(Positive);
            Elem* newElem = new Elem(multiplier, secondElems[j]->getNodeDegree()); // Создание нового монома
            resultElems.push_back(newElem); // Добавление нового монома
            j++;
        }
        else if(firstElems[i]->getNodeDegree() == secondElems[j]->getNodeDegree())
        {
            // Проверка на 0 для вычитания одинаковых дробей
            if((firstElems[i]->getNodeMultiplier().getDenominator().getStrReference().compare(secondElems[j]->getNodeMultiplier().getDenominator().getStrReference())) || \
            (firstElems[i]->getNodeMultiplier().getNumerator().getStrReference().compare(secondElems[j]->getNodeMultiplier().getNumerator().getStrReference())))
            {
                Rationals multiplier = SUB_QQ_Q(firstElems[i]->getNodeMultiplier(), secondElems[j]->getNodeMultiplier()); // Разность коэффициентов
                Elem* newElem = new Elem(multiplier, firstElems[i]->getNodeDegree()); // Создание нового монома
                resultElems.push_back(newElem); // Добавление нового монома
            }
            i++;
            j++;
        }
        else
        {
            Elem* newElem = new Elem(firstElems[i]->getNodeMultiplier(), firstElems[i]->getNodeDegree()); // Создание нового монома
            resultElems.push_back(newElem); // Добавление нового монома
            i++;
        }
    }
    // После работы предудыщего блока добавим оставшиеся мономы от второго или первого полинома по следующим правилам:
    // На основе очередного оставшегося монома второго полинома создаём новый моном но с заменой знака и добавляе в новый вектор мономов
    // То же самое делаем со первым полиномом, только не меняем знак и мономов
    while(i < firstElems.size())
    {
        Elem* newElem = new Elem(firstElems[i]->getNodeMultiplier(), firstElems[i]->getNodeDegree()); // Создание нового монома
        resultElems.push_back(newElem); // Добавление нового монома
        i++;
    }
    while(j < secondElems.size())
    {
        Rationals multiplier = secondElems[j]->getNodeMultiplier();
        multiplier.setSign(Negative); // Смена знака
        Elem* newElem = new Elem(multiplier, secondElems[j]->getNodeDegree()); // Создание нового монома
        resultElems.push_back(newElem); // Добавление нового монома
        j++;
    }
    Polynomials resultPolinom = Polynomials(); // Создаём новый полином
    resultPolinom.setElems(resultElems); // Инициализируем его вектор мономов
    return resultPolinom;
}