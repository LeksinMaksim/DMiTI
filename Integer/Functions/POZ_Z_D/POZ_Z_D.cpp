#include "POZ_Z_D.h"

size_t POZ_Z_D(Integer number) { return number.getSign(); }

size_t POZ_Z_D_Interactive()
{
    Integer number = NumberInput::readInteger("Введите целое число: ");
    return POZ_Z_D(number);
}
