#include "NZER_N_B.h"

bool NZER_N_B(NaturalNumbers& number)
{
    // Если размер числа 0, значит число равно 0
    if (number.getSize() == 0)
    {
        return false;
    }

    // Если размер 1 и единственная цифра 0, значит число равно 0
    if (number.getSize() == 1)
    {
        auto [status, digit] = number.getDigit(0);
        if (status == Successfull && digit == 0)
        {
            return false;
        }
    }

    // Во всех остальных случаях число не равно 0
    return true;
}
