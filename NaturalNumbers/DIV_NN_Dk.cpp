#include "DIV_NN_Dk.h"
short DIV_NN_Dk(NaturalNumbers firstNumber, NaturalNumbers secondNumber, int tenDegree){
    int i = 0;
	secondNumber = MUL_Nk_N(secondNumber, tenDegree);
	if (COM_NN_D(firstNumber, secondNumber) == 1){
		return 0;
	}

	if (COM_NN_D(firstNumber, secondNumber) == 0){
		return 1;
	}
	while (COM_NN_D(firstNumber, secondNumber) != 1){
		firstNumber = SUB_NN_N(firstNumber, secondNumber);
		i++;
	}
	return i;
}
