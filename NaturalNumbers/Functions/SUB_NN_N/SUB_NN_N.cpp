#include "SUB_NN_N.h"

NaturalNumbers SUB_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){ 
    NaturalNumbers result;
    if (COM_NN_D(firstNumber, secondNumber) == 1){
        NaturalNumbers buffer;
        buffer = firstNumber;
        firstNumber = secondNumber;
        secondNumber = buffer;
    }
	int temp = 0;
	int sub = 0;
	std::vector<size_t>  a = firstNumber.getDigits();
	std::vector<size_t> b = secondNumber.getDigits();
	std::vector<size_t> resDigits;
    int diffSizes = firstNumber.getSize()-secondNumber.getSize();

	for (int i = secondNumber.getSize()-1; i>=0; i--){
		temp = a[i+diffSizes] - b[i] + sub;
		if (temp < 0){
			resDigits.insert(resDigits.begin(), temp + 10);
			sub = -1;
		}
		else{
			resDigits.insert(resDigits.begin(), temp);
			sub = 0;
		}
	}
	for (int i = diffSizes-1; i>=0; i--){
		temp = a[i] + sub;
		if (temp < 0) {
			resDigits.insert(resDigits.begin(), temp + 10);
			sub = -1;
		}
		else {
			resDigits.insert(resDigits.begin(), temp);
			sub = 0;
		}
	}
    while (resDigits.size() >1 && resDigits[0] == 0){
        resDigits.erase(resDigits.begin());
    }
    result.setDigits(resDigits);
	return result;
}
