#include "DIV_NN_Dk.h"
short DIV_NN_Dk(NaturalNumbers firstNumber, NaturalNumbers secondNumber, int tenDegree){
	secondNumber = MUL_Nk_N(secondNumber, tenDegree);
	if (COM_NN_D(firstNumber, secondNumber) == 1){
		return 0;
	}

	if (COM_NN_D(firstNumber, secondNumber) == 0){
		return 1;
	}
	std::vector<size_t> firstNumberDigits = firstNumber.getDigits();
	NaturalNumbers bufferNumber;
	std::vector<size_t> bufferNumberDigets;
	int i = 0;
	while (COM_NN_D(bufferNumber, secondNumber)==1){
		bufferNumberDigets.push_back(firstNumberDigits[i]);
		bufferNumber.setDigits(bufferNumberDigets);
		i++;
	}
	short result = 0;
	while(COM_NN_D(bufferNumber, secondNumber)!=1){
		bufferNumber = SUB_NN_N(bufferNumber, secondNumber);
		result++;
	}
	return result;
}