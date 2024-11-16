#include "ABS_Z_N.h"
Integer ABS_Z_N(Integer number){   
    Integer result;
    result = number;
    result.setSign(Positive);
    return result;
}