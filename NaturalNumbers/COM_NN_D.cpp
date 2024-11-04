#include "COM_NN_D.h"
short COM_NN_D(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
    if (firstNumber.getSize() > secondNumber.getSize())
		return 2;
	else if (secondNumber.getSize() > firstNumber.getSize())
		return 1;
	else{
		for (int index = firstNumber.getSize() - 1; index >= 0; index--){
			if (firstNumber.getDigits()[index] > secondNumber.getDigits()[index]){
                return 2;
            }
			else if (secondNumber.getDigits()[index] > firstNumber.getDigits()[index]){
                return 1;
            }
		}
	}
	return 0;
}