#include "MUL_ZM_Z.h"

Integer MUL_ZM_Z(Integer number){
	if (POZ_Z_D(number) == 0) return number;

	number.setSign((POZ_Z_D(number) == 2) ? Negative : Positive);

	return number;
}
