#include "mainUtils.h"

int main(){
	NaturalNumbers firstNumber = NaturalNumbers(3315);
	NaturalNumbers secondNumber = NaturalNumbers(120);
	Integer n1 = Integer(-16);
	Integer n2 = Integer(5);
	Rationals r1 = Rationals({4,8});
	Rationals r2 = Rationals({2,10});
	Polynomials p1 = Polynomials("-12/1x^2+1/1x^3");
	Polynomials p2 = Polynomials("-3/1x^0+1/1x^1");
	std::cout << DIV_ZZ_Z(n1,n2).getStrReference() << '\n';
	std::cout << LCM_NN_N(secondNumber,firstNumber).getStrReference() << '\n';
	std::cout << MOD_ZZ_Z(n1,n2).getStrReference() << '\n';
	std::cout << RED_Q_Q(r2).getStrReference() << '\n';
	std::cout << INT_Q_B(r2) << '\n';
	std::cout << SUB_QQ_Q(r1,r2).getStrReference() << '\n';
	std::cout << DIV_QQ_Q(r1,r2).getStrReference() << '\n';
	std::cout << DIV_PP_P(p1,p2).first.getStrReference() << '\n';
	std::cout << MOD_PP_P(p1,p2).getStrReference() << '\n';
	return 0;
}
