#include "NaturalNumbers.h"
#include "COM_NN_D.h"
#include "MUL_ND_N.h"
#include <iostream>
#include <vector>
#include <map>

bool testNaturalNumbersInit(){
	size_t firstNumber = 189214;
	NaturalNumbers firstNaturalNumber = NaturalNumbers(firstNumber);
	std::cout << "First number reference : " << firstNumber << '\n';
	std::cout << "First Natural Number : " << firstNaturalNumber.getStrReference() << '\n';
	std::cout << "Count Digits : " << firstNaturalNumber.getSize() << '\n';
	NaturalNumbers secondNaturalNumber = firstNaturalNumber;
	std::cout << "Second Natural Number : " << secondNaturalNumber.getStrReference() << "\n\n";
  	return (firstNaturalNumber.getSize() == 6 && secondNaturalNumber.getStrReference() == firstNaturalNumber.getStrReference());
}

bool testCompareNaturalNumbers(){
	std::map<size_t, std::string> compareStrReferences = {
		{0, "Equal"},
		{1, "Lower"},
		{2, "Bigger"}	
	};
	size_t fNumber = 682005;
	size_t sNumber = 566;
	NaturalNumbers fNaturalNum = NaturalNumbers(fNumber);
	NaturalNumbers sNaturalNum = NaturalNumbers(sNumber);
	size_t fResult = compareNaturalNaturalNumbers(fNaturalNum, sNaturalNum);
	size_t sResult = compareNaturalNaturalNumbers(fNaturalNum, fNaturalNum);
	size_t tResult = compareNaturalNaturalNumbers(sNaturalNum, fNaturalNum);
	std::cout << "First number : " << fNaturalNum.getStrReference() << '\n';
	std::cout << "Second number : " << sNaturalNum.getStrReference() << '\n';
	std::cout << "Result of compare First number and Second number: " << compareStrReferences[fResult] << '\n';
	std::cout << "Result of compare First number and First number: " << compareStrReferences[sResult] << '\n';	
	std::cout << "Result of compare Second number and First number: " << compareStrReferences[tResult] << "\n\n";
	return (fResult == 2 && sResult == 0 && tResult == 1);
}

bool testMultiplicateNaturalToDigit(){
	NaturalNumbers oneResNumber = multNaturalNumberToDigit(NaturalNumbers(228), 1);
	NaturalNumbers nullResNumber = multNaturalNumberToDigit(NaturalNumbers(1337), 0);
	NaturalNumbers fResNumber = multNaturalNumberToDigit(NaturalNumbers(567), 5);
	NaturalNumbers sResNumber = multNaturalNumberToDigit(NaturalNumbers(68205), 9);
	NaturalNumbers tResNumber = multNaturalNumberToDigit(NaturalNumbers(3333), 3);
	NaturalNumbers ftResNumber = multNaturalNumberToDigit(NaturalNumbers(8763), 6);
	std::cout << "First Number : "<< 228 << " digit is 1 result is :" << oneResNumber.getStrReference() << '\n';
	std::cout << "First Number : "<< 1337 << " digit is 0 result is :" << nullResNumber.getStrReference() << '\n';
	std::cout << "First Number : "<< 567 << " digit is 5 result is :" << fResNumber.getStrReference() << '\n';
	std::cout << "First Number : "<< 68205 << " digit is 9 result is :" << sResNumber.getStrReference() << '\n';
	std::cout << "First Number : "<< 3333 << " digit is 3 result is :" << tResNumber.getStrReference() << '\n';
	std::cout << "First Number : "<< 8763 << " digit is 6 result is :" << ftResNumber.getStrReference() << "\n\n";
	return (oneResNumber.getStrReference() == std::to_string(228*1) 
	&& nullResNumber.getStrReference() == std::to_string(1337 * 0) 
	&& fResNumber.getStrReference() == std::to_string(567*5)
	&& sResNumber.getStrReference() == std::to_string(68205*9)
	&& tResNumber.getStrReference() == std::to_string(3333*3)
	&& ftResNumber.getStrReference() == std::to_string(8763*6));
}


int main(int argc, char* argv[]){
	bool resultInitTest = testNaturalNumbersInit();
	bool resultCompareNaturalNumbers = testCompareNaturalNumbers();
	bool resultMultiplicateNaturalToDigit = testMultiplicateNaturalToDigit();
	std::cout << "Result of test init : " << (resultInitTest == true ? "Passed" : "Failed") << '\n';
	std::cout << "Result of compare natural numbers : " << (resultCompareNaturalNumbers == true ? "Passed" : "Failed") << '\n';
	std::cout << "Result of multiplicate natural to digit : " << (resultMultiplicateNaturalToDigit == true ? "Passed" : "Failed") << '\n';
	return 0;
}
