#include "COM_NN_D.h"
#include "SUB_NN_N.h"
#include <iostream>
NaturalNumbers SUB_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){ 
    NaturalNumbers result;
    if (COM_NN_D(firstNumber, secondNumber) == 1){
        NaturalNumbers buffer;
        buffer = firstNumber;
        firstNumber = secondNumber;
        secondNumber = buffer;
    }
	int temp;
	int sub = 0;
	std::vector<size_t>  a = firstNumber.getDigits();
	std::vector<size_t> b = secondNumber.getDigits();
	std::vector<size_t> res_digits;
    int diff_sizes = firstNumber.getSize()-secondNumber.getSize();

	for (int i = secondNumber.getSize()-1; i>=0; i--){
		temp = a[i+diff_sizes] - b[i] + sub;
		if (temp < 0){
			res_digits.insert(res_digits.begin(), temp + 10);
			sub = -1;
		}
		else{
			res_digits.insert(res_digits.begin(), temp);
			sub = 0;
		}
	}
	for (int i = diff_sizes-1; i>=0; i--){
		temp = a[i] + sub;
		if (temp < 0) {
			res_digits.insert(res_digits.begin(), temp + 10);
			sub = -1;
		}
		else {
			res_digits.insert(res_digits.begin(), temp);
			sub = 0;
		}
	}
    while (res_digits.size()>1 && res_digits[0]==0){
        res_digits.erase(res_digits.begin());
    }
    result.setDigits(res_digits);
    result.setSize(res_digits.size());
	return result;
}