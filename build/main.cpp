#include "mainUtils.h"

int main(){
	NaturalNumbers firstNumber = NaturalNumbers(3315);
	NaturalNumbers secondNumber = NaturalNumbers(120);
	Integer n1 = Integer(-16);
	Integer n2 = Integer(5);
	std::cout << DIV_ZZ_Z(n1,n2).getStrReference() << '\n';
	std::cout << LCM_NN_N(secondNumber,firstNumber).getStrReference() << '\n';
	std::cout << MOD_ZZ_Z(n1,n2).getStrReference() << '\n';
	return 0;
}
