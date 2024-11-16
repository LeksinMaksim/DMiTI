#include "DIV_QQ_Q.h"

Rationals DIV_QQ_Q(Rationals fraction1, Rationals fraction2)
{
    // Проверяем, что делитель не равен нулю
    if (fraction2.getNumerator().getStrReference() == "0")
    {
        return Rationals();
    }

    // Сохраняем знаки дробей
    SignStatus sign1 = fraction1.getSign();
    SignStatus sign2 = fraction2.getSign();

    // При делении дробей:
    // (a/b) / (c/d) = (a*d)/(b*c)

    // Получаем числитель первой дроби (a) и знаменатель второй дроби (d)
    Integer numerator1 = fraction1.getNumerator();
    NaturalNumbers denominator2 = fraction2.getDenominator();

    // Получаем знаменатель первой дроби (b) и числитель второй дроби (c)
    NaturalNumbers denominator1 = fraction1.getDenominator();
    Integer numerator2 = fraction2.getNumerator();

    // Создаем целое число из знаменателя второй дроби
    Integer denominator2AsInteger;
    denominator2AsInteger.setDigits(denominator2.getDigits());
    denominator2AsInteger.setSize(denominator2.getSize());
    denominator2AsInteger.setSign(Positive);

    // Создаем целое число из знаменателя первой дроби
    Integer denominator1AsInteger;
    denominator1AsInteger.setDigits(denominator1.getDigits());
    denominator1AsInteger.setSize(denominator1.getSize());
    denominator1AsInteger.setSign(Positive);

    // Вычисляем новый числитель (a*d)
    Integer newNumerator = MUL_ZZ_Z(numerator1, denominator2AsInteger);

    // Вычисляем новый знаменатель (b*c)
    Integer newDenominator = MUL_ZZ_Z(denominator1AsInteger, numerator2);

    // Создаем объект NaturalNumbers для нового знаменателя
    NaturalNumbers newDenominatorNatural;
    newDenominatorNatural.setDigits(newDenominator.getDigits());
    newDenominatorNatural.setSize(newDenominator.getSize());

    // Создаем результирующую дробь
    Rationals result(newNumerator, newDenominatorNatural);

    // Определяем знак результата
    // Результат отрицательный, если знаки дробей разные
    if (sign1 != sign2)
    {
        result.setSign(Negative);
    }
    else
    {
        result.setSign(Positive);
    }

    return result;
}
