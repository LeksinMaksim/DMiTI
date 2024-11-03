#include "NaturalNumbers.h"
#include "COM_NN_D.cpp"
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
	std::cout << "Second Natural Number : " << secondNaturalNumber.getStrReference() << '\n';
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
	std::cout << "Result of compare Second number and First number: " << compareStrReferences[tResult] << '\n';
	return (fResult == 2 && sResult == 0 && tResult == 1);
}

int main(int argc, char* argv[]){
	bool resultInitTest = testNaturalNumbersInit();
	bool resultCompareNaturalNumbers = testCompareNaturalNumbers();
	std::cout << "Result of compare natural numbers : " << (resultCompareNaturalNumbers == true ? "Passed" : "Failed") << '\n';
	std::cout << "Result of test init : " << (resultInitTest == true ? "Passed" : "Failed") << '\n';
	return 0;
}
