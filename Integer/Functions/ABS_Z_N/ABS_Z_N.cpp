#include "ABS_Z_N.h"

NaturalNumbers ABS_Z_N(Integer number){
	NaturalNumbers result;
	result.setDigits(number.getDigits());
	return result;
}
