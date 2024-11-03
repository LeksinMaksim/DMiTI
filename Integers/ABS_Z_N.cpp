#include "Integer.h"
#include <stdio.h>
Integer ABS_Z_N(Integer number){   
    Integer result;
    result = number;
    result.sign = 0;
    return result;
}