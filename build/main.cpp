#include "mainUtils.h"

int main(){
	NaturalNumbers firstNumber = NaturalNumbers(3315);
	NaturalNumbers secondNumber = NaturalNumbers(120);
	Integer n1 = Integer(1500);
	Integer n2 = Integer(-100);
	std::cout << DIV_ZZ_Z(n1,n2).getStrReference() << '\n';
	std::cout << LCM_NN_N(secondNumber,firstNumber).getStrReference() << '\n';
	std::cout << SUB_ZZ_Z(n1,n2).getStrReference() << '\n';
	return 0;
}
