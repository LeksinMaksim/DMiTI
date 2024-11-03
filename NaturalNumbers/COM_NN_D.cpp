#include "COM_NN_D.h"

size_t compareNaturalNaturalNumbers(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
	int resultOfCompare = firstNumber.getSize() - secondNumber.getSize();
	if (resultOfCompare == 0) return 0;
	return resultOfCompare > 0 ? 2 : 1;
}
