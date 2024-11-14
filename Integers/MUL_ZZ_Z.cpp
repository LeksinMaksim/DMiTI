#include "MUL_ZZ_Z.h"

#include "ABS_Z_N.h"
#include "../NaturalNumbers/MUL_NN_N.h"
#include "POZ_Z_D.h"

Integer MUL_ZZ_Z(const Integer& number1, const Integer& number2)
{
    // Проверяем случай, когда одно из чисел равно нулю
    // POZ_Z_D возвращает size_t, поэтому сравниваем с 0
    if (POZ_Z_D(number1) == 0 || POZ_Z_D(number2) == 0)
    {
        return Integer(0);
    }

    // Получаем абсолютные значения чисел
    Integer absNumber1 = ABS_Z_N(number1);
    Integer absNumber2 = ABS_Z_N(number2);

    // Преобразуем в NaturalNumbers для умножения
    NaturalNumbers nat1;
    nat1.setDigits(absNumber1.getDigits());
    nat1.setSize(absNumber1.getSize());  // Явно устанавливаем размер

    NaturalNumbers nat2;
    nat2.setDigits(absNumber2.getDigits());
    nat2.setSize(absNumber2.getSize());  // Явно устанавливаем размер

    // Умножаем как натуральные числа
    NaturalNumbers natResult = MUL_NN_N(nat1, nat2);

    // Создаем результат
    Integer result;
    result.setDigits(natResult.getDigits());
    result.setSize(natResult.getSize());  // Явно устанавливаем размер
    result.setSign(Positive);             // Начальный знак - положительный

    // Определяем знак результата
    // POZ_Z_D возвращает: 2 - положительное, 1 - отрицательное
    if ((POZ_Z_D(number1) == 2 && POZ_Z_D(number2) == 1) ||
        (POZ_Z_D(number1) == 1 && POZ_Z_D(number2) == 2))
    {
        result.setSign(Negative);
    }

    return result;
}
