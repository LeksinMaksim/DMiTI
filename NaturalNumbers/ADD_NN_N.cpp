#include "ADD_NN_N.h"
#include "COM_NN_D.h"
#include <algorithm>

NaturalNumbers ADD_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber)
{
    if(COM_NN_D(firstNumber, secondNumber) == 1)
        std::swap(firstNumber, secondNumber);

    std::vector<size_t>first = firstNumber.getDigits();
    std::vector<size_t>second = secondNumber.getDigits();
    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());

    size_t k = 0;
    size_t highDigit = 0;

    while(k < second.size())
    {
        highDigit = (first[k] + second[k]) / 10; // Инкремент в старший разряд
        first[k] = (first[k] + second[k]) % 10; // Обновление текущего разряд
        k++;
        if(k < second.size())
            first[k] += highDigit; // Инкремент старшего(младшего) разряда прошлой(текущей) итерации, если не достигнута граница числа
    }
    if(highDigit) // Проверка на необходимость инкремента в разряд первого числа на границе второго числа
    {
        while(k < first.size() && first[k] > 8) // Пока очередная цифра равна 9, мы её зануляем и двигаемся дальше
        {
            first[k] = 0;
            k++;
        }
        if(k == first.size()) // Если вышле за границу певрого числа, то мы добавляем новый старший разряд
            first.push_back(highDigit);
        else // Иначе выполняем инкремет текущего разряда
            first[k] += highDigit;
    }
    std::reverse(first.begin(), first.end());
    NaturalNumbers newNumber = {0};
    newNumber.setDigits(first);
    return newNumber;
}