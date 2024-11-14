#include "MOD_ZZ_Z.h"

Integer MOD_ZZ_Z(Integer first, Integer second)
{
    Integer quotient = DIV_ZZ_Z(first, second);
    Integer mod = SUB_ZZ_Z(first, MUL_ZZ_Z(second, quotient));
    return mod;
}