#include "COM_NN_D.h"

size_t compareNaturalNaturalNumbers(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
	int resultOfCompare = firstNumber.getSize() - secondNumber.getSize();
	if (resultOfCompare == 0){
		for (size_t i = 0; i < firstNumber.getSize(); i++){
			if (firstNumber.getDigit(i) == secondNumber.getDigit(i)) continue;
			return firstNumber.getDigit(i) > secondNumber.getDigit(i) ? 2 : 1;
		}
		return 0;	
	};
	return resultOfCompare > 0 ? 2 : 1;
}
