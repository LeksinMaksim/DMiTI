#include "DIV_ZZ_Z.h"

Integer DIV_ZZ_Z(Integer number1, Integer number2)
{
    NaturalNumbers nnumber1, nnumber2, resNnumber;
    Integer resZnumber;           // Результирующее целое
    nnumber1 = ABS_Z_N(number1);  // Создаем натуральные числа из входных целых
    nnumber2 = ABS_Z_N(number2);
    resNnumber = DIV_NN_N(
        nnumber1, nnumber2);  // Вычисляем результат деления натуральных чисел

    if ((number1.getSign() == SignStatus::Negative &&
         number2.getSign() == SignStatus::Negative) ||
        (number1.getSign() == SignStatus::Positive &&
         number2.getSign() == SignStatus::Positive))
    {
        // Если у входных чисел одинаковый знак - просто переводим из
        // натуральных в целые
        resZnumber = TRANS_N_Z(resNnumber);  // Инициализируем целое частное
        return resZnumber;
    }
    // Иначе одно из чисел отрицательно, а второе положительно, что дает
    // отрицательный результат Иначе одно из чисел отрицательно, а второе
    // положительно, что дает отрицательный результат
    if (COM_NN_D(MUL_NN_N(nnumber2, resNnumber), nnumber1) == 0)
    {
        resZnumber = TRANS_N_Z(resNnumber);  // Инициализируем целое частное
        resZnumber.setSign(Negative);  // Делаем знак отрицательным
        return resZnumber;
    }
    resNnumber =
        ADD_1N_N(resNnumber);  // Поскольку результат отрицателен, добавляем
                               // 1(при округлении отрицательных чисел модуль
                               // целой части больше самого числа)
    resZnumber = TRANS_N_Z(resNnumber);  // Инициализируем целое частное
    resZnumber.setSign(Negative);  // Делаем знак отрицательным

    return resZnumber;
}

Integer DIV_ZZ_Z_Interactive()
{
    Integer number1 = NumberInput::readInteger("Введите первое целое число: ");
    Integer number2 = NumberInput::readInteger("Введите второе целое число: ");
    return DIV_ZZ_Z(number1, number2);
}
