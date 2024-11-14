#include "DIV_NN_N.h"

NaturalNumbers DIV_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
	size_t firstNumberSize = firstNumber.getSize();
	size_t secondNumberSize = secondNumber.getSize();
	if (firstNumberSize < secondNumberSize){
		return NaturalNumbers(0);
	}
	if (firstNumberSize == secondNumberSize){
		return DIV_NN_Dk(firstNumber, secondNumber, 0);
	}
	size_t k = firstNumberSize - secondNumberSize - 1;
	NaturalNumbers resultDiv = NaturalNumbers(0);
	while (COM_NN_D(firstNumber, secondNumber) == 2){
		size_t k = firstNumber.getSize() - secondNumberSize - 1;
		NaturalNumbers result_div_nn_dk = DIV_NN_Dk(firstNumber, secondNumber, k);
		NaturalNumbers result_mul_nk_n = MUL_Nk_N(result_div_nn_dk, k);
		resultDiv = ADD_NN_N(resultDiv, result_mul_nk_n);
		firstNumber = SUB_NN_N(firstNumber, MUL_NN_N(secondNumber, MUL_Nk_N(result_div_nn_dk, k)));
	}
	return resultDiv;
}
