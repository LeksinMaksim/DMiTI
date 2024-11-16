#include "MUL_ZM_Z.h"

Integer MUL_ZM_Z(const Integer number)
{
    Integer result(number);

    // Если число равно 0, знак не меняем
    if (result.getSize() == 1 && result.getDigit(0).second == 0)
    {
        result.setSign(NullStatus);
        return result;
    }

    // Меняем знак на противоположный
    if (result.getSign() == Positive)
    {
        result.setSign(Negative);
    }
    else if (result.getSign() == Negative)
    {
        result.setSign(Positive);
    }

    return result;
}
