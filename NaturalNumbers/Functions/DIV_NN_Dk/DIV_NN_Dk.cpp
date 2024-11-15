#include "DIV_NN_Dk.h"

NaturalNumbers DIV_NN_Dk(NaturalNumbers firstNumber, NaturalNumbers secondNumber, size_t tenDegree){
	if (NZER_N_B(secondNumber) == false) return NaturalNumbers(0);
	secondNumber = MUL_Nk_N(secondNumber, tenDegree);
	if (COM_NN_D(firstNumber, secondNumber) == 1){
		return 0;
	}
	if (COM_NN_D(firstNumber, secondNumber) == 0){
		return 1;
	}
	std::vector<size_t> firstNumberDigits = firstNumber.getDigits();
	NaturalNumbers bufferNumber;
	std::vector<size_t> bufferNumberDigits;
	int i = 0;
	while (COM_NN_D(bufferNumber, secondNumber)==1){
		bufferNumberDigits.push_back(firstNumberDigits[i]);
		bufferNumber.setDigits(bufferNumberDigits);
		i++;
	}
	NaturalNumbers result = 0;
	while(COM_NN_D(bufferNumber, secondNumber)!=1){
		bufferNumber = SUB_NN_N(bufferNumber, secondNumber);
		result = ADD_NN_N(result, NaturalNumbers(1));
	}
	return result;
}
